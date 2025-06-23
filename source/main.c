#include <stdio.h>

#include <nds.h>
#include <fat.h>
#include <filesystem.h>
#include <dswifi9.h>
#include <sys/socket.h>
#include <netinet/in.h>

void quake_main (int argc, char **argv);
void getWifiConnection(void);

int main(int argc, char **argv)
{
    // Camera * cam = (Camera *) malloc(sizeof(Camera));
    // Enable 3D
    videoSetMode(MODE_FB3);
    
    // Setup some VRAM as memory for main engine background, main engine
    // sprites, and 3D textures.
    setBrightness(2, 0);

    // 3D Texture: total 256KB
    vramSetBankA(VRAM_A_TEXTURE);
    vramSetBankB(VRAM_B_TEXTURE);
    // MODE_FB3 Test: 128KB
    vramSetBankC(VRAM_C_LCD);
    // MODE_FB3 Test: 128KB
    vramSetBankD(VRAM_D_LCD);
    // TODO: 이게 필요할지 안 필요할지 모르겠다. 텍스처가 16bit 그래픽이면 아래 뱅크는 다른 데로 돌리자.
    vramSetBankF(VRAM_F_TEX_PALETTE); // 16KB, Texture palette slot 0
    vramSetBankG(VRAM_G_TEX_PALETTE_SLOT1); // 16KB, Texture palette slot 1

    // set main 2d engine: BG2 only, 256x256, 8bpp, Total 64KB
    //vramSetBankE(VRAM_E_MAIN_BG); // 상단 BG
    vramSetBankH(VRAM_H_SUB_BG);      // 하단 BG
    vramSetBankI(VRAM_I_LCD);     // 버퍼 용도로 바꿔 CPU 및 디스플레이 엔진의 렌더링 접근을 막는다.

    Wifi_InitDefault(INIT_ONLY);
    
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
    getWifiConnection();

    // Main game loop
    quake_main(argc, argv);

    return 0;

}

void getWifiConnection() {
  // Set the library in scan mode
  Wifi_ScanMode();
  printf("Scanning for WiFi networks...\n");
  while (1)
  {
      swiWaitForVBlank();
  
      // Get find out how many APs there are in the area
      int count = Wifi_GetNumAP();
  
      Wifi_AccessPoint ap;
      for (int i = 0; i < count; i++)
      {
          
          Wifi_GetAPData(i, &ap);
  
          const char *security = "Open";
          if (ap.flags & WFLAG_APDATA_WPA)
              security = "WPA ";
          else if (ap.flags & WFLAG_APDATA_WEP)
              security = "WEP ";
  
          // WPA isn't supported in NDSL! Only DSi supports WPA.
  
          printf("[%.24s]\n", ap.ssid);
          printf("%s | Channel %2d | RSSI %u\n", security, ap.channel, ap.rssi);
          printf("ssid_len: %d\n", ap.ssid_len);
          printf("has spinlock: %ld\n", ap.spinlock);
          printf("\n");
      }
      if (count == 1)
      {
          Wifi_GetAPData(0, &ap);
          if (strncmp(ap.ssid, "melonAP", 7) == 0) // connect to 'melonAP' when using melonDS
          {
              // If there is only one AP, connect to it
              // Wifi_SetIP(0, 0, 0, 0, 0);
              printf("Connecting to %s...\n", ap.ssid);
              Wifi_ConnectAP(&ap, WEPMODE_NONE, 0, 0);
              break;
          }
      }
      else if (count > 1) // 일단 첫번째 것에만 비번 없이 연결 시도하도록 한다.
      {
          printf("Multiple APs found. Please select one to connect.\n");
          // Here you could implement a selection mechanism
          // For now, we will just wait for user input
          printf("Press A to connect to the first AP.\n");
          while (1)
          {
              scanKeys();
              if (keysDown() & KEY_A)
              {
                  // Wifi_SetIP(0, 0, 0, 0, 0);
                  Wifi_GetAPData(0, &ap);
                  Wifi_ConnectAP(&ap, WEPMODE_NONE, 0, 0);
                  break;
              }
          }
      }
  }
  while (1)
  {
      swiWaitForVBlank();
  
      int status = Wifi_AssocStatus();
      
      if (status == ASSOCSTATUS_CANNOTCONNECT)
      {
          // We can't connect to this host, try to connect to a different one!
          printf("Cannot connect to the host. Reboot the device to retry...\n");
      }
      
      if (status == ASSOCSTATUS_ASSOCIATED)
      {
          // Success!
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
          break;
      }
  }
}