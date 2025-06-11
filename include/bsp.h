// #define BSP_HEADER_ID "IBSP"
#pragma once
#define BSP_VERSION 29
#include "struct.h"

// BSP 파일 관련
int loadBSP(dmap_t* map, const char* filename);
void freeBSP(dmap_t* map);

// BSP 관련 함수

dleaf_t* bsp_FindLeaf(const dmap_t *map, float x, float y, float z);

// 렌더링 관련 함수
void renderVisibleFaces(const dmap_t *map, float camX, float camY, float camZ);