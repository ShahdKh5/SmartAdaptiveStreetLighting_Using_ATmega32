#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include <util/delay.h>  /* For software debouncing delay */
#include "BUTTON_interface.h"

void BUTTON_voidInit(const BUTTON_Config_t *Copy_pstrButtonConfig) {
    /* TODO: 
       1. Set Copy_pstrButtonConfig->Pin on Copy_pstrButtonConfig->Port as INPUT.
       2. If PullType is BUTTON_PULL_UP, enable internal pull-up resistor if supported.
    */
}

u8 BUTTON_u8GetState(const BUTTON_Config_t *Copy_pstrButtonConfig) {
    u8 Local_u8FirstRead = 0;
    u8 Local_u8SecondRead = 0;
    u8 Local_u8State = BUTTON_RELEASED;

    /* TODO: 
       1. Read initial pin state into Local_u8FirstRead.
       2. If active signal detected (0 for PULL_UP, 1 for PULL_DOWN):
          a. Wait ~20ms (_delay_ms(20)) to bypass mechanical contact bounce.
          b. Read pin state again into Local_u8SecondRead.
          c. If Local_u8FirstRead == Local_u8SecondRead, confirm press state:
             - Return BUTTON_PRESSED.
       3. Otherwise, return BUTTON_RELEASED.
    */
    
    return Local_u8State;
}