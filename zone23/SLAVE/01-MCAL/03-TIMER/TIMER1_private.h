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
#define CS11    1

/* TIFR Bits */
#define ICF1    5

#endif
