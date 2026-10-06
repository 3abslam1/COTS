/*
 * IncFile1.h
 *
 * Created: 8/30/2025 3:31:29 PM
 *  Author: USER
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BITNO)(REG|=(1<<BITNO))
#define CLR_BIT(REG,BITNO)(REG&=~(1<<BITNO))
#define TOG_BIT(REG,BITNO)(REG^=(1<<BITNO))
#define GET_BIT(REG,BITNO)((REG>>BITNO)&0X01)



#endif /* BIT_MATH_H_ */