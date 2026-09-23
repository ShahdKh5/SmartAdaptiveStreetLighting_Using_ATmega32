#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* USART Registers Memory Mapping */
#define UDR     *((volatile u8 *)0x2C)
#define UCSRA   *((volatile u8 *)0x2B)
#define UCSRB   *((volatile u8 *)0x2A)
#define UBRRL   *((volatile u8 *)0x29)

/* Notice: UCSRC and UBRRH share the same physical address */
#define UCSRC   *((volatile u8 *)0x40)
#define UBRRH   *((volatile u8 *)0x40)

/* UCSRA Bits */
#define RXC     7
#define UDRE    5

/* UCSRB Bits */
#define RXEN    4
#define TXEN    3

/* UCSRC Bits */
#define URSEL   7
#define UCSZ1   2
#define UCSZ0   1

#endif
