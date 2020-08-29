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
#define LINE0	0
#define LINE1	1
#define LINE2	2
#define LINE3	3
#define LINE4	4
#define LINE5	5
#define LINE6	6
#define LINE7	7
#define LINE8	8
#define LINE9	9
#define LINE10	10
#define LINE11	11
#define LINE12	12
#define LINE13	13
#define LINE14	14
#define LINE15	15
#define LINE16	16
#define LINE17	17
#define LINE18	18
		/*		INTERRUPT CAPTURE 		*/	
#define EXTI_RISING 	0
#define EXTI_FALLING 	1
#define EXTI_ON_CHANGE	2

#define ENABLE 	1
#define DISABLE		0
		
#endif
