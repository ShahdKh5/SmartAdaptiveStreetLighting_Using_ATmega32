#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(void)
{
	/* Configure Voltage Reference */
	#if ADC_REFVOLT == ADC_AVCC
		ADC_u8_ADMUX_REG = 0;
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
	#elif ADC_REFVOLT == ADC_INTERNAL
		ADC_u8_ADMUX_REG = 0;
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1);
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
	#elif ADC_REFVOLT == ADC_AREF
		ADC_u8_ADMUX_REG = 0;
	#endif

	/* Configure Left / Right Adjustment */
	#if ADC_ADJUST_CTRL == LEFT
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR);
	#elif ADC_ADJUST_CTRL == RIGHT
		CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR);
	#endif

	/* Configure Prescaler & Enable ADC */
	ADC_u8_ADCSRA_REG = (ADC_PRESCALAR_VAL & 0x07);
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADEN);
}

u16 ADC_u16ReadSynchronus(u8 Copy_u8Channel)
{
	/* Select analog channel (0 to 7) without clearing REFS or ADLAR bits */
	ADC_u8_ADMUX_REG = (ADC_u8_ADMUX_REG & ADC_CHANNEL_MASK) | (Copy_u8Channel & 0x07);

	/* Start conversion */
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC);

	/* Wait for conversion to complete */
	while (GET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC));

	/* Return result based on alignment configuration */
	#if ADC_ADJUST_CTRL == RIGHT
		return ADC_u16_ADC_REG;
	#elif ADC_ADJUST_CTRL == LEFT
		return (ADC_u16_ADC_REG >> 6);
	#endif
}
