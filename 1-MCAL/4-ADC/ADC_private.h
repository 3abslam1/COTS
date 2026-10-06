/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: ADC         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define MaxChannel   7
#define MaxPrescaler 7



#define ADC_CH_MASK  0b11100000
#define ADC_PRE_MASK 0b11111000

#define ADMUX_REFS1   7  //REFS SELECTION BIT1
#define ADMUX_REFS0   6  //REFS SELECTION BIT0
#define ADMUX_ADLAR   5  //ADC LEFT ADJUST RESULT

#define ADCSRA_ADEN   7 //ADC ENABLE
#define ADCSRA_ADSC   6	//ADC START CONVERSION
#define ADCSRA_ADATE  5	//ADC AUTO TRIGGER ENABLE
#define ADCSRA_ADIF   4	//INTERRUPT FLAG
#define ADCSRA_ADIE   3	//INTERRUPT ENABLE
#define ADCSRA_ADPS2  2	//PRESCALER BIT2
#define ADCSRA_ADPS1  1	//PRESCALER BIT1
#define ADCSRA_ADPS0  0	//PRESCALER BIT0

 
static void voidHandleSingleConvAsynch(void);
static void voidHandleChainConvAsynch(void);

#endif /*ADC_PRIVATE_H_*/