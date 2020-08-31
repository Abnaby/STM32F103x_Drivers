/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/



#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS	0x40010400 
		/*		REGISTER BOUNDARY ADDRESSES 		*/		
typedef struct
{
	volatile u32 EXTI_IMR	;
	volatile u32 EXTI_EMR	;
	volatile u32 EXTI_RTSR	;
	volatile u32 EXTI_FTSR	;
	volatile u32 EXTI_SWIER	;
	volatile u32 EXTI_PR	;
}EXTI_Type;
#define EXTI  ((EXTI_Type * )EXTI_BASE_ADDRESS)
		/*		LINE CONFIGURATION 		*/		
#define EXTI_LINE0	0
#define EXTI_LINE1	1
#define EXTI_LINE2	2
#define EXTI_LINE3	3
#define EXTI_LINE4	4
#define EXTI_LINE5	5
#define EXTI_LINE6	6
#define EXTI_LINE7	7
#define EXTI_LINE8	8
#define EXTI_LINE9	9
#define EXTI_LINE10	10
#define EXTI_LINE11	11
#define EXTI_LINE12	12
#define EXTI_LINE13	13
#define EXTI_LINE14	14
#define EXTI_LINE15	15
#define EXTI_LINE16	16
#define EXTI_LINE17	17
#define EXTI_LINE18	18
		/*		INTERRUPT CAPTURE 		*/	
#define EXTI_RISING 	0
#define EXTI_FALLING 	1
#define EXTI_ON_CHANGE	2

#define ENABLE 	1
#define DISABLE		0

		/*		Call Back		*/


static void (*EXTI0_Callback) (void) = NULL ;
		
#endif
