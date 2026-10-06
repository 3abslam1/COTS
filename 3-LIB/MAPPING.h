/*
 * MAPPING.h
 *
 * Created: 2/16/2026 1:08:14 AM
 *  Author: USER
 */ 




#ifndef MAPPING_H_
#define MAPPING_H_

typedef struct
{
	u32 Copy_u32InputMin ;
	u32 Copy_u32InputMax ;
	u32 Copy_u32OutputMin ;
	u32 Copy_u32OutputMax ;
	u32 Copy_u32InputValue ;
}MAPPING_CONFIG ;

u32 MAPPING_u32GetOutput (MAPPING_CONFIG * mapping_config) ;

#endif  /*  MAPPING_H_ */