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

#include "SSD_interface.h"

#include "SSD_private.h"

#include "SSD_config.h"


void SSD_voidInitAndDisplay(u8 Copy_u8Port , u8 Copy_u8Number) 
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

	GPIO_voidSetPinDirection(Copy_u8Port,SSD_A_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_B_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_C_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_D_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_E_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_F_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_G_PIN  ,SSD_PINS_MODE);
	GPIO_voidSetPinDirection(Copy_u8Port,SSD_DP_PIN ,SSD_PINS_MODE);

	/* for first pins 
	#if 	SSD_MODE == SSD_COMMON_CATHOD
		#if Copy_u8Port == GPIO_PORTA
			GPIOA_ODR |= Copy_u8Number ; 
		#elif Copy_u8Port == GPIO_PORTB
			GPIOB_ODR |= Copy_u8Number ; 
		#elif Copy_u8Port == GPIO_PORTC 
			GPIOC_ODR |= Copy_u8Number ;
		#endif 
	#elif 	SSD_MODE == SSD_COMMON_ANNOD
		#if Copy_u8Port == GPIO_PORTA
			GPIOA_ODR |= ~(Copy_u8Number); 
		#elif Copy_u8Port == GPIO_PORTB
			GPIOB_ODR |= ~(Copy_u8Number); 
		#elif Copy_u8Port == GPIO_PORTC 
			GPIOC_ODR |=  ~(Copy_u8Number); 
		#endif 
	#elif 
	#endif*/
	/* RESET */ 

	#if  SSD_MODE == SSD_COMMON_CATHOD
		switch(Copy_u8Number)
		{
			case 0 :
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				break ;
			case 1 :
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				break ;
			case 2:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				break ;
			case 3:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 4:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 5:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 6:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 7:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 8:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;

			case 9:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;

			default :
				/* error */
				break ;

		}
	#elif SSD_MODE == SSD_COMMON_ANNOD

		switch(Copy_u8Number)
		{
			case 0 :
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 1 :
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 2:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 3:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 4:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 5:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 6:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;
			case 7:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , HIGH );
				break ;
			case 8:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;

			case 9:
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_A_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_B_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_C_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_D_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_E_PIN , HIGH );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_F_PIN , LOW );
				GPIO_voidSetPinValue(Copy_u8Port ,SSD_G_PIN , LOW );
				break ;

			default :
				/* error */
				break ;

		}
	#endif

}

