#include "../00-LIB/STD_TYPES.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"

void TIMER_voidTimer0Init(void)
{
    /* Phase Correct PWM mode (WGM01:WGM00 = 0,1), Clear OC0 on compare match up-counting (non-inverting),
       prescaler = 8 (CS01 = 1) */
    TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << CS01);
    OCR0  = 0;
}

void TIMER_voidTimer0SetCompareValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}
