/*---------------------------------------------------------------------------------

	QWTF Lite Port video code
	-- generated by Maniac Xena
	-- QWTF is Team Fortress Software's property
	-- based on cquake project source code
---------------------------------------------------------------------------------*/
#include <video.h>
#include <quakedef.h>

u16	d_8to16table[256];
uint32 nextPBlock = (uint32)0;

void memcpy32(void* dst, const void* src, uint wdcount) ITCM_CODE;


void glColorTable(uint8 format, uint32 addr) {
	GFX_PAL_FORMAT = addr >> (4 - (format == GL_RGB4));
}
//---------------------------------------------------------------------------------
uint32 aalignVal(uint32 val, uint32 to) {
	return (val & (to - 1)) ? (val & ~(to - 1)) + to : val;
}

//---------------------------------------------------------------------------------
int ndsgetNextPaletteSlot(u16 count, uint8 format) {
	//---------------------------------------------------------------------------------
		// ensure the result aligns on a palette block for this format
	uint32 result = aalignVal(nextPBlock, 1 << (4 - (format == GL_RGB4)));

	// convert count to bytes and align to next (smallest format) palette block
	count = aalignVal(count << 1, 1 << 3);

	// ensure that end is within palette video mem
	if (result + count > 0x10000)   // VRAM_F - VRAM_E
		return -1;

	nextPBlock = result + count;
	return (int)result;
}

//---------------------------------------------------------------------------------
void ndsTexLoadPalVRAM(const u16* pal, u16 count, u32 addr) {
	//---------------------------------------------------------------------------------
	vramSetBankF(VRAM_F_LCD);
	////swiCopy( pal, &VRAM_F[addr>>1] , count / 2 | COPY_MODE_WORD);
	dmaCopyWords(3, (uint32*)pal, (uint32*)&VRAM_F[addr >> 1], count << 1);
	//memcpy32(&VRAM_F[addr>>1],pal,count/2);
	vramSetBankF(VRAM_F_TEX_PALETTE);
}

//---------------------------------------------------------------------------------
uint32 ndsTexLoadPal(const u16* pal, u16 count, uint8 format) {
	//---------------------------------------------------------------------------------
	uint32 addr = ndsgetNextPaletteSlot(count, format);
	if (addr >= 0)
		ndsTexLoadPalVRAM(pal, count, (u32)addr);

	return addr;
}

u16 ds_alpha_pal_bytes[32];
uint32 ds_alpha_pal;
uint32 ds_texture_pal;
// called at startup and after any gamma correction
void	VID_SetPalette(unsigned char* palette)
{
}
void	VID_InitPalette(unsigned char* palette)
{
	byte* pal;
	unsigned r, g, b;
	unsigned short i;
	u16	v, * table;
	static bool palflag = false;
	float inf, gm = 1.1f;

	//VID_LightmapPal();
//
// 8 8 8 encoding
//
	pal = palette;
	table = d_8to16table;
	for (i = 0; i < 256; i++)
	{
		r = pal[0];
		g = pal[1];
		b = pal[2];
#if 1
		inf = r;
		inf = 255 * pow((inf + 0.5) / 255.5, gm) + 0.5;
		if (inf < 0)
			inf = 0;
		if (inf > 255)
			inf = 255;
		r = inf;

		inf = g;
		inf = 255 * pow((inf + 0.5) / 255.5, gm) + 0.5;
		if (inf < 0)
			inf = 0;
		if (inf > 255)
			inf = 255;
		g = inf;

		inf = b;
		inf = 255 * pow((inf + 0.5) / 255.5, gm) + 0.5;
		if (inf < 0)
			inf = 0;
		if (inf > 255)
			inf = 255;
		b = inf;
#endif
		pal += 3;

		v = (1 << 15) | RGB15(r >> 3, g >> 3, b >> 3);
		*table++ = v;
		BG_PALETTE[i] = v;
		BG_PALETTE_SUB[i] = v;
	}
	BG_PALETTE[255] = 0;
	BG_PALETTE_SUB[255] = 0;
	//d_8to16table[255] = d_8to16table[0];
	//d_8to16table[255] &= 0xffffff;	// 255 is transparent
	ds_texture_pal = ndsTexLoadPal(d_8to16table, 256, GL_RGB256);
	glColorTable(GL_RGB256, ds_texture_pal);

	for (i = 0; i < 32; i++)
	{
		ds_alpha_pal_bytes[i] = RGB15(i, i, i);
	}
	ds_alpha_pal = ndsTexLoadPal(ds_alpha_pal_bytes, 32, GL_RGB32_A3);
	glColorTable(GL_RGB32_A3, ds_alpha_pal);

	glColorTable(GL_RGB256, ds_texture_pal);
}

int updatepal = 0;
int ds_vblanks = 0;
void VID_loadPal()
{
	ds_vblanks++;
	if (ds_vblanks & 0x1)
		*((u16*)SCREEN_BASE_BLOCK(15)) = 0xf058;
	else
		*((u16*)SCREEN_BASE_BLOCK(15)) = 0xf02b;

}

// called for bonus and pain flashes, and for underwater color changes
void	VID_ShiftPalette(unsigned char* palette)
{
	int i;
	byte* pal;
	unsigned r, g, b;
	u16	v, * table;

	pal = palette;
	table = d_8to16table;
	for (i = 0; i < 256; i++)
	{
		r = pal[0];
		g = pal[1];
		b = pal[2];
		pal += 3;

		v = (1 << 15) | RGB15(r >> 3, g >> 3, b >> 3);
		*table++ = v;
	}
	//updatepal = 1;
	vramSetBankF(VRAM_F_LCD);
	//swiCopy( pal, ds_texture_pal , count / 2 | COPY_MODE_WORD);
	dmaCopyWords(3, (uint32*)d_8to16table, (uint32*)&VRAM_F[ds_texture_pal >> 1], 256 << 1);
	vramSetBankF(VRAM_F_TEX_PALETTE);
	return;
}

int vid_on_top = 0;

void VID_swap_f(void)
{
	int			c;
	extern u16* ds_display_top;
	extern u16* ds_display_bottom;
	extern int	ds_display_bottom_height;

	extern int ds_bg_sub;
	extern int ds_bg_main;
	extern int ds_bg_text;

	if (vid_on_top)
	{
		lcdMainOnBottom();
		vid_on_top = 0;
		ds_display_bottom_height = 128;
		ds_display_bottom = (u16*)bgGetGfxPtr(ds_bg_main);
		ds_display_top = (u16*)bgGetGfxPtr(ds_bg_sub);
	}
	else
	{
		lcdMainOnTop();
		vid_on_top = 1;
		ds_display_bottom_height = 192;
		ds_display_bottom = (u16*)bgGetGfxPtr(ds_bg_sub);
		ds_display_top = (u16*)bgGetGfxPtr(ds_bg_main);
	}
	return;
}
