#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"
 /* Phase Correct PWM mode (WGM01:WGM00 = 0,1), Clear OC0 on compare match up-counting (non-inverting),
       prescaler = 8  */
void TIMER_voidTimer0Init(void);

void TIMER_voidTimer0SetCompareValue(u8 Copy_u8Value);

#endif
