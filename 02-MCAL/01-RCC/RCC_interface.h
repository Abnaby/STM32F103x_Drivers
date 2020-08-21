/**************************************************************************/
/* Author	: Mohamed                                                     */
/* Date		: 8 AUG 2020                                                 */
/* Version	: V01							                              */
/**************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define ON 									1
#define OFF 								0	


#define  RCC_AHB							0						
#define	 RCC_APB1							1						
#define  RCC_APB2							2	


/* Clock OPTIONS */ 
#define	RCC_HSE_CRYSTAL						0
#define	RCC_HSE_RC							1
#define	RCC_HSI								2
#define	RCC_PLL 							3
				
/* PLL OPTIONS */
#define RCC_PLL_IN_HSI_DIV_2				0
#define	RCC_PLL_IN_HSE_DIV_2				1
#define	RCC_PLL_IN_HSE						2

/* PLLMUL */

#define RCC_PLLMUL_X2						2
#define RCC_PLLMUL_X3						3
#define RCC_PLLMUL_X4						4
#define RCC_PLLMUL_X5						5
#define RCC_PLLMUL_X6						6
#define RCC_PLLMUL_X7						7
#define RCC_PLLMUL_X8						8
#define RCC_PLLMUL_X9						9
#define RCC_PLLMUL_X10						10
#define RCC_PLLMUL_X11						11
#define RCC_PLLMUL_X12						12
#define RCC_PLLMUL_X13						13
#define RCC_PLLMUL_X14						14
#define RCC_PLLMUL_X15						15
#define RCC_PLLMUL_X16						16

/* AHB prescaler */
#define RCC_AHB_prescaler_NOT_DEV			0
#define RCC_AHB_prescaler_SYSCLK_DIV_2		1
#define RCC_AHB_prescaler_SYSCLK_DIV_4		2
#define RCC_AHB_prescaler_SYSCLK_DIV_6		3
#define RCC_AHB_prescaler_SYSCLK_DIV_8		4
#define RCC_AHB_prescaler_SYSCLK_DIV_16		5
#define RCC_AHB_prescaler_SYSCLK_DIV_64		6
#define RCC_AHB_prescaler_SYSCLK_DIV_128	7
#define RCC_AHB_prescaler_SYSCLK_DIV_256	8
#define RCC_AHB_prescaler_SYSCLK_DIV_512	9

/* APB1	prescaler */
#define RCC_APB1_prescaler_AHB_NOT_DEV		0
#define RCC_APB1_prescaler_AHB_DIV_2		1
#define RCC_APB1_prescaler_AHB_DIV_4		2
#define RCC_APB1_prescaler_AHB_DIV_8		3
#define RCC_APB1_prescaler_AHB_DIV_16		4
/* APB2	prescaler */
#define RCC_APB2_prescaler_AHB_NOT_DEV		0
#define RCC_APB2_prescaler_AHB_DIV_2		1
#define RCC_APB2_prescaler_AHB_DIV_4		2
#define RCC_APB2_prescaler_AHB_DIV_8		3
#define RCC_APB2_prescaler_AHB_DIV_16		4

/* FUNCTION PROTOTYPES */
void RCC_voidEnableClock(u8 Copy_u8Bus , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8Bus , u8 Copy_u8PerId);
void RCC_voidInititSysClock(void);


#endif