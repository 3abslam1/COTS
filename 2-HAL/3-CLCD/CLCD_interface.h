/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************          SWC: CLCD         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>


#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"



void CLCD_voidSendCommand(u8 Copy_u8Command);
		  
void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos);

void CLCD_voidWriteSpecialCharcter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber ,u8 Copy_u8XPos , u8 Copy_u8YPos);

void CLCD_voidSendNumber(u16 num);



#endif    /* CLCD_INTERFACE_H_*/