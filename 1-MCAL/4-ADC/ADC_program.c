/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: ADC         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/


#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"


/* Single Asynch */
static u16* ADC_ConvResult     = NULL ;
static void(*ADC_ISRptr)(void) = NULL;

/* Chain Asynch */
static const ADC_Chain_t* ADC_pChainData= NULL;

/*To Define Single or Chain in the ISR*/
static u8 ADC_u8ISRSource;

static u8 ADC_u8BusyFlag =IDLE;

void ADC_voidInit(void)
{
	/** Select the voltage reference **/
	
	#if ADC_VREF == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
	#elif ADC_VREF == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	#elif ADC_VREF == INTERNAL_2_56
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
	
	#else
	#error "Wrong ADC_VREF config"
	
	#endif
	
	
	/*Set Prescaler Value*/
	ADCSRA &= ADC_PRE_MASK ;
	ADCSRA |= ADC_PRESCALER ;
	
	
	/** Select Adjustment **/
	
	#if ADC_ADJUSMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX,ADMUX_ADLAR);
	
	#elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	
	#else
	#error "Wrong ADC_ADJUSTMENT config"
	
	#endif
	
	
	/** ENABLE The Peripheral & Interrupt **/
	
	/*Enable ADC Peripheral*/
	
	#if ADC_STATUS == ADC_DISABLE
	CLR_BIT(ADCSRA , ADCSRA_ADEN) ;
	
	#elif ADC_STATUS == ADC_ENABLE
	SET_BIT(ADCSRA , ADCSRA_ADEN) ;
	
	#else
	#error "Wrong ADC_STATUS config"
	
	#endif


	/*Enable ADC Interrupt*/
	
	#if INT_STATUS == INT_DISABLE
	CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
	
	#elif INT_STATUS == INT_ENABLE
	SET_BIT(ADCSRA , ADCSRA_ADIE) ;
	
	#else
	#error "Wrong INT_STATUS config"
	
	#endif
}

void ADC_voidEnable           (void)
{
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidDisable          (void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidInterruptEnable  (void)
{
	GIE_voidEnable();
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_voidInterruptDisable (void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_u8Prescaler < MaxPrescaler)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= Copy_u8Prescaler ;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState ;
}

u8   ADC_u8StartSingleConversionSynch(u8 Copy_u8Channel ,  u16* Copy_pu16Reading)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32TimeoutCounter = 0 ;
	if (Copy_pu16Reading != NULL)
	{
		if (ADC_u8BusyFlag == IDLE)
	{
		/*ADC is now Busy*/
		ADC_u8BusyFlag = BUSY ;

		/*Set required channel*/
		ADMUX &= ADC_CH_MASK ;
		ADMUX |= Copy_u8Channel ;

		/*Start Conversion*/
		SET_BIT(ADCSRA , ADCSRA_ADSC) ;

		/*Waiting until the conversion is complete*/
		while (((GET_BIT(ADCSRA , ADCSRA_ADIF)) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
		{
			Local_u32TimeoutCounter++ ;
		}
		if (Local_u32TimeoutCounter == ADC_TIMEOUT)
		{
			Local_u8ErrorState = NOK ;
		}
		else
		{
			/*Clear the interrupt flag*/
			SET_BIT(ADCSRA , ADCSRA_ADIF) ;

			/*Return Conversion Result*/
            #if ADC_RESOLUTION == ADC_8Bits
                   
                   #if ADC_ADJUSMENT == LEFT_ADJUSTMENT
                   *Copy_pu16Reading= ADCH;
                   
                   #elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
                   *Copy_pu16Reading= (ADCL>>2) |  ( (u16)ADCH<<6 ) ;
                   
                   #else
                   #error "Wrong ADC_ADJUSTMENT config"
                   
                   #endif
                   
             #elif ADC_RESOLUTION == ADC_10Bits
                   
                   #if ADC_ADJUSMENT == LEFT_ADJUSTMENT
                   *Copy_pu16Reading= (ADCL>>6) |  ( (u16) ADCH<<2 ) ;
                   
                   #elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
                   *Copy_pu16Reading= (ADCL) |  ( (u16) ADCH<<8 );
                   
                   #else
                   #error "Wrong ADC_ADJUSTMENT config"
                   
                   #endif
                   
                   #endif
		}

		/*ADC is IDLE*/
		ADC_u8BusyFlag = IDLE ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}


}
else
{
	Local_u8ErrorState = NULL_POINTER ;
}
return Local_u8ErrorState ;
	
}


u8   ADC_u8StartSingleConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) )
{
	u8 Local_u8ErrorState = OK ;

	if ((Copy_pu16Reading != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_u8BusyFlag == IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8BusyFlag = BUSY ;

			/*Initialize the global result pointer*/
			ADC_ConvResult = Copy_pu16Reading;

			/*Initialize the global notification function pointer*/
			ADC_ISRptr= Copy_pvNotificationFunc;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;

			/*Start Conversion*/
			SET_BIT(ADCSRA , ADCSRA_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA , ADCSRA_ADIE) ;

            /*ISR Source is SINGLE Conversion Asynch*/
            ADC_u8ISRSource = SINGLE_ASYNCH;
			
			
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

u8   ADC_u8StartChainConversionAsynch( const ADC_Chain_t* Copy_Object )
{
	u8 Local_u8StateError = OK;
	
	if( (Copy_Object!= NULL) && (Copy_Object->ChannelArr!= NULL) && (Copy_Object->ResultArr!= NULL) && (Copy_Object->NotificationFunc!=NULL) )
	{
		if(ADC_u8BusyFlag == IDLE)
		{
			
			ADC_u8BusyFlag = BUSY;
			
			ADC_pChainData = Copy_Object;
			
			//set the required channel
			ADMUX&=ADC_CH_MASK;
			ADMUX|=ADC_pChainData->ChannelArr[0];
			
			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			
			//Enable ADC conversion complete interrupt
			SET_BIT(ADCSRA, ADCSRA_ADIE);

			/*ISR Source is CHAIN Conversion Asynch*/
			ADC_u8ISRSource = CHAIN_ASYNCH;
		}
		
		else
		{
			Local_u8StateError = Busy_ERROR ;
		}
		
	}
	else
	{
		Local_u8StateError = NOK;
	}
	
	
	return Local_u8StateError;
}



static void voidHandleSingleConvAsynch(void)
{
	#if ADC_RESOLUTION == ADC_8Bits
	
	#if ADC_ADJUSMENT == LEFT_ADJUSTMENT
	*ADC_ConvResult= ADCH;
	
	#elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
	*ADC_ConvResult= (ADCL>>2) | ( (u16)ADCH<<6 ) ;
	
	#else
	#error "Wrong ADC_ADJUSTMENT config"
	
	#endif
	
	#elif ADC_RESOLUTION == ADC_10Bits
	
	#if ADC_ADJUSMENT == LEFT_ADJUSTMENT
	*ADC_ConvResult= (ADCL>>6) |  ( (u16) ADCH<<2 ) ;
	
	#elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
	*ADC_ConvResult= (ADCL) | ( (u16) ADCH<<8 ) ;
	
	#else
	#error "Wrong ADC_ADJUSTMENT config"

	#endif
	
	#endif

	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	ADC_u8BusyFlag = IDLE;

	
	if (ADC_ISRptr!= NULL)
	{
		ADC_ISRptr();
	}
	
}

static void voidHandleChainConvAsynch(void)
{
	volatile static u8 Local_u8ChannelIndex=0;
	
	#if ADC_RESOLUTION == ADC_8Bits
	
	#if ADC_ADJUSMENT == LEFT_ADJUSTMENT
	ADC_pChainData->ResultArr[Local_u8ChannelIndex]=ADCH;
	
    #elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
	ADC_pChainData->ResultArr[Local_u8ChannelIndex]= (ADCL>>2) | ( (u16)ADCH<<6 ) ;
	
	#else
	#error "Wrong ADC_ADJUSTMENT config"
	
	#endif
	
	#elif ADC_RESOLUTION == ADC_10Bits
	
	#if ADC_ADJUSMENT == LEFT_ADJUSTMENT
	ADC_pChainData->ResultArr[Local_u8ChannelIndex]= (ADCL>>6) | ( (u16) ADCH<<2 ) ;
	
	#elif ADC_ADJUSMENT == RIGHT_ADJUSTMENT
	ADC_pChainData->ResultArr[Local_u8ChannelIndex]=(ADCL) | ( (u16) ADCH<<8 ) ;
	
    #else
    #error "Wrong ADC_ADJUSTMENT config"
	
	#endif
	
	#endif

	Local_u8ChannelIndex++;

	if(Local_u8ChannelIndex == ADC_pChainData->ChainSize)
	{
		/*Chain is Completed*/
		Local_u8ChannelIndex =0;
		
		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		ADC_u8BusyFlag = IDLE;

		
		if (ADC_pChainData->NotificationFunc !=NULL)
		{
			ADC_pChainData->NotificationFunc();
		}
		
		
	}
	else{
		/*Chain is Not Finished*/
		//set the required channel
		ADMUX&=ADC_CH_MASK;
		ADMUX|=ADC_pChainData->ChannelArr[Local_u8ChannelIndex];

		//start conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);

	}
}

void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void){

	if(ADC_u8ISRSource == SINGLE_ASYNCH)
	{
		voidHandleSingleConvAsynch();
	}

	else if (ADC_u8ISRSource == CHAIN_ASYNCH)
	{
		voidHandleChainConvAsynch();
	}

}



