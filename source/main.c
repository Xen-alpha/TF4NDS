#include <stdio.h>

#include <nds.h>
#include <host.h>


int main(int argc, char **argv)
{
    // Enable 3D
    videoSetMode(MODE_0_3D);

    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    consoleDemoInit();

    init3D();

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