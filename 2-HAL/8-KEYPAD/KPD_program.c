/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************         SWC: Keypad        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

void KPD_voidInit(void)
{
	DIO_u8SetPinDirection(KPD_PORT , KPD_COLUMN0_PIN , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_COLUMN1_PIN , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_COLUMN2_PIN , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_COLUMN3_PIN , DIO_u8PIN_OUTPUT);
	
	DIO_u8SetPinDirection(KPD_PORT , KPD_ROW0_PIN , DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_ROW1_PIN , DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_ROW2_PIN , DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT , KPD_ROW3_PIN , DIO_u8PIN_INPUT);
	
	DIO_u8SetPinValue(KPD_PORT , KPD_ROW0_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_ROW1_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_ROW2_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_ROW3_PIN , DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(KPD_PORT , KPD_COLUMN0_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_COLUMN1_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_COLUMN2_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT , KPD_COLUMN3_PIN , DIO_u8PIN_HIGH);
}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColumnIdx;
	u8 Local_u8RowIdx;
	
	u8 Local_u8PinState;
	
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	
	static u8 Local_u8KPDArr [ROW_NUM][COLUMN_NUM]= KPD_ARR_VAL;
	
	static u8 Local_u8KPDColumnArr [COLUMN_NUM] = {KPD_COLUMN0_PIN , KPD_COLUMN1_PIN , KPD_COLUMN2_PIN , KPD_COLUMN3_PIN};	
	static u8 Local_u8KPDROWArr    [ROW_NUM]    = {KPD_ROW0_PIN    , KPD_ROW1_PIN    , KPD_ROW2_PIN    , KPD_ROW3_PIN};	
	
for(Local_u8ColumnIdx=0 ; Local_u8ColumnIdx< COLUMN_NUM ; Local_u8ColumnIdx++ )
  {
		
		/*Activate current Column*/
		
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);
		
		for(Local_u8RowIdx=0 ; Local_u8RowIdx< ROW_NUM ; Local_u8RowIdx++ )
		{
         
		     /*Read The Current Row*/
		     DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIdx],&Local_u8PinState);
		     
			 /*Check If The Button Pressed*/
		     if(Local_u8PinState == DIO_u8PIN_LOW)
		     { 
				 Local_u8PressedKey= Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx]; 
			
				 
				 /*Busy Waiting until the key is released*/
				 
				 while(Local_u8PinState == DIO_u8PIN_LOW)
				     {
		                DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIdx],&Local_u8PinState);						 
					 }
			 }
			 
		 }	
		 	
		/*Deactivate current Column*/ 
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH); 
  }
  
	return Local_u8PressedKey;
}