/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
void EXTI_voidInitDefaultMode()
{
	#if EXTI_IRQEvent == EXTI_RISING
		SET_BIT((EXTI->EXTI_RTSR) , EXTI_LINE ) ;
		CLR_BIT((EXTI->EXTI_FTSR) , EXTI_LINE )	;
	#elif EXTI_IRQEvent == EXTI_FALLING
		SET_BIT((EXTI->EXTI_FTSR) , EXTI_LINE ) ;
		CLR_BIT((EXTI->EXTI_RTSR) , EXTI_LINE ) ;
	#elif EXTI_IRQEvent == EXTI_ON_CHANGE
		SET_BIT((EXTI->EXTI_FTSR) , EXTI_LINE ) ;
		SET_BIT((EXTI->EXTI_RTSR) , EXTI_LINE ) ;
	#else
		#error ("Wrong Mode Choice")
	#endif 
	//SET_BIT((EXTI -> EXTI_IMR ) , EXTI_LINE ) ;
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
	
	SET_BIT((EXTI->EXTI_IMR) , EXTI_LINE ); 
	CLR_BIT((EXTI->EXTI_PR) ,EXTI_LINE ) ; 
	SET_BIT((EXTI->EXTI_SWIER) , EXTI_LINE );
}
void EXTI_VoidFullControlSignalLatch(u8 Copy_u8LineID , u8 Copy_u8IRQEvent  , u8 Copy_u8LineStatus )
{
	if (Copy_u8LineID <= 15)
	{	switch(Copy_u8IRQEvent)
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
				else
				{
					// <~TODO> Wrong In Line Status
				}
				break ;
			case EXTI_FALLING	:
				if ( Copy_u8LineStatus == ENABLE )
				{
					SET_BIT((EXTI->EXTI_FTSR) , Copy_u8LineID ) ;
					CLR_BIT((EXTI->EXTI_RTSR) , Copy_u8LineID);
				}	
				else if ( Copy_u8LineStatus == DISABLE )
				{
					CLR_BIT((EXTI->EXTI_IMR) , Copy_u8LineID )  ;
				}
				else
				{
					// <~TODO> Wrong In Line Status
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
				else
				{
					// <~TODO> Wrong In Line Status
				}
				break ; 
			default : /* error in IRQ Enent (Mode Event) */ break ; 
			
		}
	}
	else
	{
		// <~TODO> Wrong Line Number
	}
}

void EXTI_VoidSetCallBack(void(*Copy_ptr) (void))
{
	EXTI0_Callback = Copy_ptr ;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_Callback();
	/*	Clear Pending Bit	*/
	SET_BIT((EXTI -> EXTI_PR ) , 0 ) ; 
}
