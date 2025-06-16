#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <filesystem.h>
#include <nds.h>
#include <bsp.h>
#include <polygon.h>
#include <texture.h>

extern u16 *paletteData[MAX_TEX_DATA];

void* loadLump(FILE* file, lump_t lump, int elemSize, int* count) {
    void* buffer = malloc(lump.length);
    fseek(file, lump.offset, SEEK_SET);
    fread(buffer, 1, lump.length, file);
    *count = lump.length / elemSize;
    return buffer;
}

miptex_t ** readTextureContents(const unsigned char * texture_data, int *sectionSize) {
  miptexheader_t *miptex_header = (miptexheader_t *) texture_data;
  miptex_t **result = (miptex_t **) malloc(sizeof(miptex_t *) * miptex_header->numtextures);
  if (!result) {
    printf("Out of memory for texture!\n");
    return NULL;
  }
  *sectionSize = miptex_header->numtextures;
  for (int i = 0 ; i < miptex_header->numtextures; i++) {
    result[i] = (miptex_t *)(&texture_data[miptex_header->dataofs[i]]);
  }
  return result;
}

/// 내부: 평면과 점의 거리
float pointOnPlaneSide(const float* point, const dplane_t* plane) {
    return point[0] * plane->normal[0] +
           point[1] * plane->normal[1] +
           point[2] * plane->normal[2] - plane->dist;
}

/// 카메라 위치가 포함된 leaf 찾기
dleaf_t* bsp_FindLeaf(const dmap_t *map, float x, float y, float z) {
  for (int i = 0; i < map->numModels; ++i) {
    dmodel_t model = map->models[i];
    for (int j = 0 ; j < MAX_MAP_HULLS; ++j) {
        if (model.headNode[j] < 0) continue; // 유효한 헤드 노드가 아니면 건너뛴다
        int nodeIndex = model.headNode[j];
        if (nodeIndex < 0 || nodeIndex >= map->numNodes) {
            return NULL; // 유효하지 않은 노드 인덱스
        }
        while (nodeIndex >= 0) {
          dnode_t* node = &map->nodes[nodeIndex];
          dplane_t* plane = &map->planes[node->planeIndex];

          float side = pointOnPlaneSide((float[]){x, y, z}, plane);

          int childIndex = (side >= 0) ? node->children[0] : node->children[1];

          if (childIndex < 0) {
              int leafIndex = -1 - childIndex;
              if (leafIndex < map->numLeafs) {
                  return &map->leafs[leafIndex];
              } else {
                  return NULL;
              }
          }

          nodeIndex = childIndex;
      }
    }
    
  }
  return NULL;
}

lightmap_info_t calcLightmapInfo (const dmap_t *map, const dface_t* face) {
    texinfo_t* texinfo = &map->texinfos[face->texInfo];
    float umin = 1e9, umax = -1e9;
    float vmin = 1e9, vmax = -1e9;

    for (int i = 0; i < face->numEdges; i++) {
        int edgeIndex = map->surfEdges[face->firstEdge + i];
        dedge_t edge = map->edges[abs(edgeIndex)];
        dvertex_t vertex = (edgeIndex >= 0) ? map->vertices[edge.v[0]] : map->vertices[edge.v[1]];

        // world 좌표 → 텍스처 좌표 변환
        float x = vertex.x, y = vertex.y, z = vertex.z;

        float u = texinfo->vecs[0][0]*x + texinfo->vecs[0][1]*y + texinfo->vecs[0][2]*z + texinfo->vecs[0][3];
        float v = texinfo->vecs[1][0]*x + texinfo->vecs[1][1]*y + texinfo->vecs[1][2]*z + texinfo->vecs[1][3];

        if (u < umin) umin = u;
        if (u > umax) umax = u;
        if (v < vmin) vmin = v;
        if (v > vmax) vmax = v;
    }

    // lightmap은 16 단위 그리드 기준으로 정렬됨 (Quake 규칙)
    lightmap_info_t info;
    info.minU = umin;
    info.minV = vmin;
    info.w = ((int)(umax - umin) / 16) + 1;
    info.h = ((int)(vmax - vmin) / 16) + 1;
    return info;

}

void getLightmapUV(const dvertex_t* vtx, const texinfo_t* tex, const lightmap_info_t* lmInfo, float* outU, float* outV) {
    float u = tex->vecs[0][0]*vtx->x + tex->vecs[0][1]*vtx->y + tex->vecs[0][2]*vtx->z + tex->vecs[0][3];
    float v = tex->vecs[1][0]*vtx->x + tex->vecs[1][1]*vtx->y + tex->vecs[1][2]*vtx->z + tex->vecs[1][3];

    // Offset to lightmap space
    *outU = (u - lmInfo->minU) / (float)lmInfo->w;
    *outV = (v - lmInfo->minV) / (float)lmInfo->h;
}

// 빛 강도 추출 (lightmap의 값이 있다고 가정)
int getLightLevelAt(float u, float v, const lightmap_info_t* lmInfo, const uint8_t* lightmapData) {
    int x = (int)(u * lmInfo->w);
    int y = (int)(v * lmInfo->h);

    // 경계 체크
    if (x < 0 || x >= lmInfo->w || y < 0 || y >= lmInfo->h) return 255;

    return lightmapData[y * lmInfo->w + x];
}



void computeUV(const texinfo_t* texinfo, const dvertex_t* v, float* outU, float* outV, float width, float height) {
    float u = texinfo->vecs[0][0] * v->x +
              texinfo->vecs[0][1] * v->y +
              texinfo->vecs[0][2] * v->z +
              texinfo->vecs[0][3];

    float v_ = texinfo->vecs[1][0] * v->x +
               texinfo->vecs[1][1] * v->y +
               texinfo->vecs[1][2] * v->z +
               texinfo->vecs[1][3];

    // 정규화
    *outU = u / width;
    *outV = v_ / height;
}

dvertex_t* bsp_GetVertexFromFace(const dmap_t *map, const dface_t* face, int localIndex) {
    int edgeIndex = map->surfEdges[face->firstEdge + localIndex];
    int reversed = 0;
    if (edgeIndex < 0) {
        edgeIndex = -edgeIndex;
        reversed = 1;
    }

    dedge_t* edge = &map->edges[edgeIndex];
    int vi = reversed ? edge->v[1] : edge->v[0];
    return &map->vertices[vi];
}

void drawTexturedFace(const dmap_t *map, const dface_t* face) {
    texinfo_t* texinfo = &map->texinfos[face->texInfo];
    miptex_t* texture = map->textures[texinfo->miptex];
    int textureID = getTextureId(texture->name);
    if (textureID < 0) {
        // printf("Texture not found: %s\n", texture->name);
        return;
    }
    glBindTexture(0, textureID);
    glColorTableEXT(0, 0, 256, 0, 0, paletteData[textureID]);
    lightmap_info_t lmInfo = calcLightmapInfo(map, face);

    glBegin(GL_TRIANGLE);
    for (int i = 0; i < face->numEdges; ++i) {
        dvertex_t* v0 = bsp_GetVertexFromFace(map, face, 0);
        dvertex_t* v1 = bsp_GetVertexFromFace(map, face, i);
        dvertex_t* v2 = bsp_GetVertexFromFace(map, face, i + 1);

        float u0, v0_, u1, v1_, u2, v2_;
        computeUV(&map->texinfos[face->texInfo], v0, &u0, &v0_, texture->width, texture->height);
        computeUV(&map->texinfos[face->texInfo], v1, &u1, &v1_, texture->width, texture->height);
        computeUV(&map->texinfos[face->texInfo], v2, &u2, &v2_, texture->width, texture->height);
        
        glTexCoord2f(u0, v0_); glVertex3f(v0->x, v0->y, v0->z); // Quake는 Y축이 위로, Z축이 앞으로
        glTexCoord2f(u1, v1_); glVertex3f(v1->x, v1->y, v1->z); // NDS는 Y축이 앞으로, Z축이 위로
        glTexCoord2f(u2, v2_); glVertex3f(v2->x, v2->y, v2->z);
        
        
        // 빛맵 UV 계산
        getLightmapUV(v0, texinfo, &lmInfo, &u0, &v0_);
        int light0 = getLightLevelAt(u0, v0_, &lmInfo, &map->lightData[face->lightofs]);
        getLightmapUV(v1, texinfo, &lmInfo, &u1, &v1_);
        int light1 = getLightLevelAt(u1, v1_, &lmInfo, &map->lightData[face->lightofs]);
        getLightmapUV(v2, texinfo, &lmInfo, &u2, &v2_);
        int light2 = getLightLevelAt(u2, v2_, &lmInfo, &map->lightData[face->lightofs]);

        int brightness = light0 >> 1; // 0~255
        glColor3b(brightness, brightness, brightness);
        glTexCoord2f(u0, v0_); glVertex3f(v0->x, v0->y, v0->z); // Quake는 Y축이 위로, Z축이 앞으로
        brightness = light1 >> 1;
        glColor3b(brightness, brightness, brightness);
        glTexCoord2f(u1, v1_); glVertex3f(v1->x, v1->y, v1->z); // NDS는 Y축이 앞으로, Z축이 위로
        brightness = light2 >> 1;
        glColor3b(brightness, brightness, brightness);
        glTexCoord2f(u2, v2_); glVertex3f(v2->x, v2->y, v2->z);
        
    }
    glEnd();
}

void renderVisibleFaces(const dmap_t *map, float camX, float camY, float camZ) {
    dleaf_t* leaf = bsp_FindLeaf(map, camX, camY, camZ);
    if (!leaf) return;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    for (int i = 0; i < leaf->numMarkSurfaces; ++i) {
        int faceIndex = map->markSurfaces[leaf->firstMarkSurface + i];
        if (faceIndex < 0 || faceIndex >= map->numFaces) continue;

        dface_t* face = &map->faces[faceIndex];
        drawTexturedFace(map, face);
    }
}

int loadBSP(dmap_t* map, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return 0;
    
    dheader_t header;
    fread(&header, sizeof(header), 1, file);

    if (header.version != 29) { // Note: 지금 헤더 IBSP가 안 읽힌다.
        fclose(file);
        printf("Invalid BSP file: %s\n", filename);
        return 0;
    }

    // TODO: Entity load, VISIBILITY load, clipnode load
    map->planes = loadLump(file, header.lumps[LUMP_PLANES], sizeof(dplane_t), &map->numPlanes);
    printf("BSP: plane loaded\n");
    map->models = loadLump(file, header.lumps[LUMP_MODELS], sizeof(dmodel_t), &map->numModels);
    printf("BSP: models loaded\n");
    map->vertices = loadLump(file, header.lumps[LUMP_VERTEXES], sizeof(dvertex_t), &map->numVertices);
    printf("BSP: vertices loaded\n");
    map->nodes = loadLump(file, header.lumps[LUMP_NODES], sizeof(dnode_t), &map->numNodes);
    printf("BSP: nodes loaded\n");
    map->leafs = loadLump(file, header.lumps[LUMP_LEAFS], sizeof(dleaf_t), &map->numLeafs);
    printf("BSP: leaves loaded\n");
    map->faces = loadLump(file, header.lumps[LUMP_FACES], sizeof(dface_t), &map->numFaces);
    printf("BSP: faces loaded\n");
    map->texinfos = loadLump(file, header.lumps[LUMP_TEXINFO], sizeof(texinfo_t), &map->numTexInfos);
    printf("BSP: texture info loaded\n");
    map->textureData = loadLump(file, header.lumps[LUMP_TEXTURES], sizeof(unsigned char), &map->texDataLength);
    map->textures = readTextureContents(map->textureData, &map->numTextures);
    map->edges = loadLump(file, header.lumps[LUMP_EDGES], sizeof(dedge_t), &map->numEdges);
    printf("BSP: edges loaded\n");
    map->surfEdges = loadLump(file, header.lumps[LUMP_SURFEDGES], sizeof(long), &map->numSurfEdges);
    printf("BSP: surfEdges loaded\n");
    map->markSurfaces = loadLump(file, header.lumps[LUMP_MARKSURFACES], sizeof(long), &map->numMarkSurfaces);
    printf("BSP: markSurfaces loaded\n");
    map->lightData = loadLump(file, header.lumps[LUMP_LIGHTING], sizeof(char), &map->lightDataSize);
    printf("BSP: Light loaded\n");

    fclose(file);
    return 1;
}

void freeBSP(dmap_t* map) {
    if (!map) return;
    free(map->lightData);
    free(map->markSurfaces);
    free(map->surfEdges);
    free(map->edges);
    free(map->texinfos);
    free(map->faces);
    free(map->leafs);
    free(map->nodes);
    free(map->vertices);
    free(map->models);
    free(map->planes);
    
    memset(map, 0, sizeof(dmap_t));
}
