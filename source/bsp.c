#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <filesystem.h>
#include <nds.h>
#include "bsp.h"
#include "polygon.h"
#include "texture.h"

void* loadLump(FILE* file, lump_t lump, int elemSize, int* count) {
    void* buffer = malloc(lump.length);
    fseek(file, lump.offset, SEEK_SET);
    fread(buffer, 1, lump.length, file);
    *count = lump.length / elemSize;
    return buffer;
}

/// Lump ID 0이 plane
static dplane_t* bsp_planes;
static int bsp_numPlanes;

void bsp_LoadPlanes(FILE* file, lump_t lump) {
    bsp_numPlanes = lump.length / sizeof(dplane_t);
    bsp_planes = malloc(lump.length);
    fseek(file, lump.offset, SEEK_SET);
    fread(bsp_planes, lump.length, 1, file);
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
          dplane_t* plane = &bsp_planes[node->planeIndex];

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

extern int textureGLIDs[MAX_TEXTURES];

void drawTexturedFace(const dmap_t *map, const dface_t* face) {
    texinfo_t* texinfo = &map->texinfos[face->texInfo];
    miptex_t* texture = &map->textures[texinfo->miptex];

    glBindTexture(0, textureGLIDs[texinfo->miptex]);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < face->numEdges; ++i) {
        dvertex_t* v0 = bsp_GetVertexFromFace(map, face, 0);
        dvertex_t* v1 = bsp_GetVertexFromFace(map, face, i);
        dvertex_t* v2 = bsp_GetVertexFromFace(map, face, i + 1);

        float u0, v0_, u1, v1_, u2, v2_;
        computeUV(&map->texinfos[face->texInfo], v0, &u0, &v0_, texture->width, texture->height);
        computeUV(&map->texinfos[face->texInfo], v1, &u1, &v1_, texture->width, texture->height);
        computeUV(&map->texinfos[face->texInfo], v2, &u2, &v2_, texture->width, texture->height);

        glTexCoord2f(u0, v0_); glVertex3f(v0->x, v0->z, -v0->y); // Quake는 Y축이 위로, Z축이 앞으로
        glTexCoord2f(u1, v1_); glVertex3f(v1->x, v1->z, -v1->y); // NDS는 Y축이 앞으로, Z축이 위로
        glTexCoord2f(u2, v2_); glVertex3f(v2->x, v2->z, -v2->y);
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

    bsp_LoadPlanes(file, header.lumps[0]);
    map->models = loadLump(file, header.lumps[7], sizeof(dmodel_t), &map->numModels);
    map->vertices = loadLump(file, header.lumps[3], sizeof(dvertex_t), &map->numVertices);
    map->nodes = loadLump(file, header.lumps[5], sizeof(dnode_t), &map->numNodes);
    map->leafs = loadLump(file, header.lumps[10], sizeof(dleaf_t), &map->numLeafs);
    map->faces = loadLump(file, header.lumps[13], sizeof(dface_t), &map->numFaces);
    map->texinfos = loadLump(file, header.lumps[6], sizeof(texinfo_t), &map->numTexInfos);
    map->edges = loadLump(file, header.lumps[12], sizeof(dedge_t), &map->numEdges);
    map->surfEdges = loadLump(file, header.lumps[11], sizeof(int32_t), &map->numSurfEdges);
    map->markSurfaces = loadLump(file, header.lumps[14], sizeof(int32_t), &map->numMarkSurfaces);

    fclose(file);
    return 1;
}

void freeBSP(dmap_t* map) {
    if (!map) return;
    free(map->markSurfaces);
    free(map->surfEdges);
    free(map->edges);
    free(map->texinfos);
    free(map->faces);
    free(map->leafs);
    free(map->nodes);
    free(map->vertices);
    free(map->models);
    
    memset(map, 0, sizeof(dmap_t));
}
