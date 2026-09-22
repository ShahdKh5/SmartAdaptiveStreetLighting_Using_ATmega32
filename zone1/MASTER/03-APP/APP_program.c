#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../01-MCAL/00-LIB/STD_TYPES.h"
#include "../01-MCAL/01-DIO/DIO_interface.h"
#include "../01-MCAL/02-ADC/ADC_interface.h"
#include "../01-MCAL/03-TIMER/TIMER_interface.h"
#include "../01-MCAL/04-USART/USART_interface.h"
#include "../02-HAL/01-LCD/LCD_interface.h"
#include "../02-HAL/02-LDR/LDR_interface.h"
#include "../02-HAL/03-ULTRASONIC/ULTRASONIC_interface.h"
#include "../02-HAL/04-LED/LED_interface.h"
#include "../02-HAL/05-BUTTON/BUTTON_interface.h"
#include "APP_interface.h"
#include "LINK_protocol.h"

static const BUTTON_Config_t APP_strModeButton  = { DIO_u8_PORTB, DIO_u8_PIN0, BUTTON_PULL_UP };
static const BUTTON_Config_t APP_strZoneButton  = { DIO_u8_PORTB, DIO_u8_PIN1, BUTTON_PULL_UP };
static const BUTTON_Config_t APP_strLevelButton = { DIO_u8_PORTB, DIO_u8_PIN2, BUTTON_PULL_UP };

static const ULTRASONIC_Config_t APP_strZone1Ultrasonic =
    { DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_PORTD, DIO_u8_PIN6 };

#define APP_u8_ZONE2_STATUS_PORT   DIO_u8_PORTD
#define APP_u8_ZONE2_STATUS_PIN    DIO_u8_PIN4
#define APP_u8_ZONE3_STATUS_PORT   DIO_u8_PORTD
#define APP_u8_ZONE3_STATUS_PIN    DIO_u8_PIN5

#define APP_u8_MODE_AUTO    0
#define APP_u8_MODE_MANUAL  1

#define APP_u16_DETECT_RANGE_CM   20
#define APP_u8_HOLD_LOOPS         5

static u8  APP_u8Mode         = APP_u8_MODE_AUTO;
static u8  APP_u8ManualZone   = 0;
static u8  APP_u8ManualLevels[3] = {LED_u8_LEVEL_OFF, LED_u8_LEVEL_OFF, LED_u8_LEVEL_OFF};
static u8  APP_u8BroadcastIndex = 0;

static u8  APP_u8ModePrevState  = BUTTON_RELEASED;
static u8  APP_u8ZonePrevState  = BUTTON_RELEASED;
static u8  APP_u8LevelPrevState = BUTTON_RELEASED;

static u8  APP_u8Zone1Level      = LED_u8_LEVEL_OFF;
static u8  APP_u8Zone1Hold       = 0;

static u8  APP_u8Zone2Level = LED_u8_LEVEL_OFF;
static u8  APP_u8Zone3Level = LED_u8_LEVEL_OFF;

void APP_voidSystemInit(void)
{
    ADC_voidInit();
    LCD_voidInit();
    LDR_voidInit();
    LED_voidInit();
    USART_voidInit();
    BUTTON_voidInit(&APP_strModeButton);
    BUTTON_voidInit(&APP_strZoneButton);
    BUTTON_voidInit(&APP_strLevelButton);
    ULTRASONIC_voidInit(&APP_strZone1Ultrasonic);

    DIO_voidSetPinDirection(APP_u8_ZONE2_STATUS_PORT, APP_u8_ZONE2_STATUS_PIN, DIO_u8_INPUT);
    DIO_voidSetPinDirection(APP_u8_ZONE3_STATUS_PORT, APP_u8_ZONE3_STATUS_PIN, DIO_u8_INPUT);

    LCD_voidClearDisplay();
    LCD_voidGotoXY(1, 0);
    LCD_voidWriteString((u8*)"SMART STREET", 12);
    LCD_voidGotoXY(2, 0);
    LCD_voidWriteString((u8*)"LIGHT (3-MCU)", 13);
    _delay_ms(1000);
}

void APP_voidControlLighting(void)
{
    u8  Local_u8Night;
    u16 Local_u16Distance;
    u8  Local_u8StatusByte;
    u8  Local_u8Zone2Pin, Local_u8Zone3Pin;

    if (BUTTON_u8GetPressEvent(&APP_strModeButton, &APP_u8ModePrevState) == BUTTON_PRESSED)
    {
        APP_u8Mode = (APP_u8Mode == APP_u8_MODE_AUTO) ? APP_u8_MODE_MANUAL : APP_u8_MODE_AUTO;
        APP_voidUpdateDisplay();

    }

    if (APP_u8Mode == APP_u8_MODE_MANUAL)
    {
        if (BUTTON_u8GetPressEvent(&APP_strZoneButton, &APP_u8ZonePrevState) == BUTTON_PRESSED)
        {
            APP_u8ManualZone = (APP_u8ManualZone + 1) % 3;
            APP_voidUpdateDisplay();
        }
        if (BUTTON_u8GetPressEvent(&APP_strLevelButton, &APP_u8LevelPrevState) == BUTTON_PRESSED)
        {
            APP_u8ManualLevels[APP_u8ManualZone] = (APP_u8ManualLevels[APP_u8ManualZone] + 1) % 3;
            APP_voidUpdateDisplay();
        }
    }

    Local_u8Night = LDR_u8IsNight();

    if (APP_u8Mode == APP_u8_MODE_MANUAL)
    {
        APP_u8Zone1Level = APP_u8ManualLevels[LINK_u8_ZONE1];
        APP_u8Zone2Level = APP_u8ManualLevels[LINK_u8_ZONE2];
        APP_u8Zone3Level = APP_u8ManualLevels[LINK_u8_ZONE3];
        APP_u8Zone1Hold = 0;
        APP_u8Zone1WasDetect = 0;
    }
    else if (!Local_u8Night)
    {
        APP_u8Zone1Level = LED_u8_LEVEL_OFF;
        APP_u8Zone1Hold = 0;
        APP_u8Zone1WasDetect = 0;
    }
    else
    {
        /* قراءة المسافة */
        Local_u16Distance = ULTRASONIC_u16GetDistance(&APP_strZone1Ultrasonic);

        if (Local_u16Distance != 0 && Local_u16Distance < APP_u16_DETECT_RANGE_CM)
        {
            APP_u8Zone1Level = LED_u8_LEVEL_HIGH;
            APP_u8Zone1Hold = APP_u8_HOLD_LOOPS; /* شحن عداد الـ 3 ثواني */
        }
        else
        {
            /* تشغيل التأخير */
            if (APP_u8Zone1Hold > 0)
            {
                APP_u8Zone1Level = LED_u8_LEVEL_HIGH;
                APP_u8Zone1Hold--;
            }
            else
            {
                APP_u8Zone1Level = LED_u8_LEVEL_LOW;
            }
        }
    }
    LED_voidSetLevel(APP_u8Zone1Level);

    Local_u8StatusByte = 0;
    if (Local_u8Night)                          Local_u8StatusByte |= (1 << LINK_u8_NIGHT_BIT);
    if (APP_u8Mode == APP_u8_MODE_MANUAL)       Local_u8StatusByte |= (1 << LINK_u8_MANUAL_BIT);

    if (APP_u8Mode == APP_u8_MODE_MANUAL)
    {
        APP_u8BroadcastIndex = (APP_u8BroadcastIndex + 1) % 3;
        Local_u8StatusByte |= (u8)((APP_u8BroadcastIndex & LINK_u8_ZONE_MASK) << LINK_u8_ZONE_SHIFT);
        Local_u8StatusByte |= (u8)((APP_u8ManualLevels[APP_u8BroadcastIndex] & LINK_u8_LEVEL_MASK) << LINK_u8_LEVEL_SHIFT);
    }
    else
    {
        Local_u8StatusByte |= (u8)((APP_u8ManualZone & LINK_u8_ZONE_MASK) << LINK_u8_ZONE_SHIFT);
        Local_u8StatusByte |= (u8)((APP_u8ManualLevels[APP_u8ManualZone] & LINK_u8_LEVEL_MASK) << LINK_u8_LEVEL_SHIFT);
    }
    USART_voidSendByte(Local_u8StatusByte);

    if (APP_u8Mode != APP_u8_MODE_MANUAL)
    {
        if (!Local_u8Night)
        {
            APP_u8Zone2Level = LED_u8_LEVEL_OFF;
            APP_u8Zone3Level = LED_u8_LEVEL_OFF;
        }
        else
        {
            Local_u8Zone2Pin = DIO_voidGetPinValue(APP_u8_ZONE2_STATUS_PORT, APP_u8_ZONE2_STATUS_PIN);
            Local_u8Zone3Pin = DIO_voidGetPinValue(APP_u8_ZONE3_STATUS_PORT, APP_u8_ZONE3_STATUS_PIN);

            APP_u8Zone2Level = Local_u8Zone2Pin ? LED_u8_LEVEL_HIGH : LED_u8_LEVEL_LOW;
            APP_u8Zone3Level = Local_u8Zone3Pin ? LED_u8_LEVEL_HIGH : LED_u8_LEVEL_LOW;
        }
    }
}

/*
static u8 APP_u8EnergySavingPercent(void)
{
    u16 Local_u16Total = 0;
    u8  Local_u8Levels[3];
    u8  i;
    Local_u8Levels[0] = APP_u8Zone1Level;
    Local_u8Levels[1] = APP_u8Zone2Level;
    Local_u8Levels[2] = APP_u8Zone3Level;

    for (i = 0; i < 3; i++)
    {
        switch (Local_u8Levels[i])
        {
            case LED_u8_LEVEL_OFF:  Local_u16Total += 0;  break;
            case LED_u8_LEVEL_LOW:  Local_u16Total += 25; break;
            case LED_u8_LEVEL_HIGH: Local_u16Total += 90; break;
        }
    }
    return (u8)(100 - (Local_u16Total / 3));
}
*/

static u8 APP_u8ZoneLevelChar(u8 Copy_u8Level)
{
    switch (Copy_u8Level)
    {
        case LED_u8_LEVEL_LOW:  return 'L';
        case LED_u8_LEVEL_HIGH: return 'H';
        default:                return '-';
    }
}

void APP_voidUpdateDisplay(void)
{
    LCD_voidClearDisplay();

    LCD_voidGotoXY(1, 0);
    if (APP_u8Mode == APP_u8_MODE_MANUAL)
    {
        u8 Local_u8Buf[9];
        Local_u8Buf[0]='M';Local_u8Buf[1]='A';Local_u8Buf[2]='N';Local_u8Buf[3]='U';Local_u8Buf[4]='A';Local_u8Buf[5]='L';
        Local_u8Buf[6]=' ';Local_u8Buf[7]='Z';Local_u8Buf[8]=(u8)('1'+APP_u8ManualZone);
        LCD_voidWriteString(Local_u8Buf, 9);
    }
    else if (APP_u8Zone1Level==LED_u8_LEVEL_OFF && APP_u8Zone2Level==LED_u8_LEVEL_OFF && APP_u8Zone3Level==LED_u8_LEVEL_OFF)
    {
        LCD_voidWriteString((u8*)"DAY    AUTO", 11);
    }
    else
    {
        LCD_voidWriteString((u8*)"NIGHT  AUTO", 11);
    }

    LCD_voidGotoXY(2, 0);
    {
        u8 Local_u8Buf[14];
        Local_u8Buf[0]='Z';Local_u8Buf[1]='1';Local_u8Buf[2]=':';Local_u8Buf[3]=APP_u8ZoneLevelChar(APP_u8Zone1Level);
        Local_u8Buf[4]=' ';
        Local_u8Buf[5]='Z';Local_u8Buf[6]='2';Local_u8Buf[7]=':';Local_u8Buf[8]=APP_u8ZoneLevelChar(APP_u8Zone2Level);
        Local_u8Buf[9]=' ';
        Local_u8Buf[10]='Z';Local_u8Buf[11]='3';Local_u8Buf[12]=':';Local_u8Buf[13]=APP_u8ZoneLevelChar(APP_u8Zone3Level);
        LCD_voidWriteString(Local_u8Buf, 14);
    }
}
