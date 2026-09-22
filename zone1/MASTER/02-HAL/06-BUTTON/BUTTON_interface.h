#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* Button Connection Types */
#define BUTTON_PULL_DOWN    0
#define BUTTON_PULL_UP      1

/* Button Pressed States */
#define BUTTON_RELEASED     0
#define BUTTON_PRESSED      1

/* Structure to define Button Configuration */
typedef struct {
    u8 Port;
    u8 Pin;
    u8 PullType; /* BUTTON_PULL_DOWN or BUTTON_PULL_UP */
} BUTTON_Config_t;

/* Initialize the specified button pin as INPUT */
void BUTTON_voidInit(const BUTTON_Config_t *Copy_pstrButtonConfig);

/* Read the state of the button with de-bouncing (Returns BUTTON_PRESSED or BUTTON_RELEASED) */
u8 BUTTON_u8GetState(const BUTTON_Config_t *Copy_pstrButtonConfig);

#endif