/**************************************************************************/
/* Author	: Mohamed                                                     */
/* Date		: 8 AUG 2020                                                  */
/* Version	: V01							                              */
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/**********************************************************/
/* Copy_u8Bus : AHB, APB1 or APB2 						  */
/* Copy_u8PerId : bit number in specific bus (0 : 31)	  */
/* RCC_AHBENR  ==> register name						  */
/**********************************************************/
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8PerId){
	//Input validation
	if (Copy_u8PerId <= 31) // check range
	{
		switch(Copy_u8Bus)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);	break ;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);	break ;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);break ;
			//default		  : /*return error */	break ;
		}
		
	}
	else{
		/* return error*/
		
	}
		
}
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8PerId){
	//Input validation
	if (Copy_u8PerId <= 31) // check range
	{
		switch(Copy_u8Bus)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId); 	break ;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);	break ;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);	break ;
			//default		  : /*return error */	break ;
		}
		
	}
	else{
		/* return error*/
		
	}
		
}
	//PLL multiplication factor. These bits can be written only when PLL is disabled.

void RCC_voidInititSysClock(void)
{
	#if	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL 
		RCC_CR   = 0x00010000 ; // enable HSI with no byoass 
		RCC_CFGR = 0x00000001; //HSE sys clock
	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000 ; // enable HSI with  byoass 
		RCC_CFGR = 0x00000001; //HSE sys clock
	#elif 	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; // 0X00000001  // enable HSI		
		RCC_CFGR = 0x00000000; //HSI sys clock
	#elif 	RCC_CLOCK_TYPE == RCC_PLL
		while(GET_BIT(RCC_CR ,PLLRDY) != 1){}
		#if 	RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR = 0x00000000 ; 
		#elif	RCC_PLL_IN_HSE_DIV_2
			/* add 1 in bit 16 */ 
			RCC_CFGR = 0x10000;  // 0b0000000000000010000000000000000 
		#elif	RCC_PLL_IN_HSE
			/* add 1 in bit 16 and 1 in bit 17 */ 
			RCC_CFGR = 0x30000; //  0b0000000000000010000000000000000 
		#else
			/*error */
		#endif 
		RCC_CFGR |= 0x00000002; // 0b 00000000 00000000 00000000 00000010 to make PLL as a system clk
		/* for multiplication */
		SPECIAL_CLR (RCC_CFGR,0b1111,18); // Reset 4 bit of RCC_PLLMUL_VAL  Write 0000 
		SPECIAL_SET(RCC_CFGR,RCC_PLLMUL_VAL,18); // shifted 18 by MUL value then |= with RCC_CFGR Rrgister to write on this 4 bits 
		SET_BIT(RCC_CR,PLLON); // for enable PLL
	#else
		#error("Wrong chocice clock type")
	#endif
}
