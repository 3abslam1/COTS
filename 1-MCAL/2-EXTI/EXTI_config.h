/****************************************************************/
/****************************************************************/
/******************   Author: Mohamed 3abslam  ******************/
/******************          Layer: MCAL       ******************/
/******************           SWC: EXTI        ******************/
/******************         Version:1.00       ******************/
/****************************************************************/
/****************************************************************/

 
#ifndef   EXTI_CONFIG_H_
#define   EXTI_CONFIG_H_



/*   OPTIONS FOR INT0 & INT1                             OPTIONS FOR INT2
        1-   LOW_LEVEL								    1-   FALLING_EDGE
        2-   ON_CHANGE								    2-   RISING_EDGE
        3-   FALLING_EDGE							     
        4-   RISING_EDGE             				   
*/
#define  INT0_SENSE_MODE      FALLING_EDGE
#define  INT1_SENSE_MODE      FALLING_EDGE
#define  INT2_SENSE_MODE      FALLING_EDGE



/*                     OPTIONS
                  1-   ENABLED
				  2-   DISABLED
*/
#define  INT0_INITIAL_STATE  ENABLED
#define  INT1_INITIAL_STATE  ENABLED
#define  INT2_INITIAL_STATE  ENABLED




#endif  /*EXTI_CONFIG_H_*/