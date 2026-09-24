#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

void TIMER_voidTimer0Init(void)
{
   

    SET_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    SET_BIT(TCCR0, COM01);
    CLR_BIT(TCCR0, COM00);

    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);

    OCR0 = 0;
}

void TIMER_voidTimer0SetCompareValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}
