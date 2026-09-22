#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "ULTRASONIC_interface.h"
#include <util/delay.h>

//Simple polling-based measurement.
//Timeout protects the loop if no echo ever returns.
#define ULTRASONIC_u32_TIMEOUT_US   30000UL

void ULTRASONIC_voidInit(const ULTRASONIC_Config_t *Copy_pstrConfig) {
    /* TODO: 
       1. Configure Trigger pin as OUTPUT.
       2. Configure Echo pin as INPUT.
       For multiple sensors
    */
	if (Copy_pstrConfig == NULL) return; // Guard against NULL pointer dereference

	DIO_voidSetPinDirection(Copy_pstrConfig->Trigger_u8_Port, Copy_pstrConfig->Trigger_u8_Pin, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(Copy_pstrConfig->Echo_u8_Port, Copy_pstrConfig->Echo_u8_Pin, DIO_u8_INPUT);

	// Ensure trigger pin starts LOW
	DIO_voidSetPinValue(Copy_pstrConfig->Trigger_u8_Port, Copy_pstrConfig->Trigger_u8_Pin, DIO_u8_LOW);
}

void ULTRASONIC_voidTrigger(const ULTRASONIC_Config_t *Copy_pstrConfig) {
    /* TODO: 
       1. Set Trigger pin HIGH.
       2. Delay for ~10 microseconds.
       3. Set Trigger pin LOW.
    */
	if (Copy_pstrConfig == NULL) return;

	DIO_voidSetPinValue(Copy_pstrConfig->Trigger_u8_Port, Copy_pstrConfig->Trigger_u8_Pin, DIO_u8_HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(Copy_pstrConfig->Trigger_u8_Port, Copy_pstrConfig->Trigger_u8_Pin, DIO_u8_LOW);
}

u16 ULTRASONIC_u16GetDistance(const ULTRASONIC_Config_t *Copy_pstrConfig) {
    /* TODO: 
       1. Call ULTRASONIC_voidTrigger().
       2. Measure the Echo pulse width duration (using Timer/ICU or delay loop).
       3. Calculate distance: Distance (cm) = (Duration * 0.0343) / 2.
       4. Return the calculated distance in cm.
    */
	if (Copy_pstrConfig == NULL) return 0;

    u32 Local_u32Duration = 0;

    //1. Send trigger pulse
    ULTRASONIC_voidTrigger(Copy_pstrConfig);

    //2. Wait for ECHO pin to go HIGH (with timeout)
	while (DIO_voidGetPinValue(Copy_pstrConfig->Echo_u8_Port, Copy_pstrConfig->Echo_u8_Pin) == DIO_u8_LOW)
	{
		_delay_us(1);
		if (Local_u32Duration > ULTRASONIC_u32_TIMEOUT_US) return 0; //nothing in range
	}

	//3. Measure duration while ECHO pin stays HIGH
	Local_u32Duration = 0;
	while (DIO_voidGetPinValue(Copy_pstrConfig->Echo_u8_Port, Copy_pstrConfig->Echo_u8_Pin) == DIO_u8_HIGH)
	{
		_delay_us(1);
		Local_u32Duration++;
		if (Local_u32Duration > ULTRASONIC_u32_TIMEOUT_US) break;
	}

    //Local_u32Duration now holds the pulse duration in microseconds

    return (u16)((Local_u32Duration * 343UL) / 20000UL);
}
