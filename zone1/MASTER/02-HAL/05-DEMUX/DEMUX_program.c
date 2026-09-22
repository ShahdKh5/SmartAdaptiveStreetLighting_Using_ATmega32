#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "DEMUX_config.h"
#include "DEMUX_interface.h"

void DEMUX_voidInit(void) {
    /* TODO: 
       1. Set S0, S1, S2 (Select pins) as OUTPUT.
       2. Set EN (Enable pin) as OUTPUT.
    */
}

void DEMUX_voidSelectChannel(u8 Copy_u8Channel) {
    /* TODO: 
       1. Extract bit values of Copy_u8Channel.
       2. Write bit 0 to DEMUX_S0_PIN.
       3. Write bit 1 to DEMUX_S1_PIN.
       4. Write bit 2 to DEMUX_S2_PIN.
    */
}

void DEMUX_voidSetEnable(u8 Copy_u8State) {
    /* TODO: 
       1. Set DEMUX_EN_PIN to Copy_u8State (HIGH/LOW based on active HIGH/LOW enable logic).
    */
}