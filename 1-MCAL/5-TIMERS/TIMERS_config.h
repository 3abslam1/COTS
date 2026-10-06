/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************          SWC: TIMERS       ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef  TIMERS_CONFIG_H_
#define  TIMERS_CONFIG_H_


/* Options
   1-TIMER_NORMAL_MODE                      
   2-TIMER_PWM_PHASE_CORRECT_MODE              
   3-TIMER_CCT_MODE                            
   4-TIMER_FAST_PWM_MODE                           
*/
#define  TIMER0_WAVEFORM_GENERATION_MODE        TIMER_NORMAL_MODE
#define  TIMER2_WAVEFORM_GENERATION_MODE        TIMER_NORMAL_MODE



/* Options
   1-TIMER_NO_CLOCK_SOURCE	 	        
   2-TIMER_NO_PRESCALER_FACTOR 	           
   3-TIMER_PRESCALER_8   	               
   4-TIMER_PRESCALER_64                     
   5-TIMER_PRESCALER_256 	               
   6-TIMER_PRESCALER_1024	               
   7-TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING   
   8-TIMER0_T0_EXTERNAL_CLOCK_SOURCE_RISING	   
*/
#define TIMER0_PRESCALER    TIMER_PRESCALER_256
#define TIMER1_PRESCALER    TIMER_PRESCALER_256
#define TIMER2_PRESCALER    TIMER_PRESCALER_256




#endif /*TIMERS_CONFIG_H_*/