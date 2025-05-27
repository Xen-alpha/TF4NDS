/************************************\
* Timers.h by dovoto *
\************************************/

// Modified by Torlus (March 2003)
#include "print.h"
#ifndef TIMERS_H
#define TIMERS_H

#define TIME_FREQUENCY_SYSTEM 0x0
#define TIME_FREQUENCY_64 0x1
#define TIME_FREQUENCY_256 0x2
#define TIME_FREQUENCY_1024 0x3
#define TIME_OVERFLOW 0x4
#define TIME_ENABLE 0x80
#define TIME_IRQ_ENABLE 0x40

inline  void Fps_Counter(void)
{
  static u32 totframes,lastsec,fps;
  if (REG_TM3D != lastsec)
  {
    fps = totframes;
    totframes=0;
    lastsec=REG_TM3D;
  }
  printnum(90,0,fps);
  totframes++;
}

#endif
