/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


		/*			PUBLIC FUNCTIONS  					*/	
		
		
/******************************************************************************
* Description : Initialize IRQ Event as selected in config file 
* Parameters  : External Interrupt Line Number  , And Pin Number Mapped With Line Number 
													AFIO_PIN_A : AFIO_PIN_G
													ex : Line Number = 0 SO WILL BE Pin A0
														 Line Number = 5 SO WILL BE Pin A5s										
* Return type : void 
******************************************************************************/
void AFIO_voidEXTIConfiguration(u8 Copy_u8LineID , u8 Copy_u8PinMap);

#endif
