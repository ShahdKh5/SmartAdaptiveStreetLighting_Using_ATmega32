#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

#define LDR_u8_PORT  DIO_u8_PORTA
#define LDR_u8_PIN   DIO_u8_PIN0

#define NIGHT_THRESHOLD 512

/* Initialize LDR connection pin */
void LDR_voidInit(void);

/* Check if it's Day or Night based on LDR reading. 
   Return 0 for DAY, 1 for NIGHT. */
u8 LDR_u8IsNight(void);

#endif
