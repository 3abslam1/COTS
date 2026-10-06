/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************          SWC: CLCD         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


void CLCD_voidSendCommand(u8 Copy_u8Command){
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN , DIO_u8PIN_LOW);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN , DIO_u8PIN_LOW);	
	
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN , DIO_u8PIN_LOW);
	
}

void CLCD_voidSendData(u8 Copy_u8Data){
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN , DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN , DIO_u8PIN_LOW);
	
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN , DIO_u8PIN_LOW);
	
}

void CLCD_voidInit(void){
	
	
	// Initialize CLCD DATA PORT
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	
	// Initialize CLCD CTRL PINS
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);	
	
/*Wait For more Than 30s*/	
_delay_ms(40);

/*Function Set Command For 2 Lines N=1 , Font 5*8 F=0*/
CLCD_voidSendCommand(CLCD_NoL2_Font5_8);

/*Display Enable D=1 C=0 B=0*/
CLCD_voidSendCommand(CLCD_DisplayOn_cursorOff_BlinkCoff);

/* Clear Display*/
CLCD_voidSendCommand(CLCD_ClearDisplay);

}



void CLCD_voidSendString(const char* Copy_pcString){
	u8 Local_u8Counter=0;
	
	while(Copy_pcString[Local_u8Counter]!= '\0'){
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
	
}


void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos){

u8 Local_u8Address;

	if(Copy_u8XPos==0){
		Local_u8Address= Copy_u8YPos;
	}
	if(Copy_u8XPos==1){
		Local_u8Address= 0x40+ Copy_u8YPos;
	}	
	CLCD_voidSendCommand(Local_u8Address+128);
	
}


void CLCD_voidWriteSpecialCharcter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber ,u8 Copy_u8XPos , u8 Copy_u8YPos){
	//Write inside CGRAM
	u8 Local_u8CGRAMAddress=0;
	
	//calculate CGRAM Address
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	
	//Send CGRAM address to LCD with setting bit6 , cleating bit 7
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);
	
	//Write the pattern into CGRAM
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator;Local_u8Iterator<8;Local_u8Iterator++)
	CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	
	//Display the value on screen access DDRAM
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	
	//Display the saved data in CGRAM
	CLCD_voidSendData(Copy_u8PatternNumber);
	
	
	
}



void CLCD_voidSendNumber(u16 Copy_u8No)
{
    u8 num[6];      
    u8 Counter = 0;

    if(Copy_u8No == 0)
    {
	    CLCD_voidSendData('0');
	    return;
    }
   else{
	   
    while(Copy_u8No > 0)
    {
	    num[Counter] = (Copy_u8No % 10) + '0';
	    Copy_u8No /= 10;
	    Counter++;
    }
	
	num[Counter]='\0';
	
        for(s8 LocalCounter= Counter-1 ; LocalCounter>=0 ; LocalCounter--)
		CLCD_voidSendData(num[LocalCounter]);

	}	
	
	
	
}




