/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: ADC         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/



#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

//ADC MUX SELECTION REGISTER
#define ADMUX         *((volatile u8*)0x27)



//ADC CONTROL & STATUS REGISTER
#define ADCSRA        *((volatile u8*)0x26)



//ADC HIGH REGISTER
#define ADCH          *((volatile u8*)0x25)



//ADC LOW REGISTER
#define ADCL          *((volatile u8*)0x24)





#endif /*ADC_REGISTER_H_*/