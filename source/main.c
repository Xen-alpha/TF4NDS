#include <stdio.h>

#include <nds.h>
#include <fat.h>
#include <filesystem.h>

void quake_main (int argc, char **argv);

int main(int argc, char **argv)
{
    // Camera * cam = (Camera *) malloc(sizeof(Camera));
    // Enable 3D
    videoSetMode(MODE_0_3D);
    
    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    setBrightness(2, 0);

    // set main 3d engine: 3D mode, 256x192, 16bpp, Total 512KB
    //init3D();
    //loadCamera();

    // 3D Texture: total 512KB
    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);
    vramSetBankC(VRAM_C_TEXTURE);
    vramSetBankD(VRAM_D_TEXTURE);
    // TODO: 이게 필요할지 안 필요할지 모르겠다. 텍스처가 16bit 그래픽이면 아래 뱅크는 다른 데로 돌리자.
    vramSetBankF(VRAM_F_TEX_PALETTE); // 16KB, Texture palette slot 0
    vramSetBankG(VRAM_G_TEX_PALETTE_SLOT1); // 16KB, Texture palette slot 1

    // set main 2d engine: BG2 only, 256x256, 8bpp, Total 64KB
    vramSetBankE(VRAM_E_MAIN_BG); // 상단 BG
    vramSetBankH(VRAM_H_SUB_BG);      // 하단 BG
    vramSetBankI(VRAM_I_LCD);     // 버퍼 용도로 바꿔 CPU 및 디스플레이 엔진의 렌더링 접근을 막는다.

    
    // Bank H에 할당된 VRAM을 하단 스크린에 할당
    videoSetModeSub(MODE_0_2D);

    REG_BG0CNT_SUB = BG_MAP_BASE(2) | BG_TILE_BASE(0) | BG_PRIORITY(0);

    consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 2, 0, false, true);

    // Initialize NitroFS
    bool init_ok = nitroFSInit(NULL);
    if (!init_ok)
    {
        // Handle error
        printf("Failed to initialize NitroFS\n");
        while (1)
          swiWaitForVBlank();
    }
    
    // Setup done
    printf("Device Initialized\n");
    // ==========

    // Main game loop
    quake_main(argc, argv);

    return 0;

}