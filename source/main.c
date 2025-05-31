#include <stdio.h>

#include <nds.h>
#include <fat.h>
#include <filesystem.h>
#include <host.h>


int main(int argc, char **argv)
{
    // Enable 3D
    videoSetMode(MODE_0_3D);
    
    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    // consoleDemoInit();

    // Initialize NitroFS
    /*
    bool init_ok = nitroFSInit(NULL);
    if (!init_ok)
    {
        // Handle error
        printf("Failed to initialize NitroFS\n");
        while (1)
          swiWaitForVBlank();
    }
    */

    // set main 3d engine: 3D mode, 256x192, 16bpp, Total 512KB
    init3D();

    // set main 2d engine: BG2 only, 256x256, 8bpp, Total 64KB
    vramSetBankE(VRAM_E_MAIN_BG); // 상단 BG
    vramSetBankG(VRAM_G_LCD);  // 버퍼 용도로 바꿔 CPU 및 디스플레이 엔진의 렌더링 접근을 막는다.
    vramSetBankH(VRAM_H_SUB_BG);      // 하단 BG
    vramSetBankI(VRAM_I_SUB_SPRITE);    // 하단 디스플레이용 스프라이트

    // Setup done
    // ==========

    int angle_x = 0;
    int angle_z = 0;

    while (1)
    {
        // set UI on the bottom screen
        loadUI();

        // Handle user input
        // -----------------

        scanKeys();

        uint16_t keys = keysHeld();

        if (keys & KEY_LEFT)
            angle_z += 3;
        if (keys & KEY_RIGHT)
            angle_z -= 3;

        if (keys & KEY_UP)
            angle_x += 3;
        if (keys & KEY_DOWN)
            angle_x -= 3;

        if (keys & KEY_START)
            break;
        
        drawFrame(angle_x, angle_z);

        // Synchronize game loop to the screen refresh
        swiWaitForVBlank();
    }
    // Exit the 3D engine

    return 0;

}