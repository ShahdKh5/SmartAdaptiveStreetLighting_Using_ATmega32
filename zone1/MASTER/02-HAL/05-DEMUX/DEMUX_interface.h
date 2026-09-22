#ifndef DEMUX_INTERFACE_H
#define DEMUX_INTERFACE_H

#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* Initialize the Select and Enable pins for the Demultiplexer */
void DEMUX_voidInit(void);

/* Select which channel to output to (0 to N-1) */
void DEMUX_voidSelectChannel(u8 Copy_u8Channel);

/* Enable or disable the Demultiplexer IC */
void DEMUX_voidSetEnable(u8 Copy_u8State);

#endif