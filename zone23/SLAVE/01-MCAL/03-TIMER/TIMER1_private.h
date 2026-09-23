#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

/* Timer1 Registers Memory Mapping */
#define TCCR1A  *((volatile u8 *)0x4F)
#define TCCR1B  *((volatile u8 *)0x4E)

/* 16-bit Registers */
#define TCNT1   *((volatile u16*)0x4C)
#define ICR1    *((volatile u16*)0x46)

#define TIFR    *((volatile u8 *)0x58)

/* TCCR1B Bits */
#define ICES1   6
#define CS10    0
#define CS11    1
#define CS12    2

/* TIFR Bits */
#define ICF1    5

/* Prescaler Options */
#define TIMER1_NO_CLOCK            0
#define TIMER1_PRESCALER_1         1
#define TIMER1_PRESCALER_8         2
#define TIMER1_PRESCALER_64        3
#define TIMER1_PRESCALER_256       4
#define TIMER1_PRESCALER_1024      5
#define TIMER1_EXT_CLOCK_FALLING   6
#define TIMER1_EXT_CLOCK_RISING    7

#define TIMER1_PRESCALER_MASK      0xF8

#endif
