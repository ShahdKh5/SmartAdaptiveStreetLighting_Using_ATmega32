#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

#define TIMER1_ICU_FALLING_EDGE 0
#define TIMER1_ICU_RISING_EDGE  1

void TIMER1_voidInit(void);

void TIMER1_voidSetICUEdgeTrigger(u8 Copy_u8Edge);

void TIMER1_voidClearICUFlag(void);

u8 TIMER1_u8GetICUFlag(void);

u16 TIMER1_u16GetICUValue(void);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

void TIMER1_voidStop(void);

#endif
