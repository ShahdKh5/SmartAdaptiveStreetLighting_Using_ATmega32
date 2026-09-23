#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

/* Simple one-way broadcast link: the MASTER's TXD (PD1) is wired straight to
   BOTH slaves' RXD (PD0) — one master TX line feeding two listeners, no
   addressing needed since each slave only cares about the single shared
   status byte. 9600 8N1 @ 8MHz. */

void USART_voidInit(void);

/* Blocking send (used by the MASTER only) */
void USART_voidSendByte(u8 Copy_u8Data);

/* Non-blocking check + blocking read (used by the SLAVEs) */
u8 USART_u8IsDataAvailable(void);
u8 USART_u8ReceiveByte(void);

#endif
