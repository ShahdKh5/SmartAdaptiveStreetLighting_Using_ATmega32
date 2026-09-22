#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#define 	  WAVEFORM_GEN_MODE          FAST_PWM_MODE
#define 	  OC0_ACTION                 FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP

/*  CLK_DIV_BY_8 for standard Timer operation, or external clock source for counters */
#define 	 PRESCALER_TYPE     CLK_DIV_BY_8
#define 	 PRESCALER_MASK     0b11111000

#endif
