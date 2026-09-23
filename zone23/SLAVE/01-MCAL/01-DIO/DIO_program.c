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
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DIO_u8_DDRA_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_DDRA_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DIO_u8_DDRB_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_DDRB_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DIO_u8_DDRC_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_DDRC_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Direction == DIO_u8_OUTPUT) SET_BIT(DIO_u8_DDRD_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_DDRD_REG, Copy_u8Pin);
            break;
    }
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(DIO_u8_PORTA_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_PORTA_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTB:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(DIO_u8_PORTB_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_PORTB_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTC:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(DIO_u8_PORTC_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_PORTC_REG, Copy_u8Pin);
            break;
        case DIO_u8_PORTD:
            if (Copy_u8Value == DIO_u8_HIGH) SET_BIT(DIO_u8_PORTD_REG, Copy_u8Pin); else CLR_BIT(DIO_u8_PORTD_REG, Copy_u8Pin);
            break;
    }
}

u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8Value = 0;
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: Local_u8Value = GET_BIT(DIO_u8_PINA_REG, Copy_u8Pin); break;
        case DIO_u8_PORTB: Local_u8Value = GET_BIT(DIO_u8_PINB_REG, Copy_u8Pin); break;
        case DIO_u8_PORTC: Local_u8Value = GET_BIT(DIO_u8_PINC_REG, Copy_u8Pin); break;
        case DIO_u8_PORTD: Local_u8Value = GET_BIT(DIO_u8_PIND_REG, Copy_u8Pin); break;
    }
    return Local_u8Value;
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: DIO_u8_DDRA_REG = Copy_u8Direction; break;
        case DIO_u8_PORTB: DIO_u8_DDRB_REG = Copy_u8Direction; break;
        case DIO_u8_PORTC: DIO_u8_DDRC_REG = Copy_u8Direction; break;
        case DIO_u8_PORTD: DIO_u8_DDRD_REG = Copy_u8Direction; break;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
        case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8Value; break;
        case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8Value; break;
        case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8Value; break;
        case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8Value; break;
    }
}
