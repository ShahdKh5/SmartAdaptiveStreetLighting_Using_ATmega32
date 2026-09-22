#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "BUTTON_interface.h"

void BUTTON_voidInit(const BUTTON_Config_t *Copy_pstrButtonConfig)
{
    DIO_voidSetPinDirection(Copy_pstrButtonConfig->Port, Copy_pstrButtonConfig->Pin, DIO_u8_INPUT);

    /* On the ATmega32, writing PORTx HIGH while DDRx is INPUT enables that
       pin's internal pull-up resistor — use this for BUTTON_PULL_UP wiring
       (button to GND). For BUTTON_PULL_DOWN wiring, leave it as-is. */
    if (Copy_pstrButtonConfig->PullType == BUTTON_PULL_UP)
    {
        DIO_voidSetPinValue(Copy_pstrButtonConfig->Port, Copy_pstrButtonConfig->Pin, DIO_u8_HIGH);
    }
}

u8 BUTTON_u8GetState(const BUTTON_Config_t *Copy_pstrButtonConfig)
{
    u8 Local_u8ActiveLevel = (Copy_pstrButtonConfig->PullType == BUTTON_PULL_UP) ? DIO_u8_LOW : DIO_u8_HIGH;
    u8 Local_u8FirstRead;
    u8 Local_u8SecondRead;
    u8 Local_u8State = BUTTON_RELEASED;

    Local_u8FirstRead = DIO_voidGetPinValue(Copy_pstrButtonConfig->Port, Copy_pstrButtonConfig->Pin);
    if (Local_u8FirstRead == Local_u8ActiveLevel)
    {
        _delay_ms(20); /* debounce */
        Local_u8SecondRead = DIO_voidGetPinValue(Copy_pstrButtonConfig->Port, Copy_pstrButtonConfig->Pin);
        if (Local_u8SecondRead == Local_u8ActiveLevel)
        {
            Local_u8State = BUTTON_PRESSED;
        }
    }
    return Local_u8State;
}
u8 BUTTON_u8GetPressEvent(const BUTTON_Config_t *Copy_pstrConfig, u8 *Copy_pu8PrevState)
{
    u8 Local_u8CurrentState = BUTTON_u8GetState(Copy_pstrConfig);
    u8 Local_u8Event = BUTTON_RELEASED;

    if (Local_u8CurrentState == BUTTON_PRESSED && *Copy_pu8PrevState == BUTTON_RELEASED)
    {
        Local_u8Event = BUTTON_PRESSED;  
    }

    *Copy_pu8PrevState = Local_u8CurrentState;
    return Local_u8Event;
}
