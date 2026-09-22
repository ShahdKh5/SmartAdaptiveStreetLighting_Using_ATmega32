#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

#define EXTI_u8_EXTI0                0
#define EXTI_u8_EXTI1                1
#define EXTI_u8_EXTI2                2

#define EXTI_u8_LOW_LEVEL            0
#define EXTI_u8_ANY_LOGICAL_CHANGE   1
#define EXTI_u8_FALLING_EDGE         2 
#define EXTI_u8_RISING_EDGE          3

void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense);
void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo);
void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex);

#endif
