#pragma once
#include <struct.h>
void initTexture();
void loadTexture(const char* name, const u8* data, int texSizeX, int texSizeY);
void bindFaceTexture(const dmap_t* map, const dface_t* face);