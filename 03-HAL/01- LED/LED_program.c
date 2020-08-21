/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 18 August 2020                                                    */
/*********************************************************************************/
/* Library includes */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

/* MCAL includes */

#include "RCC_interface.h" 

#include "GPIO_interface.h"

#include "LED_interface.h"

#include "LED_private.h"

#include "LED_config.h"


/*
				GPIO_OUTPUT_$MHZ_#			$ -->
												10
												2
												50
											# -- >
												PUSH_PULL
												OPEN_DRAIN
												AF_PUSH_PULL
												AF_OPEN_DRAIN	
	BY DEFAULT : OUTPUT WITH 10MHZ SPEED PUSH PULL
*/
void LED_voidTurnOn  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	#if Copy_u8Port == GPIO_PORTA
		RCC_voidEnableClock(RCC_APB2 , 2) ;
	#elif Copy_u8Port == GPIO_PORTB
		RCC_voidEnableClock(RCC_APB2 , 3) ;
	#elif Copy_u8Port == GPIO_PORTC
		RCC_voidEnableClock(RCC_APB2 , 4) ;
	#else 
		/* error */ 
	#endif
	#if LED_MODE == LED_NORMAL_MODE 
		GPIO_voidSetPinDirection(Copy_u8Port , Copy_u8Pin ,Copy_u8Mode);
		GPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin  , HIGH) ;
	#elif LED_MODE == LED_REVERSE_MODE
		GPIO_voidSetPinDirection(Copy_u8Port , Copy_u8Pin ,Copy_u8Mode);
		GPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin  , LOW) ;
	#endif
}

void LED_voidTurnOff (u8 Copy_u8Port , u8 Copy_u8Pin) 
{
	#if LED_MODE == LED_NORMAL_MODE 
		GPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin  , LOW) ;
	#elif LED_MODE == LED_REVERSE_MODE
		GPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin  , HIGH) ;
	#endif
}
void LED_voidToggle	 (u8 Copy_u8Port , u8 Copy_u8Pin ){
	   GPIO_voidTogglePinValue(Copy_u8Port, Copy_u8Pin) ;
	
}

u8 LED_u8State (u8 Copy_u8Port , u8 Copy_u8Pin ) 
{
		u8 LOC_u8LedState = GPIO_u8GetPinValue (Copy_u8Port , Copy_u8Pin ) ;
		return LOC_u8LedState ; 
}
