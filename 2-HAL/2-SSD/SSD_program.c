/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************           SWC: SSD         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

static u8 seven_segment[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

void SSD_voidSSDInit(SSD_Configuration *Target_SSD)
{
	DIO_u8SetPortDirection(Target_SSD->Port, DIO_u8PORT_OUTPUT);
}


u8 SSD_u8SetNumber(SSD_Configuration *Target_SSD ,u8 Target_Number)
{
	u8 Local_u8ErrorState =0;
	if( (Target_SSD->CommonType <= COMMON_ANODE) && (Target_Number >= 0)   && (Target_Number<= 9)  )
	{
		if(Target_SSD->CommonType == COMMON_ANODE){
		DIO_u8SetPortValue(Target_SSD->Port, ~seven_segment[Target_Number]);}
		
		else if(Target_SSD->CommonType == COMMON_CATHODE){
		DIO_u8SetPortValue(Target_SSD->Port, seven_segment[Target_Number]);
		}
	}
	else{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState;
}



u8 SSD_u8DisableCommon(SSD_Configuration *Target_SSD)
{
	u8 Local_u8ErrorState =0;
	if( Target_SSD->CommonType <= COMMON_ANODE )
	{
		if(Target_SSD->CommonType == COMMON_ANODE){
		DIO_u8SetPortValue(Target_SSD->Port, DIO_u8PORT_HIGH);}
		
		else if(Target_SSD->CommonType == COMMON_CATHODE){
		DIO_u8SetPortValue(Target_SSD->Port, DIO_u8PORT_LOW);
		}
	}
	else{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState;
}
