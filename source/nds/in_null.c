// in_null.c -- for systems without a mouse

#include "quakedef.h"

cvar_t _windowed_mouse = {"_windowed_mouse", "0", true}; // for compatibility

void IN_Init (void)
{
}

void IN_Shutdown (void)
{
}

void IN_Commands (void)
{
}

void IN_Move (usercmd_t *cmd)
{
}

/*
===========
IN_ModeChanged
===========
*/
void IN_ModeChanged (void)
{
}

