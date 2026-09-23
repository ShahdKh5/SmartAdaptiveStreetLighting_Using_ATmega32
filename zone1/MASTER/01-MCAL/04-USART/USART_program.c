#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"

#define USART_u32_BAUD        9600UL
#define USART_u16_UBRR_VALUE  ((F_CPU / (16UL * USART_u32_BAUD)) - 1)

void USART_voidInit(void)
{
    UBRRH = (u8)(USART_u16_UBRR_VALUE >> 8);
    UBRRL = (u8)(USART_u16_UBRR_VALUE);

    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);

    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void USART_voidSendByte(u8 Copy_u8Data)
{
    while (GET_BIT(UCSRA, UDRE) == 0);
    UDR = Copy_u8Data;
}

u8 USART_u8IsDataAvailable(void)
{
    return GET_BIT(UCSRA, RXC);
}

u8 USART_u8ReceiveByte(void)
{
    while (GET_BIT(UCSRA, RXC) == 0);
    return UDR;
}
