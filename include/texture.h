#pragma once
#include <struct.h>
#define MAX_TEX_DATA 512

void initTexture();
void loadTexture(int texId, const char* name, const u8* data, int texSizeX, int texSizeY, 
                 const u16* palette);
int getTextureId(const char * name);