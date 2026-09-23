#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"


#define LED_u8_LEVEL_OFF    0
#define LED_u8_LEVEL_LOW    1
#define LED_u8_LEVEL_HIGH   2

void LED_voidInit(void);
void LED_voidSetLevel(u8 Copy_u8Level);

#endif
