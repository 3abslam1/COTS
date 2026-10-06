/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: HAL        ******************/
/******************          SWC: LM35         ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/



#include "LM35_interface.h"
#include "../../MCAL/ADC/ADC_config.h"


void LM35_voidGetTemp (LM35_configuration * lm35 , u8 * Copy_u8TempValue)
{	
	u16 Local_u16ADCresult;
	u16 Local_u16mv;
	
	u16 Local_u16ADCvref=(lm35->Copy_u8ADCVoltageReference)*1000;
	
	ADC_u8GetChannelReading(lm35->Copy_u8LM35Channel , &Local_u16ADCresult);
	
#if ADC_RESOLUTION == ADC_8Bits
	Local_u16mv=(u16) ( ( (u32)Local_u16ADCresult * (u32)Local_u16ADCvref)/256UL );

#elif ADC_RESOLUTION == ADC_10Bits
Local_u16mv=(u16) ( ( (u32)Local_u16ADCresult * (u32)Local_u16ADCvref)/1024UL );	
	
#endif
	*Copy_u8TempValue= Local_u16mv / 10;
	
}