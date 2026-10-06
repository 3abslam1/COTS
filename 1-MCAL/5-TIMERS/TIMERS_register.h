/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************          SWC: TIMERS       ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/




#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TIMSK			*((volatile u8*)0X59)
	#define TIMSK_TOIE0		0
	#define TIMSK_OCIE0		1
	#define TIMSK_TOIE1		2
	#define TIMSK_OCIE1B	3
	#define TIMSK_OCIE1A	4
	#define TIMSK_TICIE1	5
	#define TIMSK_TOIE2		6
	#define TIMSK_OCIE2		7




#define TIFR			*((volatile u8*)0X58)
	#define TIFR_TOV0		0
	#define TIFR_OCF0		1
	#define TIFR_TOV1		2
	#define TIFR_OCF1B		3
	#define TIFR_OCF1A		4
	#define TIFR_ICF1		5
	#define TIFR_TOV2		6
	#define TIFR_OCV2		7




/*Timer0*/
#define TCCR0			*((volatile u8*)0X53)
	#define TCCR0_CS00      0
	#define TCCR0_CS01      1
	#define TCCR0_CS02      2
	#define TCCR0_WGM01     3
	#define TCCR0_COM00     4
	#define TCCR0_COM01     5	
	#define TCCR0_WGM00     6	
	#define TCCR0_FOC0      7	
	
	
#define TCNT0			*((volatile u8*)0X52)
#define OCR0			*((volatile u8*)0X5C)




/*Timer1*/
#define TCCR1A			*((volatile u8*)0X4F)
#define TCCR1B			*((volatile u8*)0X4E)
#define TCNT1H          *((volatile u8 *)(0x4D))
#define TCNT1L          *((volatile u8 *)(0x4C))
#define TCNT1			*((volatile u16*)0X4C)    /* u16 for HIGH & LOW */
#define OCR1AL          *((volatile u8 *)(0x4A))
#define OCR1AH          *((volatile u8 *)(0x4B))
#define OCR1A			*((volatile u16*)0X4A)
#define OCR1BL          *((volatile u8 *)(0x48))
#define OCR1BH          *((volatile u8 *)(0x49))
#define OCR1B			*((volatile u16*)0X48)
#define ICR1H           *((volatile u8 *)(0x47))
#define ICR1L           *((volatile u8 *)(0x46))
#define ICR1			*((volatile u16*)0X46)

/*Timer2*/

#define TCCR2			*((volatile u8*)0X45)
#define TCNT2			*((volatile u8*)0X44)
#define TCNT2			*((volatile u8*)0X44)
#define OCR2			*((volatile u8*)0X43)

#define WDTCR        *((volatile u8 *)(0x41))

#endif /* TIMER_REGISTER_H_ */