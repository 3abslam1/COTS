/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************        SWC: IR Sensor      ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "IRsensor_interface.h"



void IRsensor_voidInit(IRsensor_Configuration * Target_Sensor)
{
	DIO_u8SetPinDirection(Target_Sensor->Port , Target_Sensor->Pin , DIO_u8PIN_INPUT);
}



u8   IRsensor_u8Read(IRsensor_Configuration * Target_Sensor)
{
		u8 Local_u8IRsensorState = NO_OBJECT;
		u8 Sensor_Value = DIO_u8PIN_LOW;
		
	    DIO_u8GetPinValue(Target_Sensor->Port , Target_Sensor->Pin , &Sensor_Value);
		
			
		if (Sensor_Value == DIO_u8PIN_LOW && Target_Sensor->SensorType == ACTIVE_LOW)
		{
			Local_u8IRsensorState= OBJECT;
		}
		
		if (Sensor_Value == DIO_u8PIN_HIGH && Target_Sensor->SensorType == ACTIVE_HIGH)
		{
			Local_u8IRsensorState= OBJECT;
		}
		
	

	    return Sensor_Value;
}