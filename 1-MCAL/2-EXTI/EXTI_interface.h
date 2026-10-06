/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: EXTI        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/



#ifndef   EXTI_INTERFACE_H_
#define   EXTI_INTERFACE_H_


#define INT_LINE0    0
#define INT_LINE1    1
#define INT_LINE2    2


#define LOW_LEVEL    0
#define ON_CHANGE    1
#define FALLING_EDGE 2
#define RISING_EDGE  3


void EXTI_voidIntInit(void);

u8 EXTI_u8IntSetSenseControl(u8 Copy_INTline ,u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8INTline);
u8 EXTI_u8IntDisable(u8 Copy_INTline);

u8 EXTI_u8SetCallBack_INT0( void (*Copy_pvInt0Func)(void) );
u8 EXTI_u8SetCallBack_INT1( void (*Copy_pvInt1Func)(void) );
u8 EXTI_u8SetCallBack_INT2( void (*Copy_pvInt2Func)(void) );

#endif   /*EXTI_INTERFACE_H_*/