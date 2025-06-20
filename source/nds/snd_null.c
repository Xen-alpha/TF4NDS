#include "quakedef.h"

qboolean SNDDMA_Init(void) {
	// This function initializes the sound device.
	// Since this is a null implementation, we simply return 0 to indicate success.
	return 0;
}

int SNDDMA_GetDMAPos(void) {
	// This function returns the current position of the sound DMA.
	// Since this is a null implementation, we return 0.
	return 0;
}

void SNDDMA_Shutdown(void) {
	// This function shuts down the sound device.
// No action is needed for a null implementation.
}

/*
==============
SNDDMA_Submit

Send sound to device if buffer isn't really the dma buffer
===============
*/
void SNDDMA_Submit(void)
{
}