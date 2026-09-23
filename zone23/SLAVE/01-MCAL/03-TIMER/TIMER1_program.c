#include "../00-LIB/STD_TYPES.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

void TIMER1_voidInit(void)
{
    TCCR1A = 0;
    TCCR1B = (1 << CS11); /* Prescaler = 8 */
}

void TIMER1_voidSetICUEdgeTrigger(u8 Copy_u8Edge)
{
    if(Copy_u8Edge == TIMER1_ICU_RISING_EDGE)
        TCCR1B |= (1 << ICES1);
    else
        TCCR1B &= ~(1 << ICES1);
}

void TIMER1_voidClearICUFlag(void)
{
    TIFR = (1 << ICF1);
}

u8 TIMER1_u8GetICUFlag(void)
{
    return ((TIFR >> ICF1) & 0x01);
}

u16 TIMER1_u16GetICUValue(void)
{
    return ICR1;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
    TCNT1 = Copy_u16Value;
}

void TIMER1_voidStop(void)
{
    TCCR1B = 0;
}
