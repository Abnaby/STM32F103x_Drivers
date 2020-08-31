/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
#include "RCC_interface.h"
void AFIO_voidInit(void)
{
	RCC_voidEnableClock(RCC_APB2,0);

}
void AFIO_voidEXTIConfiguration(u8 Copy_u8LineID , u8 Copy_u8PinMap)
{
	u8 LOC_u8IntIndex = 0 ; 
	if (Copy_u8LineID <= 3)
	{
		/*		REGISTER 0 INT 0 , INT 1 , INT 2 AND INT 3		 */
		LOC_u8IntIndex = 0 ;
	}
	else if (Copy_u8LineID <= 7 )
	{
		/*		REGISTER 1 INT 4 , INT 5 , INT 6 AND INT 7		 */
		Copy_u8LineID -=4 ; 
		LOC_u8IntIndex = 1 ; 
	}
	else if (Copy_u8LineID <= 11 )
	{
		/*		REGISTER 2 INT 8 , INT 9 , INT 10 AND INT 11		 */
		Copy_u8LineID -=8 ; 
		LOC_u8IntIndex = 2 	;	
	}
	else if (Copy_u8LineID <= 15)
	{
		/*		REGISTER 3 INT 12 , INT 13 , INT 14 AND INT 15		 */
		Copy_u8LineID -=12 ; 
		LOC_u8IntIndex = 3 	;	
	}
	else
	{
		/* ERROR */ 
	}
	/*			RESET		*/
	AFIO -> AFIO_EXTICR[LOC_u8IntIndex] &=~((0b1111)<<(Copy_u8LineID * 4 ));
	/*			ASSIGN		*/
	AFIO -> AFIO_EXTICR[LOC_u8IntIndex]  |= ((Copy_u8PinMap)<<(Copy_u8LineID * 4 ));
}
