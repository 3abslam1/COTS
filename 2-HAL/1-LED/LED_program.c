/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************           SWC: LED         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidLEDInit(LED_configuration *target_LED)
{
	DIO_u8SetPinDirection(target_LED->Port, target_LED->Pin, DIO_u8PIN_OUTPUT);
}


u8 LED_u8LEDON(LED_configuration *target_LED)
{
	u8 Local_u8ErrorState =0;
	if(target_LED->ConnectionType <= SOURCE_CONNECTION)
	{
		if(target_LED->ConnectionType == SINK_CONNECTION){
		DIO_u8SetPinValue(target_LED->Port, target_LED->Pin, DIO_u8PIN_LOW);}
		
		else if(target_LED->ConnectionType == SOURCE_CONNECTION){
			DIO_u8SetPinValue(target_LED->Port, target_LED->Pin, DIO_u8PIN_HIGH);
		}
	}
	else{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState;
}

u8 LED_u8LEDOFF(LED_configuration *target_LED)
{
	u8 Local_u8ErrorState =0;
	if(target_LED->ConnectionType <= SOURCE_CONNECTION)
	{
		if(target_LED->ConnectionType == SINK_CONNECTION){
		DIO_u8SetPinValue(target_LED->Port, target_LED->Pin, DIO_u8PIN_HIGH);}
		
		else if(target_LED->ConnectionType == SOURCE_CONNECTION){
			DIO_u8SetPinValue(target_LED->Port, target_LED->Pin, DIO_u8PIN_LOW);
		}
	}
	else{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState;
}
