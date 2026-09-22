#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

#include "../../01-MCAL/00-LIB/STD_TYPES.h"

typedef struct {
    u8 Trigger_u8_Port;
    u8 Trigger_u8_Pin;
    u8 Echo_u8_Port;
    u8 Echo_u8_Pin;
} ULTRASONIC_Config_t;

/* Initialize the Trigger and Echo pins for the Ultrasonic sensor */
void ULTRASONIC_voidInit(const ULTRASONIC_Config_t *Copy_pstrConfig);

/* Send a trigger pulse to the Ultrasonic sensor */
void ULTRASONIC_voidTrigger(const ULTRASONIC_Config_t *Copy_pstrConfig);

/* Measure the distance in centimeters using the Ultrasonic sensor (0 = no echo / out of range)*/
u16 ULTRASONIC_u16GetDistance(const ULTRASONIC_Config_t *Copy_pstrConfig);

#endif
