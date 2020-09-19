/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V02                                                                 */
/* Date      : 3 September 2020                                                    */
/***********************************************************************************/


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
* Description : Synchronous Function Delay
				
* Parameters  : Number of Counts or Ticks								
* Return type : void 
******************************************************************************/
void STK_voidSetBusyWait(u32 Copy_u32TicksNumber) ;

/******************************************************************************
* Description : Synchronous Function Delay
				
* Parameters  : Time In Millisecond 							
* Return type : void 
******************************************************************************/
void STK_voidSetBusyWait_MS(u16 Copy_u16TimeMS) ;

/******************************************************************************
* Description : Synchronous Function Delay
				
* Parameters  : Time In Micro-second								
* Return type : void 
******************************************************************************/
void STK_voidSetBusyWait_US(u16 Copy_u16TimeUS) ;

/******************************************************************************
* Description : Single ASynchronous Function 
				Just Finish it will make interrupt
				
* Parameters  : Number of Counts or Ticks	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalSingle(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void)) ;
/******************************************************************************
* Description : Single ASynchronous Function 
				Just Finish it will make interrupt
				
* Parameters  : Time In Millisecond	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalSingle_MS(u16 Copy_u16TimeMS , void (*Copy_ptrIntFunc) (void)) ;

/******************************************************************************
* Description : Single ASynchronous Function 
				Just Finish it will make interrupt
				
* Parameters  : Time In Microsecond	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalSingle_US(u16 Copy_u16TimeUS , void (*Copy_ptrIntFunc) (void)) ;


/******************************************************************************
* Description : Periodic ASynchronous Function
				Just Finish it will make interrupt
				
* Parameters  : Number of Counts or Ticks	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void)) ;


/******************************************************************************
* Description : Periodic ASynchronous Function
				Just Finish it will make interrupt
				
* Parameters  : Time In Millisecond	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalPeriodic_MS(u16 Copy_u16TimeMS , void (*Copy_ptrIntFunc) (void)) ;


/******************************************************************************
* Description : Periodic ASynchronous Function
				Just Finish it will make interrupt
				
* Parameters  : Time In Microsecond	, 
				Pointer to Interrupt Function execude when happen Interrupt 							
* Return type : void 
******************************************************************************/
void STK_voidSetIntervalPeriodic_US(u16 Copy_u16TimeUS , void (*Copy_ptrIntFunc) (void)) ;

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
u32 STK_u32GetElapsedTicks(void) ;
/******************************************************************************
* Description : Get Elapsed Time				
* Parameters  : void 							
* Return type : u32  : Elapsed Time in Millisecond
******************************************************************************/
u32 STK_u32GetElapsedTime_MS(void) ;
/******************************************************************************
* Description : Get Elapsed Time 				
* Parameters  : void 							
* Return type : u32  : Elapsed Time in Microsecond
******************************************************************************/
u32 STK_u32GetElapsedTime_US(void) ;
/******************************************************************************
* Description : Get Remaning Ticks 			
* Parameters  : void 							
* Return type : u32  : Number Of Remaning Ticks 
******************************************************************************/
u32 STK_u32GetRemainingTicks(void) ;
/******************************************************************************
* Description : Get Remaning Time 			
* Parameters  : void 							
* Return type : u32  : Remaning Time in Millisecond 
******************************************************************************/
u32 STK_u32GetRemainingTime_MS(void) ;
/******************************************************************************
* Description : Get Remaning Time 			
* Parameters  : void 							
* Return type : u32  : Remaning Time in Microsecond 
******************************************************************************/
u32 STK_u32GetRemainingTime_US(void) ;
#endif
