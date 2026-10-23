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

#define ACTIVE_LOW    0
#define ACTIVE_HIGH   1

#define OBJECT        0
#define NO_OBJECT     1


typedef struct
{
	u8 Port;
	u8 Pin;
	u8 SensorType;
	
}IRsensor_Configuration;

void IRsensor_voidInit(IRsensor_Configuration * Target_Sensor);
u8   IRsensor_u8Read(IRsensor_Configuration * Target_Sensor);


#endif /* IR_INTERFACE_H_ */