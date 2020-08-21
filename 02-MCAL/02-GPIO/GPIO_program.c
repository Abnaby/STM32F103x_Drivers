/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 14 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection	(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
			if(Copy_u8Pin <= 7)
			{
				/* 			RESET		*/

				GPIOA_CRL &= ~(0b1111<<(Copy_u8Pin*4));
				/*			VALUE		*/
				
				GPIOA_CRL |= ((Copy_u8Mode)<< (4*Copy_u8Pin)); 
			}
			else if (Copy_u8Pin <= 15 )
			{
				Copy_u8Pin = Copy_u8Pin - 8 ;
				GPIOA_CRH &= ~(0b1111<<(Copy_u8Pin*4));
				GPIOA_CRH |= ((Copy_u8Mode)<< ( 4 * Copy_u8Pin)); 

			}
			else 
			{
				/* error */ 
			}
			break;
		case GPIO_PORTB :
			if(Copy_u8Pin <= 7)
			{
				GPIOB_CRL &= ~(0b1111<<(Copy_u8Pin*4)); // to reset pin
				GPIOB_CRL |= ((Copy_u8Mode)<< ( 4 * Copy_u8Pin)); 
			}
			else if (Copy_u8Pin <= 15 )
			{
				Copy_u8Pin = Copy_u8Pin - 8 ; //TO REPRESENT PIN 8 IN FIRST 4 BITS IN CRH REGESTER 
				GPIOC_CRL &= ~(0b1111<<(Copy_u8Pin*4));
				GPIOB_CRH |= ((Copy_u8Mode)<< (4*Copy_u8Pin)); 

			}
			else 
			{
				/* error */ 
			}
			break;
		case GPIO_PORTC :
			if(Copy_u8Pin <= 7)
			{
				GPIOC_CRL &= ((0b0000)     << ( 4 * Copy_u8Pin)) ; // to reset pin 
				GPIOC_CRL |= ((Copy_u8Mode)<< ( 4 * Copy_u8Pin));				
			}
			else if (Copy_u8Pin <= 15 )
			{
				Copy_u8Pin = Copy_u8Pin - 8 ; //TO REPRESENT PIN 8 IN FIRST 4 BITS IN CRH REGESTER 
				GPIOC_CRH &= ~(0b1111<<(Copy_u8Pin*4)); // to reset pin
				GPIOC_CRH |= ((Copy_u8Mode)<< (4*Copy_u8Pin)); 
			}
			else 
			{
				/* error */ 
			}
			break;
		default : break ;	
	}
}
void GPIO_voidSetPortDirection	(u8 Copy_u8Port, 			 u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		u32 LOC_u32Mode=0;
		case GPIO_PORTA :
			/*			RESET		*/
			GPIOA_CRL = 0x0 ;
			GPIOA_CRH = 0x0;
			/*			VALUE		*/
			LOC_u32Mode=0;
			for (u8 i=0 ; i<=7 ;i++)
				LOC_u32Mode = (LOC_u32Mode << 4) | Copy_u8Mode;
			GPIOA_CRL =  LOC_u32Mode ;
			GPIOA_CRH = LOC_u32Mode ;
			break;
		case GPIO_PORTB :
			GPIOB_CRL = 0x0 ;
			GPIOB_CRH = 0x0;
			/*			VALUE		*/
			LOC_u32Mode=0;
			for (u8 i=0 ; i<=7 ;i++)
				LOC_u32Mode = (LOC_u32Mode << 4) | Copy_u8Mode; ;
			GPIOB_CRL =  LOC_u32Mode ;
			GPIOB_CRH = LOC_u32Mode ;
			break;
		case GPIO_PORTC :
			GPIOC_CRL = 0x0 ;
			GPIOC_CRH = 0x0;
			/*			VALUE		*/
			LOC_u32Mode=0;
			for (u8 i=0 ; i<=7 ;i++)
				LOC_u32Mode = (LOC_u32Mode << 4) | Copy_u8Mode; ;
			GPIOC_CRL =  LOC_u32Mode ;
			GPIOC_CRH = LOC_u32Mode ;
			break;
		default : break ;
	}
}
	
		

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		if(Copy_u8Pin > 15)
		{
			/* error */
		}
		case GPIO_PORTA :		
			switch (Copy_u8Value)
			{
				case HIGH :
					SET_BIT(GPIOA_ODR , Copy_u8Pin) ;
					break ;
				case LOW  :	
					CLR_BIT(GPIOA_ODR , Copy_u8Pin) ;
					break ;
				default :
					/*error */ 
					break ; 
			}	
			break ; 
		case GPIO_PORTB :
			switch (Copy_u8Value)
			{
				case HIGH :
					SET_BIT(GPIOB_ODR , Copy_u8Pin) ;
					break ;
				case LOW  :	
					CLR_BIT(GPIOB_ODR , Copy_u8Pin) ;
					break ;
				default :
					/*error */ 
					break ; 
			}			
			break ;
		case GPIO_PORTC	:
			switch (Copy_u8Value)
			{
				case HIGH :
					SET_BIT(GPIOC_ODR , Copy_u8Pin) ;
					break ;
				case LOW  :	
					CLR_BIT(GPIOC_ODR , Copy_u8Pin) ;
					break ;
				default :
					/*error */ 
					break ; 
			}	
			break ;
		default :
		//error
			break ;
	}
}


void GPIO_voidSetPortValue		(u8 Copy_u8Port, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
			switch(Copy_u8Value)
			{
			case HIGH :
				GPIOA_ODR = 0b1111111111111111 ;
				break ;
			case LOW :
				GPIOA_ODR = 0b0000000000000000 ;
				break ;
			}
			break ;
		case GPIO_PORTB :
			GPIOB_ODR = Copy_u8Value ;
			break ;
		case GPIO_PORTC :
			GPIOC_ODR = Copy_u8Value ;
			break ;
		default :

		break ;
	}

}

void GPIO_voidTogglePinValue	(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port){
		case GPIO_PORTA :
			if(Copy_u8Pin <= 7){
				TOG_BIT(GPIOA_ODR , Copy_u8Pin ) ;
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin=  Copy_u8Pin - 8 ;
				TOG_BIT(GPIOA_ODR , Copy_u8Pin ) ;
			}
			else{
				/* error */
			}
			break ;
		case GPIO_PORTB :
			if(Copy_u8Pin <= 7){
				TOG_BIT(GPIOB_ODR , Copy_u8Pin ) ;
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin=  Copy_u8Pin - 8 ;
				TOG_BIT(GPIOB_ODR , Copy_u8Pin ) ;
			}
			else{
				/* error */
			}
			break ;
		case GPIO_PORTC :
			if(Copy_u8Pin <= 7){
				TOG_BIT(GPIOC_ODR , Copy_u8Pin ) ;
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin=  Copy_u8Pin - 8 ;
				TOG_BIT(GPIOC_ODR , Copy_u8Pin ) ;
			}
			else{
				/* error */
			}
			break ;
		default :
			/* error */
			break ;

	}


}
u8 GPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	if(Copy_u8Pin > 15)
	{
		/* error */
	}
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
			LOC_u8Result  = GET_BIT(GPIOA_IDR , Copy_u8Pin ) ;
			break ;
		case GPIO_PORTB :
			LOC_u8Result  = GET_BIT(GPIOB_IDR , Copy_u8Pin ) ;			
			break ;
		case GPIO_PORTC : 
			LOC_u8Result  = GET_BIT(GPIOC_IDR , Copy_u8Pin ) ;
			break ;
		default :
			/* error */ 
			break ;
	}
	return LOC_u8Result ;
}
	
	
	
