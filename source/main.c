#include <stdio.h>

#include <nds.h>
#include <fat.h>
#include <filesystem.h>
#include <host.h>
#include <bsp.h>
#include <camera.h>

dmap_t map;
Camera* camera;

int main(int argc, char **argv)
{

    camera = (Camera*)malloc(sizeof(Camera));
    // Enable 3D
    videoSetMode(MODE_0_3D);
    
    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    setBrightness(2, 0);

    // set main 2d engine: BG2 only, 256x256, 8bpp, Total 64KB
    vramSetBankE(VRAM_E_MAIN_BG); // 상단 BG
    vramSetBankH(VRAM_H_SUB_BG);      // 하단 BG
    vramSetBankI(VRAM_I_LCD);     // 버퍼 용도로 바꿔 CPU 및 디스플레이 엔진의 렌더링 접근을 막는다.

    // set main 3d engine: 3D mode, 256x192, 16bpp, Total 512KB
    init3D();

    
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
    // Load BSP map
    if (!load_bsp_map("introseq.bsp", &map)) {
        printf("Failed to load BSP\n");
        while (1)
          swiWaitForVBlank();
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ==========

    int angle_x = 0;
    int angle_z = 0;

    while (1)
    {
        // set UI on the bottom screen
        loadUI();
        printf("Loaded BSP\nVertices: %d\nFaces: %d\n", map.numVertices, map.numFaces);

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
        // Update camera
        cameraMove(camera, (keys & KEY_UP) ? 0.1f : 0, (keys & KEY_LEFT) ? -0.1f : (keys & KEY_RIGHT) ? 0.1f : 0);
        cameraTurn(camera, (keys & KEY_LEFT) ? -0.05f : (keys & KEY_RIGHT) ? 0.05f : 0, (keys & KEY_UP) ? -0.05f : (keys & KEY_DOWN) ? 0.05f : 0);

        // Draw the BSP map
        glClearColor(0, 0, 0, 31);
        glClearDepth(GL_MAX_DEPTH);
        draw_bsp_faces(&map);
        glFlush(0);

        // Synchronize game loop to the screen refresh
        swiWaitForVBlank();
    }
    // Exit the 3D engine

    free_bsp_map(&map);
    free(camera);

    return 0;

}