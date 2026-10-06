/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************          SWC: TIMERS       ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "TIMERS_interface.h"


static void (*Timer0_pvCallBackFunc)  (void) = NULL;





void Timer0_voidInit(void)
{
	/*Set Mode*/
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	
#endif
	
	/*Set PRESCALER*/	
#if TIMER0_PRESCALER == TIMER_PRESCALER_256
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
	
#endif


	/*Set PRELoad Value*/
    TCNT0=220u;
	
	/*Enable Overflow interrupts*/	
	SET_BIT(TIMSK,TIMSK_TOIE0);		
	
	GIE_voidEnable();
}


u8 Timer0_u8SetCallBack( void(*Copy_pvCallBackFunc)(void) )
{
	u8 Local_u8ErrorState = OK;
	
	if (*Copy_pvCallBackFunc!=NULL)
	{
	    Timer0_pvCallBackFunc= Copy_pvCallBackFunc;
	}
    
	else Local_u8ErrorState = NULL_POINTER;
	
	
	return Local_u8ErrorState;
}


void Timer0_voidSetLoadValue(u8 Copy_u8PreloadValue)
{
	TCNT0= Copy_u8PreloadValue;
}



/*Timer0 OverFlow ISR*/
void __vector_11(void) __attribute__( (signal) );
void __vector_11(void)
{
	
	if (*Timer0_pvCallBackFunc!=NULL)
	{
		Timer0_pvCallBackFunc();
	}	
	
}