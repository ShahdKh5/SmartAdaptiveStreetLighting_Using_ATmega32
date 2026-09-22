#ifndef    TIMER_INTERFACE_H
#define    TIMER_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

#define    NORMAL_MODE      			                            0
#define    PWM_OR_PHASE_COTROL                                      1
#define    CTC_MODE                                                 2
#define    FAST_PWM_MODE                                            3

#define    NON_PWM_NORMAL_PORT_OPRETATION                           0
#define    NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                      1
#define    NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                       2
#define    NON_PWM_SET_OC0_ON_COMPARE_MATCH						    3

#define    FAST_PWM_NORMAL_PORT_OPRETATION                          0
#define    FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP      1
#define    FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	  	2

#define    CLK_DIV_BY_0										 	    1
#define    CLK_DIV_BY_8										 	    2
#define    CLK_DIV_BY_64                                            3
#define    CLK_DIV_BY_256                                           4
#define    CLK_DIV_BY_1024                                          5
#define    ECS_ON_T0_FALLING_EDGE      								6
#define    ECS_ON_T0_RISING_EDGE       								7

#define	   RISING_EDGE												0
#define	   FALLING_EDGE												1

void TIMER_voidTimer0Init(void);
void TIMER_voidTimer1Init(void);
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue);
void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void));

void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue);
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue);
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue);

void ICU_voidInit(void);
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource);
u16 ICU_u16ReadInputCapture(void);
void ICU_voidInterruptDisbale(void);
void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void));

#endif
