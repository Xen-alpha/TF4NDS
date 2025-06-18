#pragma once
#include <struct.h>
#define MAX_TEX_DATA 512

void initTexture();
int loadTexture(int texId, const char* name, int texSizeX, int texSizeY);
int getTextureId(const char * name);
int deleteTextureId(const char * name);
void clearAllMapTextures();