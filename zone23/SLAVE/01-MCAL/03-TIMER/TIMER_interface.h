#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

/* Configure Timer0 as Fast-PWM, non-inverting, on OC0 (PB3), prescaler 8 */
void TIMER_voidTimer0Init(void);

/* Set the PWM duty (0-255) driving OC0 / PB3 */
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8Value);

#endif
