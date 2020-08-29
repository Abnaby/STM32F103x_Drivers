/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*
	* OPTIONS OF EXTI_IRQEvent : 
					EXTI_RISING
					EXTI_FALLING
					EXTI_ON_CHANGE
*/

#define EXTI_IRQEvent EXTI_RISING
/*
	*OPTIONS OF EXTI_LINE OPTIONS :
									LINE0
									LINE1
									.....
									.....
									LINE15
*/
#define EXTI_LINE LINE0
#endif

