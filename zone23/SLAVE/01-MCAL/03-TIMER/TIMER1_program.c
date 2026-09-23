#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

void TIMER1_voidInit(void)
{
    TCCR1A = 0;
    /* Set configured prescaler (= 8) while preserving other TCCR1B bits */
    TCCR1B = (TCCR1B & TIMER1_PRESCALER_MASK) | TIMER1_PRESCALER;
}

void TIMER1_voidSetICUEdgeTrigger(u8 Copy_u8Edge)
{
    if(Copy_u8Edge == TIMER1_ICU_RISING_EDGE)
    	SET_BIT(TCCR1B, ICES1);
    else
    	CLR_BIT(TCCR1B, ICES1);
}

void TIMER1_voidClearICUFlag(void)
{
	SET_BIT(TIFR, ICF1);
}

u8 TIMER1_u8GetICUFlag(void)
{
    return GET_BIT(TIFR, ICF1);
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
	/* Clear prescaler bits to stop the clock */
	 TCCR1B &= TIMER1_PRESCALER_MASK;
}
