#pragma once
#include <struct.h>

void initTexture();
void load2DTexture(int texId, const char* name, const u8* data, int texSizeX, int texSizeY, 
                 const u16* palette);
int get2DTextureId(char * name);