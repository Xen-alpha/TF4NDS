#ifndef HOST_H
#define HOST_H

#include <nds.h>

#include <quakedef.h>

int Host_Exit(void);
void Host_Init(quakeparms_t* parms);
void Host_Frame(float time);
#endif