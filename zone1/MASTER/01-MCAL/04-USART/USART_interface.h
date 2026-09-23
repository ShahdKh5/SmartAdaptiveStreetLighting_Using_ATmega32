#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

void USART_voidInit(void);

void USART_voidSendByte(u8 Copy_u8Data);

u8 USART_u8IsDataAvailable(void);
u8 USART_u8ReceiveByte(void);

#endif
