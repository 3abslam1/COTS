/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************        SWC: IR Sensor      ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "IRsensor_interface.h"



void IRsensor_voidInit(IRsensor_Configuration * target_Sensor)
{
	DIO_u8SetPinDirection(target_Sensor->port , target_Sensor->pin , DIO_u8PIN_INPUT);
}



u8   IRsensor_u8Read(IRsensor_Configuration * target_Sensor)
{
	u8 Sensor_Value = 0;
	DIO_u8GetPinValue(target_Sensor->port , target_Sensor->pin , &Sensor_Value);
	return Sensor_Value;
}