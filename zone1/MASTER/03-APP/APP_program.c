#include "../01-MCAL/00-LIB/STD_TYPES.h"
#include "../02-HAL/01-LCD/LCD_interface.h"
#include "../02-HAL/02-LDR/LDR_interface.h"
#include "../02-HAL/03-IR/IR_interface.h"
#include "../02-HAL/04-LED/LED_interface.h"
#include "../01-MCAL/02-ADC/ADC_interface.h"
#include "../01-MCAL/03-TIMER/TIMER_interface.h"
#include "APP_interface.h"

void APP_voidSystemInit(void) {
    /* TODO:
       1. Initialize all MCAL layers (ADC, Timers for PWM).
       2. Initialize all HAL layers (LCD, LDR, IR, LED).
       3. Display a welcome message on the LCD.
    */
}

void APP_voidControlLighting(void) {
    /* TODO:
       1. Check if it's Day or Night using LDR_u8IsNight().
       2. If DAY: Turn OFF all LED zones (Brightness Level 0).
       3. If NIGHT:
          a. Read IR sensors (Zone A and Zone B).
          b. If no motion in a zone, set its brightness to LOW (Level 1).
          c. If motion detected in a zone, set its brightness to HIGH (Level 2).
    */
}

void APP_voidUpdateDisplay(void) {
    /* TODO:
       1. Update the LCD with the current state (e.g., "DAY OFF" or "NIGHT | LOW").
       2. Show which zones have motion detected.
    */
}
