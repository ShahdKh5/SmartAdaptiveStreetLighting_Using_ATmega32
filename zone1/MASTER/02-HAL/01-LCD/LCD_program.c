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
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_OUTPUT);

	DIO_voidSetPortDirection(LCD_u8_DATA_PORT,0xff);
	_delay_ms(30);
	LCD_voidSendInstruction(0b00111100);
	_delay_ms(2);
	LCD_voidSendInstruction(0b00001100);
	_delay_ms(2);
	LCD_voidSendInstruction(0b00000001);
	_delay_ms(2);
	LCD_voidSendInstruction(0b00000110);
	_delay_ms(2);
}

void LCD_voidSendInstruction(u8 Copy_u8instruction)
{
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8instruction);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

void LCD_voidWriteChar(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size)
{
	for(u8 i=0; i<Copy_u8Size; i++)
	{
		LCD_voidWriteChar(Copy_u8String[i]);
	}
}

void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	if( (Copy_u8Row == 1) && (Copy_u8Column < 16) )		
	{
		LCD_voidSendInstruction(0x80 + Copy_u8Column);	
	}
	else if( (Copy_u8Row == 2) && (Copy_u8Column < 16) )
	{
		LCD_voidSendInstruction(0xC0 + Copy_u8Column);	
	}
}

void LCD_voidClearDisplay(void)
{
	LCD_voidSendInstruction(0b00000001);
}

void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column)
{
	u8 Local_u8Adress=(Copy_u8PatternNumber*8);
	LCD_voidSendInstruction(Local_u8Adress+64);
	for (u8 i=0 ;i<8 ;i++)
	{
		LCD_voidWriteChar(Copy_u8Pattern[i]);
	}
	LCD_voidGotoXY(Copy_u8Row ,Copy_u8Column );
	LCD_voidWriteChar(Copy_u8PatternNumber); 
}
