/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************        SWC: IR Sensor      ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef   IR_INTERFACE_H_
#define   IR_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"


typedef struct
{
	u8 port;
	u8 pin;
	
}IRsensor_Configuration;

void IRsensor_voidInit(IRsensor_Configuration * target_Sensor);
u8   IRsensor_u8Read(IRsensor_Configuration * target_Sensor);


#endif /* IR_INTERFACE_H_ */