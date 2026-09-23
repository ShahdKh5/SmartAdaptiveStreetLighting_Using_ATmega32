#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_interface.h"
#include "../../01-MCAL/03-TIMER/TIMER1_interface.h"
#include "ULTRASONIC_interface.h"

/* Simple polling-based measurement (no ICU/interrupt needed): trigger the
   sensor, wait for its own Echo to rise, then time how long it stays HIGH
   in 1us steps. Timeout protects the loop if no echo ever returns. */
#define ULTRASONIC_u32_TIMEOUT_US   30000UL   /* ~5 m round trip */

void ULTRASONIC_voidInit(const ULTRASONIC_Config_t *Copy_pstrConfig)
{
    DIO_voidSetPinDirection(Copy_pstrConfig->TrigPort, Copy_pstrConfig->TrigPin, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(Copy_pstrConfig->EchoPort, Copy_pstrConfig->EchoPin, DIO_u8_INPUT);
    DIO_voidSetPinValue(Copy_pstrConfig->TrigPort, Copy_pstrConfig->TrigPin, DIO_u8_LOW);
}

void ULTRASONIC_voidTrigger(const ULTRASONIC_Config_t *Copy_pstrConfig)
{
    DIO_voidSetPinValue(Copy_pstrConfig->TrigPort, Copy_pstrConfig->TrigPin, DIO_u8_HIGH);
    _delay_us(10);
    DIO_voidSetPinValue(Copy_pstrConfig->TrigPort, Copy_pstrConfig->TrigPin, DIO_u8_LOW);
}

u16 ULTRASONIC_u16GetDistance(const ULTRASONIC_Config_t *Copy_pstrConfig)
{
    u16 Local_u16EchoTime = 0;
    u32 Local_u32Timeout = 0;

    ULTRASONIC_voidTrigger(Copy_pstrConfig);

    /* 1. Timer initialization, edge select (rising edge), and flag clearing */
    TIMER1_voidInit();
    TIMER1_voidSetICUEdgeTrigger(TIMER1_ICU_RISING_EDGE);
    TIMER1_voidClearICUFlag();

    /* 2. Wait for rising edge */
    while (TIMER1_u8GetICUFlag() == 0)
    {
        Local_u32Timeout++;
        if (Local_u32Timeout > 100000UL) { TIMER1_voidStop(); return 999; }
    }

    /* 3. Reset the counter, change capture to falling edge, and clear the flag */
    TIMER1_voidSetTimerValue(0);
    TIMER1_voidSetICUEdgeTrigger(TIMER1_ICU_FALLING_EDGE);
    TIMER1_voidClearICUFlag();

    /* 4. Wait for falling edge */
    Local_u32Timeout = 0;
    while (TIMER1_u8GetICUFlag() == 0)
    {
        Local_u32Timeout++;
        if (Local_u32Timeout > 100000UL) { TIMER1_voidStop(); return 999; }
    }

    /* 5. Read time and stop timer */
    Local_u16EchoTime = TIMER1_u16GetICUValue();
    TIMER1_voidStop();

    return (Local_u16EchoTime / 58);
}

u16 ULTRASONIC_u16GetFilteredDistance(const ULTRASONIC_Config_t *Copy_pstrConfig)
{
    u16 Local_u16Readings[5];
    u16 Local_u16Sum = 0;
    u16 Local_u16Max = 0;
    u16 Local_u16Min = 0xFFFF; /* A very large number so that the first reading is the smallest */
    u8 i;

    /* 1. Take 5 consecutive readings */
    for (i = 0; i < 5; i++)
    {
        Local_u16Readings[i] = ULTRASONIC_u16GetDistance(Copy_pstrConfig);
        Local_u16Sum += Local_u16Readings[i];

        /* 2. Find the maximum value */
        if (Local_u16Readings[i] > Local_u16Max)
        {
            Local_u16Max = Local_u16Readings[i];
        }

        /* 3. Find the minimum value */
        if (Local_u16Readings[i] < Local_u16Min)
        {
            Local_u16Min = Local_u16Readings[i];
        }

        /* Very short delay between readings to give the sensor time to send the wave */
        _delay_ms(5);
    }

    /* 4. Subtract the maximum and minimum values from the sum, and divide the remainder by 3 */
    Local_u16Sum = Local_u16Sum - Local_u16Max - Local_u16Min;

    return (Local_u16Sum / 3);
}
