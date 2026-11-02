/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************         SWC: DC Motor      ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/



#include "DcMotor_interface.h"

void DCMOTOR_voidInit(DCMOTOR_Configuration * Target_Motor)
{
	DIO_u8SetPinDirection( Target_Motor->port , Target_Motor->pinx , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection( Target_Motor->port , Target_Motor->piny , DIO_u8PIN_OUTPUT);
}



void DCMOTOR_voidMove(DCMOTOR_Configuration * Target_Motor , u8 Motor_Rotation )
{

	if(Motor_Rotation == CLOCK_WISE)
	{
	    DIO_u8SetPinValue( Target_Motor->port , Target_Motor->pinx , DIO_u8PIN_HIGH);
	    DIO_u8SetPinValue( Target_Motor->port , Target_Motor->piny , DIO_u8PIN_LOW);
	}
	
	
	if(Motor_Rotation == COUNTER_CLOCK_WISE)
	{
		DIO_u8SetPinValue( Target_Motor->port , Target_Motor->pinx , DIO_u8PIN_LOW);
		DIO_u8SetPinValue( Target_Motor->port , Target_Motor->piny , DIO_u8PIN_HIGH);
	}
	
}



void DCMOTOR_voidStop(DCMOTOR_Configuration * Target_Motor)
{
		DIO_u8SetPinValue( Target_Motor->port , Target_Motor->pinx , DIO_u8PIN_LOW);
		DIO_u8SetPinValue( Target_Motor->port , Target_Motor->piny , DIO_u8PIN_LOW);	
}