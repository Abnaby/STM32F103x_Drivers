/**************************************************************************/
/* Author	: Mohamed                                                     */
/* Date		: 8 AUG 2020                                                 */
/* Version	: V01							                              */
/**************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*  Clock type :
	Options:		RCC_HSE_CRYSTAL
					RCC_HSE_RC
					RCC_HSI
					RCC_PLL 
				
*/
#define RCC_CLOCK_TYPE				RCC_HSE_CRYSTAL
/*  Clock Security system :
	Options:		ON
					OFF 
*/
#define RCC_CSS_STATE				OFF
/* prepherial prescaler
	For AHB : 
				RCC_AHB_prescaler_NOT_DEV
				RCC_AHB_prescaler_SYSCLK_DIV_# , :# 2,4,6,8,16,64,128,256 and 512
	For APB1:
				RCC_APB1_prescaler_AHB_NOT_DEV
				RCC_APB1_prescaler_AHB_DIV_#  ,  : # --> 2,4,8 and 16
	For APB2:	
				RCC_APB2_prescaler_AHB_NOT_DEV
				RCC_APB2_prescaler_AHB_DIV_#  ,  : # --> 2,4,8 and 16
				

*/
#define RCC_AHB_prescaler			RCC_AHB_prescaler_NOT_DEV
#define RCC_APB1_prescaler			RCC_APB1_prescaler_AHB_NOT_DEV
#define RCC_APB2_prescaler			RCC_APB2_prescaler_AHB_NOT_DEV
/* PLL Clock source
	select valus only if have PLL as input clock source
				Options:		RCC_PLL_IN_HSI_DIV_2
								RCC_PLL_IN_HSE_DIV_2
								RCC_PLL_IN_HSE
				
*/
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT			RCC_PLL_IN_HSI_DIV_2
	/* PLL multiplexer value Options ==>  2 : 16 
		Options : 
			RCC_PLLMUL_X# : # from 2 to 16
	*/
	#define RCC_PLLMUL_VAL		 	RCC_PLLMUL_X4
#endif
#endif
