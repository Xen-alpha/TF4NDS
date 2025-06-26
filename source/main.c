#include <nds.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fat.h>
#include <filesystem.h>
#include <dswifi9.h>

void quake_main (int argc, char **argv);
void getWifiConnection();

static Wifi_AccessPoint AccessPoint;

int main(int argc, char **argv)
{
    // Camera * cam = (Camera *) malloc(sizeof(Camera));
    // Enable 3D
    videoSetMode(MODE_FB0);
    
    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    // 

    // 3D Texture: total 256KB
    vramSetBankA(VRAM_A_LCD);
    //setBrightness(2, 0);
    //vramSetBankB(VRAM_B_TEXTURE);
    // MODE_FB3 Test: 128KB
    //vramSetBankC(VRAM_C_LCD);
    // MODE_FB3 Test: 128KB
    //vramSetBankD(VRAM_D_LCD);
    // TODO: 이게 필요할지 안 필요할지 모르겠다. 텍스처가 16bit 그래픽이면 아래 뱅크는 다른 데로 돌리자.
    //vramSetBankF(VRAM_F_TEX_PALETTE); // 16KB, Texture palette slot 0
    //vramSetBankG(VRAM_G_TEX_PALETTE_SLOT1); // 16KB, Texture palette slot 1

    // set main 2d engine: BG2 only, 256x256, 8bpp, Total 64KB
    //vramSetBankE(VRAM_E_LCD); // 상단 BG
    //vramSetBankH(VRAM_H_SUB_BG);      // 하단 BG
    //vramSetBankI(VRAM_I_LCD);     // 버퍼 용도로 바꿔 CPU 및 디스플레이 엔진의 렌더링 접근을 막는다.
    
    // Bank H에 할당된 VRAM을 하단 스크린에 할당
    // videoSetModeSub(MODE_0_2D);
    
    // REG_BG0CNT_SUB = BG_MAP_BASE(2) | BG_TILE_BASE(0) | BG_PRIORITY(0);

    consoleDemoInit();

    if (Wifi_InitDefault(INIT_ONLY))
    {
        printf("Wifi initialized successfully\n");
    }
    else
    {
        printf("Failed to initialize Wifi\n");
        while (1)
          swiWaitForVBlank();
    }

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
    getWifiConnection("DESKTOP-P8D41A5");

    // Main game loop
    quake_main(argc, argv);

    if (Wifi_DisconnectAP() != 0)
      printf("Error: Wifi_DisconnectAP()\n");
    return 0;

}


void access_point_selection_menu(void)
{
    // Set the library in scan mode
    Wifi_ScanMode();

    int chosen = 0;

    while (1)
    {
        swiWaitForVBlank();

        scanKeys();
        uint16_t keys = keysDown();

        // Get find out how many APs there are in the area
        int count = Wifi_GetNumAP();

        consoleClear();

        printf("Number of AP: %d\n", count);
        printf("\n");

        if (count == 0)
            continue;

        if (keys & KEY_UP)
            chosen--;

        if (keys & KEY_DOWN)
            chosen++;

        if (chosen < 0)
            chosen = 0;
        if (chosen >= count)
            chosen = count - 1;

        int first = chosen - 5;
        if (first < 0)
            first = 0;

        int last = first + 6;
        if (last >= count)
            last = count - 1;

        for (int i = first; i <= last; i++)
        {
            Wifi_AccessPoint ap;
            Wifi_GetAPData(i, &ap);

            const char *security = "Open";
            if (ap.flags & WFLAG_APDATA_WPA)
                security = "WPA ";
            else if (ap.flags & WFLAG_APDATA_WEP)
                security = "WEP ";

            printf("%s [%.24s] %s\n", i == chosen ? "->" : "  ", ap.ssid,
                ap.flags & WFLAG_APDATA_ADHOC ? "*" : "");
            printf("   %s | Ch %2d | RSSI %u\n", security, ap.channel, ap.rssi);
            printf("\n");

            if (i == chosen)
                Wifi_GetAPData(chosen, &AccessPoint);
        }

        if (keys & KEY_A)
        {
            // WPA isn't supported
            if (!(AccessPoint.flags & WFLAG_APDATA_WPA))
                break;
        }
    }
}

void connect_to_firmware_access_points(void)
{
    printf("Connecting to firmware APs...\n");

    // Autoconnect to firmware access points
    Wifi_AutoConnect();

    // IP settings have been loaded from flash
}

#define URL "DESKTOP-P8D41A5"

void connect_to_other_access_points(void)
{
    // Search for all available access points
    access_point_selection_menu();

    // Setting everything to 0 will make DHCP determine the IP address
    Wifi_SetIP(0, 0, 0, 0, 0);

    // If the access point requires a password, ask the user to provide it
    if (AccessPoint.flags & WFLAG_APDATA_WEP)
    {
        consoleClear();

        char password[100];
        int wepmode = WEPMODE_NONE;

        printf("Please, enter the password:\n");

        while (1)
        {
            password[0] = '\0';
            scanf("%s", password);

            size_t len = strlen(password);
            if (password[len - 1] == '\n')
                password[len - 1] = '\0';

            if (len == 13)
                wepmode = WEPMODE_128BIT;
            else if (len == 5)
                wepmode = WEPMODE_40BIT;
            else
                printf("Invalid key length! [%s] %zu\n", password, len);

            if (wepmode != WEPMODE_NONE)
                break;
        }

        Wifi_ConnectAP(&AccessPoint, wepmode, 0, (u8 *)password);
    }
    else
    {
        Wifi_ConnectAP(&AccessPoint, WEPMODE_NONE, 0, 0);
    }

    printf("Selected network:\n");
    printf("\n");
    printf("%.31s\n", AccessPoint.ssid);
    printf("Key: %s | Ch: %d\n",
           AccessPoint.flags & WFLAG_APDATA_WEP ? "WEP" : "No",
           AccessPoint.channel);
    printf("\n");
  
}

void getWifiConnection() {
    const char *url = URL;
    int quit = 0;
    while (!quit)
    {
        int gotoReturn = 0;
        Wifi_EnableWifi();
        consoleClear();
        printf("WiFi connection options:\n");
        printf("\n");
        printf("A: Connect to firmware AP\n");
        printf("B: Search for APs\n");
        printf("\n");
        printf("\n");

        int num_wfc_caps = Wifi_GetData(WIFIGETDATA_NUMWFCAPS, 0, NULL);

        printf("APs configured in firmware: %d\n", num_wfc_caps);
        if (num_wfc_caps <= 0)
            printf("No APs setup: Option A will fail\n");

        int selection = 0;

        while (selection == 0)
        {
            swiWaitForVBlank();
            scanKeys();
            if (keysDown() & KEY_A)
                selection = 1;
            if (keysDown() & KEY_B)
                selection = 2;
        }

        consoleClear();

        if (selection == 1)
        {

            connect_to_firmware_access_points();
        }
        else if (selection == 2)
        {

            connect_to_other_access_points();
        }

        consoleClear();

        // Wait until we're connected

        printf("Connecting to AP\n");
        printf("Press B to cancel\n");
        printf("\n");

        int oldstatus = -1;
        while (1)
        {
            swiWaitForVBlank();

            scanKeys();
            if (keysDown() & KEY_B) {
              gotoReturn = 1;
              break;
            }

            //consoleClear();
            int status = Wifi_AssocStatus();

            if (status != oldstatus)
            {
                printf("%s\n", ASSOCSTATUS_STRINGS[status]);
                oldstatus = status;
            }
            if (status == ASSOCSTATUS_CANNOTCONNECT)
            {
                printf("\n");
                printf("Cannot connect to AP\n");
                printf("Press START to restart\n");

                while (1)
                {
                    swiWaitForVBlank();
                    scanKeys();
                    if (keysDown() & KEY_START)
                      break;
                }
                gotoReturn = true;
                break;
            }
            else if (status == ASSOCSTATUS_ASSOCIATED)
                break;
        }
        if (gotoReturn) continue;

        consoleClear();

        // Get network information

        struct in_addr ip, gateway, mask, dns1, dns2;
        ip = Wifi_GetIPInfo(&gateway, &mask, &dns1, &dns2);

        printf("\n");
        printf("Connection information:\n");
        printf("\n");
        printf("IP:      %s\n", inet_ntoa(ip));
        printf("Gateway: %s\n", inet_ntoa(gateway));
        printf("Mask:    %s\n", inet_ntoa(mask));
        printf("DNS1:    %s\n", inet_ntoa(dns1));
        printf("DNS2:    %s\n", inet_ntoa(dns2));
        printf("\n");

        
        printf("Resolving IP of:\n");
        printf("\n");
        printf("   %s\n", url);
        printf("\n");

        struct hostent *host = gethostbyname(url);

        if (host)
            printf("IP: %s\n", inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
        else
            printf("Could not get IP\n");

        printf("\n");
        printf("Press A to end Internet Settings\n");

        while (1)
        {
            swiWaitForVBlank();

            scanKeys();
            if (keysHeld() & KEY_A){
              quit = 1;
              break;
            }
        }
        
    }
}