/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


		/*			PUBLIC FUNCTIONS  					*/	
		
		
/******************************************************************************
* Description : Initialize IRQ Event as selected in config file 
* Parameters  : none
* Return type : void 
******************************************************************************/
void EXTI_voidInitDefaultMode();
/******************************************************************************
* Description : enable external interrupt for line with selected event in config file
* Parameters  : Line number (0 : 15)
* Return type : void 
******************************************************************************/
void EXTI_voidEnableEXTIInDefaultMode(u8 Copy_u8LineID);
/******************************************************************************
* Description : Disable external interrupt 
* Parameters  : Line number (0 : 15)
* Return type : void 
******************************************************************************/
void EXTI_voidDisableEXTIInDefaultMode(u8 Copy_u8LineID);
/******************************************************************************
* Description : Software External Interrupt  
* Parameters  : Line number (0 : 15)
* Return type : void 
******************************************************************************/
void EXTI_voidSwTriggerInDefaultMode(u8 Copy_u8LineID);
/******************************************************************************
* Description : Enable External Interrupt and choose one of IRQ events
* Parameters  : Line number (0->15), IRQ event type
											For
												RISING write 0
												FALLIN	~	 1
												OnChange ~   2)
* Return type : void 
******************************************************************************/
void EXTI_VoidFullControlSignalLatch(u8 Copy_u8LineID , u8 Copy_u8IRQEvent  , u8 Copy_u8LineStatus );

/******************************************************************************
* Description : Call Back Function
* Parameters  : ,
* Return type : void 
******************************************************************************/
void EXTI_VoidSetCallBack(void(*Copy_ptr) (void));



#endif
