/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 28 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
void (*Callback) (void) ;
void STK_voidInit(void)
{
	#if STK_CLK_SOURCE_SELECTION == STK_AHB
		SET_BIT((STK -> STK_CTRL) , 2 );
	#elif STK_CLK_SOURCE_SELECTION == STK_AHB_OVER_8
		CLR_BIT((STK -> STK_CTRL) , 2 );
	#else
		#error "Choose Correct Clock Source From Config File"
	#endif
}

void STK_voidSetBusyWait(u32 Copy_u32TicksNumber)
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		u8 LOC_u8FlagStatus = 0 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		LOC_u8FlagStatus = GET_BIT((STK -> STK_CTRL) , 16 ) ; 
		while( LOC_u8FlagStatus != 1 ); 
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalSingle(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void))
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{	/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		Copy_ptrIntFunc = Callback  ; 
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void))
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{	/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		Copy_ptrIntFunc = Callback  ;
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidStopInterval(void)
{
	/*	For ASynchronous	*/
	/*	DISABLE INTERRUPT	*/
	SET_BIT((STK -> STK_CTRL) , 1);
}
u32 STK_u32GetElapsedTime(void)
{
	u32 LOC_u32ElapsedTime = 0 ;
	LOC_u32ElapsedTime = ( STK -> STK_LOAD ) - ( STK -> STK_VAL ) ;
	return LOC_u32ElapsedTime ; 
}
u32 STK_u32GetRemainingTime(void)
{
	u32 LOC_u32RemainingTime = 0 ;
	LOC_u32RemainingTime = ( STK -> STK_VAL ) ;
	return LOC_u32RemainingTime ; 
}
void SysTick_Handler(void) {
	Callback();
}