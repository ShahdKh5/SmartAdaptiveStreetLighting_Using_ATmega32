#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

#define LDR_u8_DAY   0
#define LDR_u8_NIGHT 1

/* Initialize LDR connection pin */
void LDR_voidInit(void);

/* Check if it's Day or Night based on LDR reading. */
u8 LDR_u8IsNight(void);

#endif
