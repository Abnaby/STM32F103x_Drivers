/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


		/*			PUBLIC FUNCTIONS  					*/	
		
		
/******************************************************************************
* Description : Apply clock choice from config file
				Disable SysTic Interrupt 
				Disable SysTic
* Parameters  : void								
* Return type : void 
******************************************************************************/
void STK_voidInit(void) ;

/******************************************************************************
* Description : Synchronous Function
				
* Parameters  : Number of Counts or Ticks								
* Return type : void 
******************************************************************************/
void STK_voidSetBusyWait(u32 Copy_u32TicksNumber) ;

/******************************************************************************
* Description : Single ASynchronous Function 
				Just Finish it will make interrupt
				
* Parameters  : Number of Counts or Ticks	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalSingle(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void)) ;

/******************************************************************************
* Description : Periodic ASynchronous Function
				Just Finish it will make interrupt
				
* Parameters  : Number of Counts or Ticks	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void)) ;

/******************************************************************************
* Description : Stop ASynchronous Interval 				
* Parameters  : void 							
* Return type : void 
******************************************************************************/
void STK_voidStopInterval(void) ;

/******************************************************************************
* Description : Get Number Of Successfully Ticks 				
* Parameters  : void 							
* Return type : u32  : How many ticks done 
******************************************************************************/
u32 STK_u32GetElapsedTime(void) ;

/******************************************************************************
* Description : Get Remaning Time 			
* Parameters  : void 							
* Return type : u32  : Number Of Remaning Ticks 
******************************************************************************/
u32 STK_u32GetRemainingTime(void) ;
#endif
