#include <nds.h>
#include <stdio.h>
#include <host.h>
#include <camera.h>


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
    
}


void loadUI () {
  // Print some text in the demo console
  // -----------------------------------

  consoleClear();

  // Print some controls
  printf("PAD: View map\n");
  printf("START:   Exit to loader\n");
  printf("\n");
}