#include <avr/io.h>
#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRA, Copy_u8Pin); else CLR_BIT(DDRA, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRB, Copy_u8Pin); else CLR_BIT(DDRB, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRC, Copy_u8Pin); else CLR_BIT(DDRC, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DDRD, Copy_u8Pin); else CLR_BIT(DDRD, Copy_u8Pin);
            break;
    }
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTA, Copy_u8Pin); else CLR_BIT(PORTA, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTB, Copy_u8Pin); else CLR_BIT(PORTB, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTC, Copy_u8Pin); else CLR_BIT(PORTC, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(PORTD, Copy_u8Pin); else CLR_BIT(PORTD, Copy_u8Pin);
            break;
    }
}

u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8Value = 0;
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: Local_u8Value = GET_BIT(PINA, Copy_u8Pin); break;
        case DIO_u8_PORTB: Local_u8Value = GET_BIT(PINB, Copy_u8Pin); break;
        case DIO_u8_PORTC: Local_u8Value = GET_BIT(PINC, Copy_u8Pin); break;
        case DIO_u8_PORTD: Local_u8Value = GET_BIT(PIND, Copy_u8Pin); break;
    }
    return Local_u8Value;
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: DDRA = Copy_u8Direction; break;
        case DIO_u8_PORTB: DDRB = Copy_u8Direction; break;
        case DIO_u8_PORTC: DDRC = Copy_u8Direction; break;
        case DIO_u8_PORTD: DDRD = Copy_u8Direction; break;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: PORTA = Copy_u8Value; break;
        case DIO_u8_PORTB: PORTB = Copy_u8Value; break;
        case DIO_u8_PORTC: PORTC = Copy_u8Value; break;
        case DIO_u8_PORTD: PORTD = Copy_u8Value; break;
    }
}
