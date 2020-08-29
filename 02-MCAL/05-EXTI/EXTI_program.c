/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInitDefaultMode()
{
	#if EXTI_IRQEvent == EXTI_RISING
		SET_BIT((EXTI->EXTI_RTSR) , EXTI_LINE ) ;
	#elif EXTI_IRQEvent == EXTI_FALLING
		SET_BIT((EXTI->EXTI_FTSR) , EXTI_LINE ) ;
	#elif EXTI_IRQEvent == EXTI_ON_CHANGE
		SET_BIT((EXTI->EXTI_FTSR) , EXTI_LINE ) ;
		SET_BIT((EXTI->EXTI_RTSR) , EXTI_LINE ) ;
	#else
		#error "Wrong Mode Choice"
	#endif 
}
void EXTI_voidEnableEXTIInDefaultMode(u8 Copy_u8LineID)
{
	SET_BIT((EXTI->EXTI_IMR) , EXTI_LINE );
}
void EXTI_voidDisableEXTIInDefaultMode(u8 Copy_u8LineID)
{
	CLR_BIT((EXTI->EXTI_IMR) , EXTI_LINE );
}
void EXTI_voidSwTriggerInDefaultMode(u8 Copy_u8LineID)
{
	
	SET_BIT((EXTI->EXTI_SWIER) , EXTI_LINE );
}
void EXTI_VoidFullControlSignalLatch(u8 Copy_u8LineID , u8 Copy_u8IRQEvent  , u8 Copy_u8LineStatus )
{
	switch(Copy_u8IRQEvent)
	{
		case EXTI_RISING 	: 
			if ( Copy_u8LineStatus == ENABLE )
			{
				SET_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
				SET_BIT((EXTI->EXTI_RTSR) , Copy_u8LineID ) ;
				CLR_BIT((EXTI->EXTI_FTSR) , Copy_u8LineID );
			}	
			else if ( Copy_u8LineStatus == DISABLE )
			{
				CLR_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
			}
			break ;
		case EXTI_FALLING	:
			if ( Copy_u8LineStatus == ENABLE )
			{
				SET_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
				SET_BIT((EXTI->EXTI_FTSR) , Copy_u8LineID ) ;
				CLR_BIT((EXTI->EXTI_RTSR) , Copy_u8LineID);
			}	
			else if ( Copy_u8LineStatus == DISABLE )
			{
				CLR_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
			}
			break ; 
		case EXTI_ON_CHANGE :
			if ( Copy_u8LineStatus == ENABLE )
			{
				SET_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
				SET_BIT((EXTI->EXTI_RTSR) , Copy_u8LineID ) ;
				SET_BIT((EXTI->EXTI_FTSR) , Copy_u8LineID ) ;
			}	
			else if ( Copy_u8LineStatus == DISABLE )
			{
				CLR_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
			}
			break ; 
		default : /* error */ break ; 
		
	}
}
