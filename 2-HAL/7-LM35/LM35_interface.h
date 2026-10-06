/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************          SWC: LM35         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/



#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

typedef struct
{
	u8 Copy_u8LM35Channel ;
	u8 Copy_u8ADCVoltageReference ;
} LM35_configuration ;


void LM35_voidGetTemp (LM35_configuration * lm35 , u8 * Copy_u8TempValue) ;

#endif

























