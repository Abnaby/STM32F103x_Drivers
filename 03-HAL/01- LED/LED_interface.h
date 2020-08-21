/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 18 August 2020                                                    */
/*********************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


		/*			 public functions prototypes		 */

/*****************************************************************************************
* Description : Turning LED
* Parameters  : PORT number (GPIOA -> GPIOC), PIN number(PIN0 -> PIN0) , Copy_u8Mode
* Return type : void
******************************************************************************************/

void LED_voidTurnOn  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode); 


/*****************************************************************************************
* Description : Turning LED ON
* Parameters  : PORT number (GPIOA -> GPIOC), PIN number(PIN0 -> PIN0) , Copy_u8Mode
* Return type : void
******************************************************************************************/

void LED_voidTurnOff (u8 Copy_u8Port , u8 Copy_u8Pin 				 ); 


/*****************************************************************************************
* Description : Turning LED	OFF
* Parameters  : PORT number (GPIOA -> GPIOC), PIN number(PIN0 -> PIN0)
* Return type : void
******************************************************************************************/

void LED_voidToggle	 (u8 Copy_u8Port , u8 Copy_u8Pin 			     ); 


/*****************************************************************************************
* Description : Turning LED
* Parameters  : PORT number (GPIOA -> GPIOC), PIN number(PIN0 -> PIN0) , Copy_u8Mode
* Return type : u8 1 or 0 
******************************************************************************************/
u8 LED_u8State 		 (u8 Copy_u8Port , u8 Copy_u8Pin				 ); 




#endif