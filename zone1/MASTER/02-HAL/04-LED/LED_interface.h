#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* Initialize LED/Lamp pins for Zone A and Zone B */
void LED_voidInit(void);

/* Set brightness for Zone A. 
   Options: 0 (OFF), 1 (LOW brightness), 2 (HIGH brightness) */
void LED_voidSetZoneA_Brightness(u8 Copy_u8Level);

/* Set brightness for Zone B. */
void LED_voidSetZoneB_Brightness(u8 Copy_u8Level);

#endif
