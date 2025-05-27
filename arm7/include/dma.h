#include "gba.h"
/******************************************\
* DMA.h by dovoto
\******************************************/

// Modified by Torlus (March 2003)

#ifndef DMA_H
#define DMA_H

//these defines let you control individual bit in the control register
#define REG_DMA3SAD   *(u32*)0x40000D4
#define REG_DMA3SAD_L *(u32*)0x40000D4
#define REG_DMA3SAD_H *(u32*)0x40000D6
#define REG_DMA3DAD   *(u32*)0x40000D8
#define REG_DMA3DAD_L *(u32*)0x40000D8
#define REG_DMA3DAD_H *(u32*)0x40000DA
#define REG_DMA3CNT   *(u32*)0x40000DC

#define REG_DMA3SAD     *(u32*)0x40000D4	//DMA3 Source Address
#define REG_DMA3DAD     *(u32*)0x40000D8	//DMA3 Destination Address
#define REG_DMA3CNT_L   *(u16*)0x40000DC	//DMA3 Control Low Value
#define REG_DMA3CNT_H   *(u16*)0x40000DE	//DMA3 Control High Value
#define REG_DMA3CNT     *(u32*)0x40000DC	//DMA3 Control (Amount)

#define DMA_ENABLE 0x80000000
#define DMA_INTERUPT_ENABLE 0x40000000
#define DMA_TIMING_IMMEDIATE 0x00000000
#define DMA_TIMEING_IMMEDIATE 0x00000000
#define DMA_TIMEING_VBLANK 0x10000000
#define DMA_TIMEING_HBLANK 0x20000000
#define DMA_TIMEING_SYNC_TO_DISPLAY 0x30000000
#define DMA_16 0x00000000
#define DMA_32 0x04000000
#define DMA_REPEATE 0x02000000
#define DMA_SOURCE_INCREMENT 0x00000000
#define DMA_SOURCE_DECREMENT 0x00800000
#define DMA_SOURCE_FIXED 0x01000000
#define DMA_DEST_INCREMENT 0x00000000
#define DMA_DEST_DECREMENT 0x00200000
#define DMA_DEST_FIXED 0x00400000
#define DMA_DEST_RELOAD 0x00600000

//these defines group common options to save typing. You may notice that I don't have to include the option to increment the source and address register as that is the default.

#define DMA_32NOW DMA_ENABLE | DMA_TIMEING_IMMEDIATE |DMA_32
#define DMA_16NOW DMA_ENABLE | DMA_TIMEING_IMMEDIATE |DMA_16


#endif
