#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "../../01-MCAL/03-TIMER/TIMER_interface.h"
#include "LED_interface.h"

void LED_voidInit(void) {
    /* TODO: 
       1. Set the direction of the PWM pins (e.g., OC0 and OC1A) connected to the LED drivers as OUTPUT.
    */
}

void LED_voidSetZoneA_Brightness(u8 Copy_u8Level) {
    /* TODO: 
       1. Use TIMER_voidTimer0SetCompareValue to control the PWM duty cycle for Zone A.
       2. Example: 
          if Copy_u8Level == 0 -> Set compare value to 0 (OFF)
          if Copy_u8Level == 1 -> Set compare value to ~64 (25% LOW)
          if Copy_u8Level == 2 -> Set compare value to ~230 (90% HIGH)
    */
}

void LED_voidSetZoneB_Brightness(u8 Copy_u8Level) {
    /* TODO: 
       1. Use TIMER_voidTimer1ASetCompareValue (or equivalent PWM function) to control the PWM duty cycle for Zone B.
    */
}
