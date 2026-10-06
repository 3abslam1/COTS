/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************         SWC: SWITCH        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "..\..\LIB\STD_TYPE.h"
#include "..\..\MCAL\DIO\DIO_interface.h"

#include "SWITCH_config.h"
#include "SWITCH_interface.h"
#include "SWITCH_private.h"


void SWITCH_voidInit(SWITCH_Configuration * Target_SWITCH){
	DIO_u8SetPinDirection(Target_SWITCH->Port,Target_SWITCH->Pin,DIO_u8PIN_INPUT);
	
	if (Target_SWITCH->PullType == PULL_UP)
	{
		DIO_u8SetPinValue(Target_SWITCH->Port , Target_SWITCH->Pin , DIO_u8PIN_HIGH);
	}
	
}


u8 SWITCH_u8GetSwitchState(SWITCH_Configuration * Target_SWITCH){
	u8 Local_u8SwitchState = NOT_PRESSED;
	u8 Switch_Reading = DIO_u8PIN_LOW;
	
	DIO_u8GetPinValue(Target_SWITCH->Port , Target_SWITCH->Pin , &Switch_Reading);
	
	if (Switch_Reading == DIO_u8PIN_LOW && Target_SWITCH->PullType == PULL_UP)
	{
		Local_u8SwitchState= PRESSED;
	}
	
	if (Switch_Reading == DIO_u8PIN_HIGH && Target_SWITCH->PullType == PULL_DOWN)
	{
		Local_u8SwitchState= PRESSED;
	}
	
	_delay_ms(50);
	return Local_u8SwitchState;
}