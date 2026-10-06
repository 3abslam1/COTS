/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************           SWC: LED         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"


#define SINK_CONNECTION           0
#define SOURCE_CONNECTION         1

#define LED_u8PORTA               0
#define LED_u8PORTB               1
#define LED_u8PORTC               2
#define LED_u8PORTD               3
		
#define LED_u8PIN0                0
#define LED_u8PIN1                1
#define LED_u8PIN2                2
#define LED_u8PIN3                3
#define LED_u8PIN4                4
#define LED_u8PIN5                5
#define LED_u8PIN6                6
#define LED_u8PIN7                7
		
typedef struct
{
	u8 Port;
	u8 Pin;
	u8 ConnectionType;
		
}LED_configuration;

void LED_voidLEDInit(LED_configuration *target_LED);
u8 LED_u8LEDON(LED_configuration *target_LED);
u8 LED_u8LEDOFF(LED_configuration *target_LED);


#endif /* LED_INTERFACE_H_ */