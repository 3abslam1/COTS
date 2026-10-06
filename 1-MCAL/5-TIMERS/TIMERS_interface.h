/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************          SWC: TIMERS       ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef  TIMERS_INTERFACE_H_
#define  TIMERS_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_register.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"

#include "../GIE/GIE_interface.h"

void Timer0_voidInit(void);
void Timer1_voidInit(void);
void Timer2_voidInit(void);

u8 Timer0_u8SetCallBack( void(*Copy_pvCallBackFunc)(void) );
u8 Timer1_u8SetCallBack( void(*Copy_pvCallBackFunc)(void) );
u8 Timer2_u8SetCallBack( void(*Copy_pvCallBackFunc)(void));


void Timer0_voidSetLoadValue(u8 Copy_u8PreloadValue);
void Timer1_voidSetLoadValue(u8 Copy_u8PreloadValue);
void Timer2_voidSetLoadValue(u8 Copy_u8PreloadValue);

#endif /*TIMERS_INTERFACE_H_*/