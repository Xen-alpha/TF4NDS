#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <filesystem.h>
#include <nds.h>
#include "bsp.h"
#include "polygon.h"

FILE* bspFile;

static void* read_lump(FILE* f, lump_t lump, int entrySize, int* countOut) {
    int count = lump.filelen / entrySize;
    void* buffer = malloc(lump.filelen);
    if (!buffer) return NULL;
    fseek(f, lump.fileofs, SEEK_SET);
    fread(buffer, lump.filelen, 1, f);
    if (countOut) *countOut = count;
    return buffer;
}

bool load_bsp_map(const char* filename, dmap_t* outMap) {
    memset(outMap, 0, sizeof(dmap_t));

    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Failed to open BSP\n");
        return false;
    }

    dheader_t header;
    fread(&header, sizeof(header), 1, f);
    
    if (header.version != BSP_VERSION) { // 
        printf("Invalid BSP version\n");
        fclose(f);
        return false;
    }

    outMap->vertices = read_lump(f, header.lumps[2], sizeof(dvertex_t), &outMap->numVertices);
    outMap->edges = read_lump(f, header.lumps[10], sizeof(dedge_t), &outMap->numEdges);
    outMap->surfedges = read_lump(f, header.lumps[11], sizeof(int), &outMap->numSurfEdges);
    outMap->faces = read_lump(f, header.lumps[5], sizeof(dface_t), &outMap->numFaces);
    outMap->texinfos = read_lump(f, header.lumps[4], sizeof(texinfo_t), &outMap->numTexInfos);

    fclose(f);
    return true;
}

void free_bsp_map(dmap_t* map) {
    free(map->vertices);
    free(map->edges);
    free(map->surfedges);
    free(map->faces);
    free(map->texinfos);
    memset(map, 0, sizeof(dmap_t));
}
