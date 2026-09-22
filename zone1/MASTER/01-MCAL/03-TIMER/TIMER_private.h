#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define     TIM0_u8_TCCR0_REG		      *((volatile u8 *)(0x53))		
#define     TIM0_u8_TCCR0_FOC0            7								
#define     TIM0_u8_TCCR0_WGM00           6                             
#define     TIM0_u8_TCCR0_COM01           5                             
#define     TIM0_u8_TCCR0_COM00           4                             
#define     TIM0_u8_TCCR0_WGM01           3                             
#define     TIM0_u8_TCCR0_CS02            2                             
#define     TIM0_u8_TCCR0_CS01            1                             
#define     TIM0_u8_TCCR0_CS00            0                             

#define     TIM0_u8_TCNT0_REG		      *((volatile u8 *)(0x52))		
#define     TIM0_u8_OCR0_REG		      *((volatile u8 *)(0x5C))		

#define     TIM0_u8_TIMSK_REG		      *((volatile u8 *)(0x59))		
#define     TIM0_u8_TIMSK_TOIE0           0								
#define     TIM0_u8_TIMSK_OCIE0           1                             
#define		TIM0_u8_TIMSK_TOIE1		      2								
#define		TIM0_u8_TIMSK_OCIE1B	      3								
#define		TIM0_u8_TIMSK_OCIE1A	      4								
#define		TIM0_u8_TIMSK_TICIE1	      5								
#define     TIM0_u8_TIMSK_TOIE2           6								
#define     TIM0_u8_TIMSK_OCIE2           7								

#define     TIM0_u8_TIFR_REG              *((volatile u8 *)(0x58))		
#define     TIM0_u8_TIFR_TOV0             0								
#define     TIM0_u8_TIFR_OCF0             1                             
#define		TIM0_u8_TIFR_TOV1		      2								
#define		TIM0_u8_TIFR_OCF1B		      3								
#define		TIM0_u8_TIFR_OCF1A		      4								
#define		TIM0_u8_TIFR_ICF1		      5								
#define     TIM0_u8_TIFR_TOV2             6								
#define     TIM0_u8_TIFR_OCF2             7                             

#define		TIM1_u8_TCCR1A_REG			  *((volatile u8 *)(0x4F))		
#define     TIM1_u8_TCCR1A_WGM10	      0								
#define     TIM1_u8_TCCR1A_WGM11	      1								
#define     TIM1_u8_TCCR1A_FOC1B	      2								
#define     TIM1_u8_TCCR1A_FOC1A	      3								
#define     TIM1_u8_TCCR1A_COM1B0	      4								
#define     TIM1_u8_TCCR1A_COM1B1	      5								
#define     TIM1_u8_TCCR1A_COM1A0	      6								
#define     TIM1_u8_TCCR1A_COM1A1	      7								

#define		TIM1_u8_TCCR1B_REG			  *((volatile u8 *)(0x4E))		
#define     TIM1_u8_TCCR1B_CS10			  0								
#define     TIM1_u8_TCCR1B_CS11			  1								
#define     TIM1_u8_TCCR1B_CS12			  2								
#define     TIM1_u8_TCCR1B_WGM12 		  3								
#define     TIM1_u8_TCCR1B_WGM13		  4								
#define     TIM1_u8_TCCR1B_ICES1		  6								
#define     TIM1_u8_TCCR1B_ICNC1		  7								

#define		TIM1_u8_TCNT1L_REG			  *((volatile u8 *)(0x4C))		
#define		TIM1_u8_TCNT1H_REG			  *((volatile u8 *)(0x4D))		
#define		TIM1_u16_TCNT1_REG			  *((volatile u16 *)(0x4C))		

#define		TIM1_u8_OCR1AL_REG			  *((volatile u8 *)(0x4A))		
#define		TIM1_u8_OCR1AH_REG			  *((volatile u8 *)(0x4B))		
#define     TIM1_u16_OCR1A_REG			  *((volatile u16 *)(0x4A))		

#define		TIM1_u8_OCR1BL_REG			  *((volatile u8 *)(0x48))		
#define		TIM1_u8_OCR1BH_REG			  *((volatile u8 *)(0x49))		
#define     TIM1_u16_OCR1B_REG			  *((volatile u16 *)(0x48))		

#define		TIM1_u8_ICR1L_REG			  *((volatile u8 *)(0x46))		
#define		TIM1_u8_ICR1H_REG			  *((volatile u8 *)(0x47))		
#define     TIM1_u16_ICR1_REG			  *((volatile u16 *)(0x46))		

#endif
