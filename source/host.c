#include <nds.h>
#include <stdio.h>
#include <host.h>
#include <camera.h>

#include "BACKTILE.h"

int textureID;
extern Camera* camera;
void loadCamera() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 256.0 / 192.0, 0.1, 100.0);
  gluLookAt(0.0, 0.0, 2.0,  // Position
            0.0, 0.0, 0.0,  // Look at
            0.0, 1.0, 0.0); // Up    
}

void init3D() {
    glInit();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ANTIALIAS);

    glClearColor(0, 0, 0, 31);
    glClearPolyID(63);
    glClearDepth(0x7FFF);

    glViewport(0, 0, 255, 191);
    // 3D Texture: total 512KB
    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);
    vramSetBankC(VRAM_C_TEXTURE);
    vramSetBankD(VRAM_D_TEXTURE);
    // TODO: 이게 필요할지 안 필요할지 모르겠다. 텍스처가 16bit 그래픽이면 아래 뱅크는 다른 데로 돌리자.
    vramSetBankF(VRAM_F_TEX_PALETTE); // 16KB, Texture palette slot 0
    vramSetBankG(VRAM_G_TEX_PALETTE_SLOT1); // 16KB, Texture palette slot 1

    // Load texture
    /*
    glGenTextures(1, &textureID);
    glBindTexture(0, textureID);

    if (glTexImage2D(0, 0, GL_RGBA, 64, 64, 0, TEXGEN_TEXCOORD, BACKTILEBitmap) == 0)
    {
        printf("Failed to load texture\n");
        while (1)
            swiWaitForVBlank();
    }
    */
    // loadCamera();
    initCamera(camera);
    cameraUpdateView(camera);
}


/*
void drawFrame(int angle_x, int angle_z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotateZ(angle_z);
    glRotateX(angle_x);

    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

    glBindTexture(0, textureID);

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);

      GFX_TEX_COORD = (TEXTURE_PACK(0, inttot16(64)));
      glVertex3v16(floattov16(-1), floattov16(-1), 0);

      GFX_TEX_COORD = (TEXTURE_PACK(inttot16(64),inttot16(64)));
      glVertex3v16(floattov16(1), floattov16(-1), 0);

      GFX_TEX_COORD = (TEXTURE_PACK(inttot16(64), 0));
      glVertex3v16(floattov16(1), floattov16(1), 0);

      GFX_TEX_COORD = (TEXTURE_PACK(0,0));
      glVertex3v16(floattov16(-1), floattov16(1), 0);

    glEnd();
    glPopMatrix(1);

    glFlush(0);
}
*/
void loadUI () {
  // Print some text in the demo console
  // -----------------------------------

  consoleClear();

  // Print some controls
  printf("PAD: View map\n");
  printf("START:   Exit to loader\n");
  printf("\n");
}