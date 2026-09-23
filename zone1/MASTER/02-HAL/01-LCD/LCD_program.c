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

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_LOW);
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_LOW);
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);

    _delay_ms(30);

    LCD_voidSendInstruction(LCD_u8_CMD_FUNCTION_SET);

    LCD_voidSendInstruction(LCD_u8_CMD_DISPLAY_ON);

    LCD_voidSendInstruction(LCD_u8_CMD_CLEAR_DISPLAY);

    LCD_voidSendInstruction(LCD_u8_CMD_ENTRY_MODE);

    _delay_ms(2);
}
void LCD_voidSendInstruction(u8 Copy_u8instruction)
{

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_LOW);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN, DIO_u8_LOW);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);

    DIO_voidSetPortValue( LCD_u8_DATA_PORT,Copy_u8instruction);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_HIGH);

    _delay_us(10);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);


    _delay_ms(2);
}
void LCD_voidWriteChar(u8 Copy_u8Data)
{
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RSPIN, DIO_u8_HIGH);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RWPIN,DIO_u8_LOW);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);

    DIO_voidSetPortValue(LCD_u8_DATA_PORT, Copy_u8Data);
    
    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_HIGH);

    _delay_us(10);

    DIO_voidSetPinValue(LCD_u8_CTRL_PORT, LCD_u8_EPIN, DIO_u8_LOW);

    _delay_us(50);
}


void LCD_voidWriteString(u8 *Copy_u8String)
{
    u8 i = 0;
    while (Copy_u8String[i] != '\0')
    {
        LCD_voidWriteChar(Copy_u8String[i]);
        i++;
    }
}


void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
    if ((Copy_u8Row == 1) && (Copy_u8Column < 16))
    {
        LCD_voidSendInstruction(LCD_u8_ROW1_BASE_ADDR + Copy_u8Column);
    }
    else if ((Copy_u8Row == 2) && (Copy_u8Column < 16))
    {
        LCD_voidSendInstruction(LCD_u8_ROW2_BASE_ADDR + Copy_u8Column);
    }
    else
    {

    }
}


void LCD_voidClearDisplay(void)
{
    LCD_voidSendInstruction(LCD_u8_CMD_CLEAR_DISPLAY);
}


void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8Row, u8 Copy_u8Column)
{
    u8 Local_u8Adress = Copy_u8PatternNumber * LCD_u8_PATTERN_SIZE;

    LCD_voidSendInstruction(Local_u8Adress + LCD_u8_CGRAM_BASE_ADDR);

    for (u8 i = 0; i < LCD_u8_PATTERN_SIZE; i++)
    {
        LCD_voidWriteChar(Copy_u8Pattern[i]);
    }

    LCD_voidGotoXY(Copy_u8Row, Copy_u8Column);

    LCD_voidWriteChar(Copy_u8PatternNumber);
}
