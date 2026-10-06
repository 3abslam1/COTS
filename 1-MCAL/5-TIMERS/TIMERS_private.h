/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************          SWC: TIMERS       ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef  TIMERS_PRIVATE_H_
#define  TIMERS_PRIVATE_H_

#define TIMER_NORMAL_MODE                               0
#define TIMER_PWM_PHASE_CORRECT_MODE                    1
#define TIMER_CCT_MODE                                  2
#define TIMER_FAST_PWM_MODE                             3


#define TIMER_NO_CLOCK_SOURCE	 	                    0
#define TIMER_NO_PRESCALER_FACTOR 	                    1
#define TIMER_PRESCALER_8   	                        2
#define TIMER_PRESCALER_64                              3
#define TIMER_PRESCALER_256 	                        4
#define TIMER_PRESCALER_1024	                        5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7



#define TIMER_PRESCALER_MASK					        0b11111000

#endif /*TIMERS_PRIVATE_H_*/