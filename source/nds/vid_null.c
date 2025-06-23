// vid_null.c -- null video driver to aid porting efforts

#include "quakedef.h"
#include "d_local.h"
#include <nds.h>

extern viddef_t	vid;				// global video state

#define	BASEWIDTH	256
#define	BASEHEIGHT	192

byte	vid_buffer[BASEWIDTH*BASEHEIGHT];
short	zbuffer[BASEWIDTH*BASEHEIGHT];
byte	surfcache[64*1024]; // reduced from 256 KB to 64 KB for NDS

unsigned short	d_8to16table[256];
unsigned	d_8to24table[256];

void	VID_SetPalette (unsigned char *palette)
{
  glColorTableEXT(0,0,256,0,0, palette);
}

void	VID_ShiftPalette (unsigned char *palette)
{
  VID_SetPalette(palette);
}

void	VID_Init (unsigned char *palette)
{
	vid.maxwarpwidth = vid.width = vid.conwidth = BASEWIDTH;
	vid.maxwarpheight = vid.height = vid.conheight = BASEHEIGHT;
	vid.aspect = 1.333f; // 4:3 aspect ratio
	vid.numpages = 1;
	vid.colormap = host_colormap;
	vid.fullbright = 256 - LittleLong (*((int *)vid.colormap + 2048));
	vid.buffer = vid.conbuffer = vid_buffer;
	vid.rowbytes = vid.conrowbytes = BASEWIDTH;
	
	d_pzbuffer = zbuffer;
	D_InitCaches (surfcache, sizeof(surfcache));

  // TODO: we need to init sound here
  // S_Init(); // sound gets initialized here
}

void	VID_Shutdown (void)
{
}

void	VID_Update (vrect_t *rects)
{
  dmaCopy(VRAM_D, vid.buffer, BASEWIDTH * BASEHEIGHT);
  // we don't need to do anything since VID_UnlockBuffer will copy the
  // contents of the buffer to the VRAM bank E, which is mapped to the LCD
  // in NDS.
}

void VID_LockBuffer (void)
{
  // In NDS, make sure Bank E is set to LCD mode
  //vramSetBankE(VRAM_E_LCD);
}

void VID_UnlockBuffer (void)
{
  
  // In NDS, make sure Bank E is set to Main BG mode
  //vramSetBankE(VRAM_E_MAIN_BG);
}

/*
================
D_BeginDirectRect
================
*/
void D_BeginDirectRect (int x, int y, byte *pbitmap, int width, int height)
{
}


/*
================
D_EndDirectRect
================
*/
void D_EndDirectRect (int x, int y, int width, int height)
{
}


