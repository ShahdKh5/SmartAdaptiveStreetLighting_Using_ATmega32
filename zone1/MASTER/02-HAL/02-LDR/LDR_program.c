#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "../../01-MCAL/02-ADC/ADC_interface.h"
#include "LDR_interface.h"

#define LDR_u8_PORT  			DIO_u8_PORTA
#define LDR_u8_PIN   			DIO_u8_PIN0
#define LDR_u8_ADC_CHANNEL      ADC_CHANNEL_0

#define LDR_u16_NIGHT_THRESHOLD 		500

void LDR_voidInit(void)
{
    DIO_voidSetPinDirection(LDR_u8_PORT, LDR_u8_PIN, DIO_u8_INPUT);
}

u8 LDR_u8IsNight(void)
{
    u16 Local_u16Reading = ADC_u16ReadSynchronus(LDR_u8_ADC_CHANNEL);
    return (Local_u16Reading > LDR_u16_NIGHT_THRESHOLD) ? LDR_u8_NIGHT : LDR_u8_DAY;
}
