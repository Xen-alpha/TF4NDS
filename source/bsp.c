#include <stdio.h>
#include <filesystem.h>
#include <nds.h>
#include "bsp.h"
#include "polygon.h"

FILE* bspFile;

int loadBSP(const char* path) {
    bspFile = fopen(path, "rb");
    if (!bspFile) return 0;

    BSPHeader header;
    fread(&header, sizeof(BSPHeader), 1, bspFile);

    if (strncmp(header.magic, "IBSP", 4) != 0 || header.version != 29) {
        fclose(bspFile);
        return 0;
    }

    // 예: Vertex Lump 로드
    fseek(bspFile, header.lumps[3].offset, SEEK_SET); // LUMP_VERTICES
    int numVertices = header.lumps[3].length / sizeof(Vertex);
    Vertex* verts = malloc(sizeof(Vertex) * numVertices);
    fread(verts, sizeof(Vertex), numVertices, bspFile);

    // 계속 face, texture 등 파싱 가능
    return 1;
}