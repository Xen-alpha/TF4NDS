#ifndef VIDEO_H
#define VIDEO_H
#include <nds.h>

void glColorTable(uint8 format, uint32 addr);
uint32 aalignVal(uint32 val, uint32 to);
int ndsgetNextPaletteSlot(u16 count, uint8 format);
void ndsTexLoadPalVRAM(const u16* pal, u16 count, u32 addr);
uint32 ndsTexLoadPal(const u16* pal, u16 count, uint8 format);
void	VID_SetPalette(unsigned char* palette);
void	VID_InitPalette(unsigned char* palette);

void VID_loadPal(void);
void	VID_ShiftPalette(unsigned char* palette);
void VID_swap_f(void);
#endif