#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* Each board now drives ONE zone's LED bank directly through its own
   hardware PWM (OC0 / PB3) — no DEMUX, no time-multiplexing needed,
   since every zone finally has its own dedicated microcontroller. */

#define LED_u8_LEVEL_OFF    0
#define LED_u8_LEVEL_LOW    1
#define LED_u8_LEVEL_HIGH   2

void LED_voidInit(void);
void LED_voidSetLevel(u8 Copy_u8Level);

#endif
