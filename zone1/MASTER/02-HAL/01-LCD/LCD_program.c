#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>

#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/00-LIB/BIT_MATH.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidInit(void)
{
    DIO_voidSetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_OUTPUT);

    DIO_voidSetPortDirection(LCD_u8_DATA_PORT, 0xFF);

    /* Initial state */
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_LOW);
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_LOW);
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);

    /* LCD power-up delay */
    _delay_ms(30);

    /* 8-bit mode, 2 lines, 5x8 font */
    LCD_voidSendInstruction(0x38);

    /* Display ON, Cursor OFF, Blink OFF */
    LCD_voidSendInstruction(0x0C);

    /* Clear display */
    LCD_voidSendInstruction(0x01);

    /* Increment cursor */
    LCD_voidSendInstruction(0x06);

    _delay_ms(2);
}


void LCD_voidSendInstruction(u8 Copy_u8instruction)
{
    /* RS = 0 -> Command */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_RSPIN,
        DIO_u8_LOW
    );

    /* RW = 0 -> Write */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_RWPIN,
        DIO_u8_LOW
    );

    /* E = LOW before changing data */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_LOW
    );

    /* Put command on data pins */
    DIO_voidSetPortValue(
        LCD_u8_DATA_PORT,
        Copy_u8instruction
    );

    /* Enable pulse */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_HIGH
    );

    _delay_us(10);

    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_LOW
    );

    /* Command execution time */
    _delay_ms(2);
}


void LCD_voidWriteChar(u8 Copy_u8Data)
{
    /* RS = 1 -> Data */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_RSPIN,
        DIO_u8_HIGH
    );

    /* RW = 0 -> Write */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_RWPIN,
        DIO_u8_LOW
    );

    /* E = LOW before changing data */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_LOW
    );

    /* Put data on data pins */
    DIO_voidSetPortValue(
        LCD_u8_DATA_PORT,
        Copy_u8Data
    );

    /* Enable pulse */
    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_HIGH
    );

    _delay_us(10);

    DIO_voidSetPinValue(
        LCD_u8_CTRL_PORT,
        LCD_u8_EPIN,
        DIO_u8_LOW
    );

    /* Character execution time */
    _delay_us(50);
}


void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size)
{
    for (u8 i = 0; i < Copy_u8Size; i++)
    {
        LCD_voidWriteChar(Copy_u8String[i]);
    }
}


void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
    if ((Copy_u8Row == 1) && (Copy_u8Column < 16))
    {
        LCD_voidSendInstruction(0x80 + Copy_u8Column);
    }
    else if ((Copy_u8Row == 2) && (Copy_u8Column < 16))
    {
        LCD_voidSendInstruction(0xC0 + Copy_u8Column);
    }
}


void LCD_voidClearDisplay(void)
{
    LCD_voidSendInstruction(0x01);

    _delay_ms(2);
}


void LCD_voidWriteSpecialChar(
    u8 *Copy_u8Pattern,
    u8 Copy_u8PatternNumber,
    u8 Copy_u8Row,
    u8 Copy_u8Column
)
{
    u8 Local_u8Adress = Copy_u8PatternNumber * 8;

    /* Set CGRAM address */
    LCD_voidSendInstruction(Local_u8Adress + 0x40);

    /* Write pattern */
    for (u8 i = 0; i < 8; i++)
    {
        LCD_voidWriteChar(Copy_u8Pattern[i]);
    }

    /* Return to DDRAM */
    LCD_voidGotoXY(Copy_u8Row, Copy_u8Column);

    /* Display custom character */
    LCD_voidWriteChar(Copy_u8PatternNumber);
}
