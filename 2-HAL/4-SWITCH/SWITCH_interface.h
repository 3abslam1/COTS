/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************         SWC: SWITCH        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "..\..\LIB\STD_TYPE.h"
#include "..\..\MCAL\DIO\DIO_interface.h"


#define PULL_UP        1
#define PULL_DOWN      0

#define PRESSED        0
#define NOT_PRESSED    1

typedef struct{
	
	u8 Port;
	u8 Pin;
	u8 PullType;
	
	}SWITCH_Configuration;
	
	void SWITCH_voidInit(SWITCH_Configuration * Target_SWITCH);
	u8 SWITCH_u8GetSwitchState(SWITCH_Configuration * Target_SWITCH);



#endif /*SWITCH_INTERFACE_H_*/