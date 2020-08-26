/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V02                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2


		/*			PORT INPUT BIT CONFIGURATION  					*/	

#define	GPIO_INPUT_ANALOG					0b0000
#define	GPIO_INPUT_FLOATING					0b0100
#define	GPIO_PULLUP_PULLDOWN				0b1000

		/*			PORT OUTPUT BIT CONFIGURATION  					*/	
		
#define GPIO_OUTPUT_10MHZ_PUSH_PULL			0b0001
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN		0b0101
#define GPIO_OUTPUT_10MHZ_AF_PUSH_PULL		0b1001
#define GPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN		0b1101

#define GPIO_OUTPUT_2MHZ_PUSH_PULL			0b0010
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN			0b0110
#define GPIO_OUTPUT_2MHZ_AF_PUSH_PULL		0b1010
#define GPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN		0b1110

#define GPIO_OUTPUT_50MHZ_PUSH_PULL			0b0011
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN		0b0111
#define GPIO_OUTPUT_50MHZ_AF_PUSH_PULL		0b1011
#define GPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN		0b1111

		/*					PIN CONFIGURATION  					*/	
		
#define PIN0								0
#define PIN1								1
#define PIN2								2
#define PIN3								3
#define PIN4								4
#define PIN5								5
#define PIN6								6
#define PIN7								7
#define PIN8								8
#define PIN9								9
#define PIN10								10
#define PIN11								11
#define PIN12								12
#define PIN13								13
#define PIN14								14
#define PIN15								15

#define	HIGH								1
#define LOW									0

void GPIO_voidSetPinDirection	(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode);
void GPIO_voidSetPortDirection	(u8 Copy_u8Port, 				 u8 Copy_u8Mode);
void GPIO_voidSetPinValue		(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value);
void GPIO_voidSetPortValue		(u8 Copy_u8Port, 				 u8 Copy_u8Value);
void GPIO_voidTogglePinValue	(u8 Copy_u8Port, u8 Copy_u8Pin 					);
u8 	 GPIO_u8GetPinValue			(u8 Copy_u8Port, u8 Copy_u8Pin					);
//void GPIO_voidLockPin			(u8 Copy_u8Port, u8 Copy_u8Pin 					);






#endif
