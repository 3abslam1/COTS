/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: ADC         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/




#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"

#define ADC_DISABLE             0
#define ADC_ENABLE              1


#define INT_DISABLE             0
#define INT_ENABLE              1



#define ADC_8Bits               0
#define ADC_10Bits              1


#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3


#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1


#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7


#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7

#define SINGLE_ASYNCH           0
#define CHAIN_ASYNCH            1

typedef struct{
   
   u8 ChainSize;
   u8*ChannelArr;
   u16*ResultArr;
   void(*NotificationFunc)(void);
	
	}ADC_Chain_t;


void ADC_voidInit(void);

u8   ADC_u8StartSingleConversionSynch(u8 Copy_u8Channel ,  u16* Copy_pu16Reading);

u8   ADC_u8StartSingleConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) );
u8   ADC_u8StartChainConversionAsynch( const ADC_Chain_t* Copy_Object );


void ADC_voidEnable           (void);
void ADC_voidDisable          (void);
void ADC_voidInterruptEnable  (void);
void ADC_voidInterruptDisable (void);

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler);






#endif /*ADC_INTERFACE_H_*/