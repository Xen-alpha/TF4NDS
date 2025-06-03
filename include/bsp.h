// #define BSP_HEADER_ID "IBSP"
#define BSP_VERSION 29
#include "struct.h"

bool load_bsp_map(const char* filename, dmap_t* outMap);
void free_bsp_map(dmap_t* map);
