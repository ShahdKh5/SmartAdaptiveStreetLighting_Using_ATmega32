#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* One sensor = one Trigger pin + one Echo pin. Declare one config struct per
   physical HC-SR04 you wire up, so several sensors (one per zone) can each
   be initialized and read independently. */
typedef struct {
    u8 TrigPort;
    u8 TrigPin;
    u8 EchoPort;
    u8 EchoPin;
} ULTRASONIC_Config_t;

/* Configure the Trigger (OUTPUT) and Echo (INPUT) pins for this sensor */
void ULTRASONIC_voidInit(const ULTRASONIC_Config_t *Copy_pstrConfig);

/* Send a trigger pulse to this sensor */
void ULTRASONIC_voidTrigger(const ULTRASONIC_Config_t *Copy_pstrConfig);

/* Measure the distance in centimeters seen by this sensor (0 = no echo / out of range) */
u16 ULTRASONIC_u16GetDistance(const ULTRASONIC_Config_t *Copy_pstrConfig);

u16 ULTRASONIC_u16GetFilteredDistance(const ULTRASONIC_Config_t *Copy_pstrConfig);

#endif
