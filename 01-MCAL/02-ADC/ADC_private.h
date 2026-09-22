#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADC Registers */
#define 	ADC_u8_ADMUX_REG   		*((volatile u8 *)0x27)
#define     ADC_u8_ADMUX_MUX0       0
#define     ADC_u8_ADMUX_MUX1       1
#define     ADC_u8_ADMUX_MUX2       2
#define     ADC_u8_ADMUX_MUX3       3
#define     ADC_u8_ADMUX_MUX4       4
#define     ADC_u8_ADMUX_ADLAR      5
#define     ADC_u8_ADMUX_REFS0      6
#define     ADC_u8_ADMUX_REFS1      7

#define 	ADC_u8_ADCSRA_REG  		*((volatile u8 *)0x26)
#define     ADC_u8_ADCSRA_ADPS0     0
#define     ADC_u8_ADCSRA_ADPS1     1
#define     ADC_u8_ADCSRA_ADPS2     2
#define     ADC_u8_ADCSRA_ADIE      3
#define     ADC_u8_ADCSRA_ADIF      4
#define     ADC_u8_ADCSRA_ADATE     5
#define     ADC_u8_ADCSRA_ADSC      6
#define     ADC_u8_ADCSRA_ADEN      7

#define     ADC_u8_ADCH_REG         *((volatile u8 *)0x25)
#define     ADC_u8_ADCL_REG         *((volatile u8 *)0x24)
#define 	ADC_u16_ADC_REG     	*((volatile u16*)0x24)

/* Reference Voltage Options */
#define		ADC_AREF	  0
#define     ADC_AVCC      1
#define     ADC_INTERNAL  3

/* Alignment Options */
#define     LEFT		  1
#define     RIGHT         0

/* Prescaler Options */
#define 	ADC_PRESCALAR_BY_2       1
#define 	ADC_PRESCALAR_BY_4       2
#define 	ADC_PRESCALAR_BY_8       3
#define 	ADC_PRESCALAR_BY_16      4
#define 	ADC_PRESCALAR_BY_32      5
#define 	ADC_PRESCALAR_BY_64      6
#define 	ADC_PRESCALAR_BY_128     7

/* Bitwise Masks */
#define		ADC_PRES_MASK		0b11111000
#define		ADC_CHANNEL_MASK	0b11100000

/* Driver Status */
#define		NOTBUSY			0
#define		BUSY			1

#endif
