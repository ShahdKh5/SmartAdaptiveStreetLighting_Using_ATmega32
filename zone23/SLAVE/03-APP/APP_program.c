#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../01-MCAL/00-LIB/STD_TYPES.h"
#include "../01-MCAL/01-DIO/DIO_interface.h"
#include "../01-MCAL/03-TIMER/TIMER_interface.h"
#include "../01-MCAL/04-USART/USART_interface.h"
#include "../02-HAL/03-ULTRASONIC/ULTRASONIC_interface.h"
#include "../02-HAL/04-LED/LED_interface.h"
#include "APP_interface.h"
#include "APP_config.h"
#include "LINK_protocol.h"

static const ULTRASONIC_Config_t APP_strUltrasonic =
    { DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_PORTD, DIO_u8_PIN6 }; /* Trig=PD3, Echo=PD6 */

#define APP_u8_STATUS_OUT_PORT   DIO_u8_PORTD
#define APP_u8_STATUS_OUT_PIN    DIO_u8_PIN4

#define APP_u16_DETECT_RANGE_CM   20
#define APP_u8_HOLD_LOOPS         5

static u8 APP_u8LastStatusByte = 128; /* keeps the last good frame between USART updates */
static u8 APP_u8Hold           = 0;


void APP_voidSystemInit(void)
{
    LED_voidInit();            /* also inits Timer0 PWM on PB3 */
    USART_voidInit();
    ULTRASONIC_voidInit(&APP_strUltrasonic);
    DIO_voidSetPinDirection(APP_u8_STATUS_OUT_PORT, APP_u8_STATUS_OUT_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinValue(APP_u8_STATUS_OUT_PORT, APP_u8_STATUS_OUT_PIN, DIO_u8_LOW);
}

void APP_voidControlLighting(void)
{
    static u8 APP_u8SavedManualLevel = LED_u8_LEVEL_OFF;

    u8  Local_u8Night, Local_u8Manual;
    u16 Local_u16Distance;
    u8  Local_u8Level;

    while (USART_u8IsDataAvailable())
    {
        APP_u8LastStatusByte = USART_u8ReceiveByte();

        u8 Tmp_Manual = (APP_u8LastStatusByte >> LINK_u8_MANUAL_BIT) & 0x01;
        u8 Tmp_Zone   = (APP_u8LastStatusByte >> LINK_u8_ZONE_SHIFT)  & LINK_u8_ZONE_MASK;
        u8 Tmp_Level  = (APP_u8LastStatusByte >> LINK_u8_LEVEL_SHIFT) & LINK_u8_LEVEL_MASK;

        if (Tmp_Manual && (Tmp_Zone == SLAVE_u8_MY_ZONE))
        {
            APP_u8SavedManualLevel = Tmp_Level; 
        }
    }

    Local_u8Night  = (APP_u8LastStatusByte >> LINK_u8_NIGHT_BIT)  & 0x01;
    Local_u8Manual = (APP_u8LastStatusByte >> LINK_u8_MANUAL_BIT) & 0x01;

    if (Local_u8Manual)
    {
        Local_u8Level = APP_u8SavedManualLevel; 
        APP_u8Hold = 0;
    }
    else if (!Local_u8Night)
    {
        Local_u8Level = LED_u8_LEVEL_OFF;
        APP_u8Hold = 0;
    }
    else
    {
        Local_u16Distance = ULTRASONIC_u16GetDistance(&APP_strUltrasonic);

        if (Local_u16Distance != 0 && Local_u16Distance < APP_u16_DETECT_RANGE_CM)
        {
            Local_u8Level = LED_u8_LEVEL_HIGH;
            APP_u8Hold = APP_u8_HOLD_LOOPS;
        }
        else
        {
            if (APP_u8Hold > 0)
            {
                Local_u8Level = LED_u8_LEVEL_HIGH;
                APP_u8Hold--;
            }
            else
            {
                Local_u8Level = LED_u8_LEVEL_LOW;
            }
        }
    }

    static u8 APP_u8LastAppliedLevel = 255;
    if (Local_u8Level != APP_u8LastAppliedLevel)
    {
        LED_voidSetLevel(Local_u8Level);
        DIO_voidSetPinValue(APP_u8_STATUS_OUT_PORT, APP_u8_STATUS_OUT_PIN,
                            (Local_u8Level == LED_u8_LEVEL_HIGH) ? DIO_u8_HIGH : DIO_u8_LOW);

        APP_u8LastAppliedLevel = Local_u8Level;
    }
}
