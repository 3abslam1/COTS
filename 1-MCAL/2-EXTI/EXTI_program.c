/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: EXTI        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

void (*EXTI_pvInt0Func)(void)= NULL ;
void (*EXTI_pvInt1Func)(void)= NULL ;
void (*EXTI_pvInt2Func)(void)= NULL ;


void EXTI_voidIntInit(void)
{
       #if   INT0_INITIAL_STATE == ENABLED
       SET_BIT(GICR,GICR_INT0);
	   EXTI_u8IntSetSenseControl(INT_LINE0 ,INT0_SENSE_MODE);
       
       #elif INT0_INITIAL_STATE == DISABLED
       CLR_BIT(GICR,GICR_INT0);

       #else
       #error "Wrong INT_INITIAL_STATE Configuration Option"
       #endif  




       #if   INT1_INITIAL_STATE == ENABLED
       SET_BIT(GICR,GICR_INT1);
       EXTI_u8IntSetSenseControl(INT_LINE1 ,INT1_SENSE_MODE);
	   
       #elif INT1_INITIAL_STATE == DISABLED
       CLR_BIT(GICR,GICR_INT1);
       
       #else
       #error "Wrong INT_INITIAL_STATE Configuration Option"
       #endif



       #if   INT2_INITIAL_STATE == ENABLED
       SET_BIT(GICR,GICR_INT2);
       EXTI_u8IntSetSenseControl(INT_LINE2 ,INT2_SENSE_MODE);
	   
       #elif INT2_INITIAL_STATE == DISABLED
       CLR_BIT(GICR,GICR_INT2);
       
       #else
       #error "Wrong INT_INITIAL_STATE Configuration Option"
       #endif



}



u8 EXTI_u8IntSetSenseControl(u8 Copy_INTline ,u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;


if (Copy_INTline == INT_LINE0)
{
       switch(Copy_u8Sense){
       	
       	case  LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC01);		CLR_BIT(MCUCR,MCUCR_ISC00); 	break;
       	
       	case ON_CHANGE:		    CLR_BIT(MCUCR,MCUCR_ISC01);		SET_BIT(MCUCR,MCUCR_ISC00);   	break;
       	
       	case FALLING_EDGE:		SET_BIT(MCUCR,MCUCR_ISC01);		CLR_BIT(MCUCR,MCUCR_ISC00);	    break;
       	
       	case RISING_EDGE:       SET_BIT(MCUCR,MCUCR_ISC01);		SET_BIT(MCUCR,MCUCR_ISC00); 	break;
       	
       	default:	Local_u8ErrorState = NOK;
       }
}

else if (Copy_INTline == INT_LINE1)
{
        switch(Copy_u8Sense){
     	
     	case  LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC11);		CLR_BIT(MCUCR,MCUCR_ISC10); 	break;
     	
     	case ON_CHANGE:		    CLR_BIT(MCUCR,MCUCR_ISC11);		SET_BIT(MCUCR,MCUCR_ISC10);   	break;
     	
     	case FALLING_EDGE:		SET_BIT(MCUCR,MCUCR_ISC11);		CLR_BIT(MCUCR,MCUCR_ISC10);	    break;
     	
     	case RISING_EDGE:       SET_BIT(MCUCR,MCUCR_ISC11);		SET_BIT(MCUCR,MCUCR_ISC10); 	break;
     	
     	default:	Local_u8ErrorState = NOK;
       }	
}
		
else if (Copy_INTline == INT_LINE2)
{
        switch(Copy_u8Sense){

	    case FALLING_EDGE:      CLR_BIT(MCUCSR,MCUCSR_INT2);	    break;
	    
	    case RISING_EDGE:       SET_BIT(MCUCSR,MCUCSR_INT2); 	break;
	    
	    default:	Local_u8ErrorState = NOK;
       }
}
else   Local_u8ErrorState = NOK;
	
   
	return Local_u8ErrorState;
}




u8 EXTI_u8IntEnable(u8 Copy_u8INTline)
{
		u8 Local_u8ErrorState = OK;
		
		switch(Copy_u8INTline){
			
			case INT_LINE0:		    SET_BIT(GICR,GICR_INT0);	    break;
			
			case INT_LINE1:         SET_BIT(GICR,GICR_INT1); 	    break;
			
			case INT_LINE2:         SET_BIT(GICR,GICR_INT2); 	    break;
			
			
			default:	Local_u8ErrorState = NOK;
		}
		
		return Local_u8ErrorState;
	
}

u8 EXTI_u8IntDisable(u8 Copy_INTline)
{
		u8 Local_u8ErrorState = OK;
		
		switch(Copy_INTline){
			
			case INT_LINE0:		    CLR_BIT(GICR,GICR_INT0);	    break;
			
			case INT_LINE1:         CLR_BIT(GICR,GICR_INT1); 	    break;
			
			case INT_LINE2:         CLR_BIT(GICR,GICR_INT2); 	    break;
			
			default:	Local_u8ErrorState = NOK;
		}
		
		return Local_u8ErrorState;
	
}


u8 EXTI_u8SetCallBack_INT0( void (*Copy_pvInt0Func)(void) ){
		u8 Local_u8ErrorState = OK;
		
		if ( (Copy_pvInt0Func != NULL) )
		{
			EXTI_pvInt0Func = Copy_pvInt0Func;
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
		return Local_u8ErrorState;
}


u8 EXTI_u8SetCallBack_INT1( void (*Copy_pvInt1Func)(void) ){
	u8 Local_u8ErrorState = OK;
	
	if ( (Copy_pvInt1Func != NULL) )
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8SetCallBack_INT2( void (*Copy_pvInt2Func)(void) ){
	u8 Local_u8ErrorState = OK;
	
	if ( (Copy_pvInt2Func != NULL) )
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}




void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Func != NULL)
	EXTI_pvInt0Func();
	
}


void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvInt1Func != NULL)
	EXTI_pvInt1Func();
	
}


void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvInt2Func != NULL)
	EXTI_pvInt2Func();
	
}