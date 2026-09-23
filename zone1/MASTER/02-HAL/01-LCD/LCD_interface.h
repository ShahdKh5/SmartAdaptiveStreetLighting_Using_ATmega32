#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "../../01-MCAL/00-LIB/STD_TYPES.h"

void LCD_voidInit(void);
void LCD_voidSendInstruction(u8 Copy_u8instruction);
void LCD_voidWriteChar(u8 Copy_u8Data);
void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size);
void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column);
void LCD_voidClearDisplay(void);
void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column);

#endif
