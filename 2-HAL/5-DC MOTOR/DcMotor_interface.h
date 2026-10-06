/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************         SWC: DC Motor      ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef   DCMOTOR_INTERFACE_H_
#define   DCMOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"


#define CLOCK_WISE             1
#define COUNTER_CLOCK_WISE     2

typedef struct
{
	u8 port;
	u8 pinx;
	u8 piny;
}DCMOTOR_Configuration;

void DCMOTOR_voidInit(DCMOTOR_Configuration * target_Motor);
void DCMOTOR_voidMove(DCMOTOR_Configuration * target_Motor , u8 Motor_Rotation );
void DCMOTOR_voidStop(DCMOTOR_Configuration * target_Motor);

#endif /* DCMOTOR_INTERFACE_H_ */