/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************           SWC: SSD         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"



#define COMMON_CATHODE            0
#define COMMON_ANODE              1

#define SSD_u8PORTA               0
#define SSD_u8PORTB               1
#define SSD_u8PORTC               2
#define SSD_u8PORTD               3

#define SSD_u8PIN0                0
#define SSD_u8PIN1                1
#define SSD_u8PIN2                2
#define SSD_u8PIN3                3
#define SSD_u8PIN4                4
#define SSD_u8PIN5                5
#define SSD_u8PIN6                6
#define SSD_u8PIN7                7

typedef struct
{
	u8 Port;
	u8 CommonType;
	
}SSD_configuration;

void SSD_voidSSDInit(SSD_configuration *target_SSD);
u8 SSD_u8SetNumber(SSD_configuration *target_SSD ,u8 target_number);
u8 SSD_u8DisableCommon(SSD_configuration *target_SSD);


#endif /* SSD_INTERFACE_H_ */