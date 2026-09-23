#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "../../01-MCAL/03-TIMER/TIMER_interface.h"
#include "LED_interface.h"

#define LED_u8_OC0_PORT   DIO_u8_PORTB
#define LED_u8_OC0_PIN    DIO_u8_PIN3

#define LED_u8_DUTY_OFF   0
#define LED_u8_DUTY_LOW   64    /* ~25% of 255 */
#define LED_u8_DUTY_HIGH  230   /* ~90% of 255 */

void LED_voidInit(void)
{
    DIO_voidSetPinDirection(LED_u8_OC0_PORT, LED_u8_OC0_PIN, DIO_u8_OUTPUT);
    TIMER_voidTimer0Init();
}

void LED_voidSetLevel(u8 Copy_u8Level)
{
    u8 Local_u8Duty;
    switch (Copy_u8Level)
    {
        case LED_u8_LEVEL_LOW:  Local_u8Duty = LED_u8_DUTY_LOW;  break;
        case LED_u8_LEVEL_HIGH: Local_u8Duty = LED_u8_DUTY_HIGH; break;
        default:                Local_u8Duty = LED_u8_DUTY_OFF;  break;
    }
    TIMER_voidTimer0SetCompareValue(Local_u8Duty);
}
