#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

/* Ports */
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

/* Pins */
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

/* Directions */
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1

/* Logic levels */
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8   DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

#endif
