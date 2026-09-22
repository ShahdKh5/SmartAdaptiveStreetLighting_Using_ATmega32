#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

void (* TIMER_pvTimer0NotificationFunction)(void) = NULL; 
void (* TIMER_pvICUNotificationFunction)(void) = NULL;

void TIMER_voidTimer0Init(void)
{
	#if WAVEFORM_GEN_MODE == NORMAL_MODE
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

	#elif WAVEFORM_GEN_MODE == PWM_OR_PHASE_COTROL
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

	#elif WAVEFORM_GEN_MODE == CTC_MODE
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION:				
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH:	        
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	        
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_SET_OC0_ON_COMPARE_MATCH:	            
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		default: break;
	}

	#elif WAVEFORM_GEN_MODE == FAST_PWM_MODE
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
	case FAST_PWM_NORMAL_PORT_OPRETATION:						
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP:	
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP:	
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	default: break;
	}
	#endif

	TIM0_u8_TCCR0_REG &= PRESCALER_MASK;
	TIM0_u8_TCCR0_REG |= PRESCALER_TYPE;
}

void TIMER_voidTimer1Init(void)
{
	/* Select The Normal Mode for Counter use */
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);

    /* Use external clock on T1 pin (falling edge) */
    TIM1_u8_TCCR1B_REG &= PRESCALER_MASK;
    TIM1_u8_TCCR1B_REG |= ECS_ON_T0_FALLING_EDGE; 
}

void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue)
{
	TIM0_u8_OCR0_REG = Copy_u8CompareValue;
}

void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	TIMER_pvTimer0NotificationFunction = Copy_pvNotificationFunction;
}

void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue)
{
	TIM1_u16_OCR1A_REG = Copy_u16CompareValue;
}

void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue)
{
	TIM1_u16_OCR1B_REG = Copy_u16CompareValue;
}

void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue)
{
	TIM1_u16_ICR1_REG = Copy_u16CaptureValue;
}

void ICU_voidInit(void)
{
	SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_TCCR1B_ICES1);
	SET_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

void ICU_voidSetTrigger(u8 Copy_u8TriggerSource)
{
	switch(Copy_u8TriggerSource)
	{
		case RISING_EDGE:
			SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		case FALLING_EDGE:
			CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		default:
			break;
	}
}

u16 ICU_u16ReadInputCapture(void)
{
	return TIM1_u16_ICR1_REG;
}

void ICU_voidInterruptDisbale(void)
{
	CLR_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	TIMER_pvICUNotificationFunction = Copy_pvNotificationFunction;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER_pvTimer0NotificationFunction != NULL)
	{
		TIMER_pvTimer0NotificationFunction();
	}
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER_pvICUNotificationFunction != NULL)
	{
		TIMER_pvICUNotificationFunction();
	}
}
