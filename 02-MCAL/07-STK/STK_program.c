/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V02                                                                 */
/* Date      : 3 September 2020                                                    */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/* Define Callback Global Variable */
void (*Callback) (void) = NULL ;
/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;

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
static u32 STK_u32ConfigIntervalMS(void)
{
	u32	LOC_u32Freq = 0 ;
	#if STK_CLK_SOURCE_SELECTION == STK_AHB
		LOC_u32Freq = AHP_CLOCK_FREQ ; 
	#elif STK_CLK_SOURCE_SELECTION == STK_AHB_OVER_8
		LOC_u32Freq = AHP_CLOCK_FREQ /8  ; 
	#else
		#error "Choose Correct Clock Source From Config File"
	#endif
	return LOC_u32Freq / STK_GENERATE_1_MS ; 
}
static u32 STK_u32ConfigIntervalUS(void)
{
	u32	LOC_u32Freq = 0 ;
	#if STK_CLK_SOURCE_SELECTION == STK_AHB
		LOC_u32Freq = AHP_CLOCK_FREQ ; 
	#elif STK_CLK_SOURCE_SELECTION == STK_AHB_OVER_8
		LOC_u32Freq = AHP_CLOCK_FREQ /8  ; 
	#else
		#error "Choose Correct Clock Source From Config File"
	#endif
	return LOC_u32Freq / STK_GENERATE_1_US ; 
}

void STK_voidSetBusyWait(u32 Copy_u32TicksNumber)
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		u8 LOC_u8FlagStatus = 0 ;
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		LOC_u8FlagStatus = GET_BIT((STK -> STK_CTRL) , 16 ) ; 
		while( LOC_u8FlagStatus == 0 );
		/* Stop Timer */
		CLR_BIT(STK->STK_CTRL, 0);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL  = 0;
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetBusyWait_MS(u16 Copy_u16TimeMS)
{
	u32 Copy_u32TicksNumber = Copy_u16TimeMS * STK_u32ConfigIntervalMS() ; 
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		u8 LOC_u8FlagStatus = 0 ;
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		LOC_u8FlagStatus = GET_BIT((STK -> STK_CTRL) , 16 ) ; 
		while( LOC_u8FlagStatus == 0 );
		/* Stop Timer */
		CLR_BIT(STK->STK_CTRL, 0);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL  = 0;
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetBusyWait_US(u16 Copy_u16TimeUS)
{
	u32 Copy_u32TicksNumber = Copy_u16TimeUS * STK_u32ConfigIntervalUS() ; 
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		u8 LOC_u8FlagStatus = 0 ;
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		LOC_u8FlagStatus = GET_BIT((STK -> STK_CTRL) , 16 ) ; 
		while( LOC_u8FlagStatus == 0 );
		/* Stop Timer */
		CLR_BIT(STK->STK_CTRL, 0);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL  = 0;
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalSingle(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void))
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	START TIMER */
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Callback = Copy_ptrIntFunc ; 
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalSingle_MS(u16 Copy_u16TimeMS , void (*Copy_ptrIntFunc) (void))
{
	u32 Copy_u32TicksNumber = Copy_u16TimeMS * STK_u32ConfigIntervalMS() ;
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	START TIMER */
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Callback = Copy_ptrIntFunc ; 
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalSingle_US(u16 Copy_u16TimeUS , void (*Copy_ptrIntFunc) (void))
{
	u32 Copy_u32TicksNumber = Copy_u16TimeUS * STK_u32ConfigIntervalUS() ;
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	START TIMER */
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Callback = Copy_ptrIntFunc ; 
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNumber , void (*Copy_ptrIntFunc) (void))
{
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Copy_ptrIntFunc = Callback  ;
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalPeriodic_MS(u16 Copy_u16TimeMS , void (*Copy_ptrIntFunc) (void))
{
	u32 Copy_u32TicksNumber = Copy_u16TimeMS * STK_u32ConfigIntervalMS() ;
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Copy_ptrIntFunc = Callback  ;
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidSetIntervalPeriodic_US(u16 Copy_u16TimeUS , void (*Copy_ptrIntFunc) (void))
{
	u32 Copy_u32TicksNumber = Copy_u16TimeUS * STK_u32ConfigIntervalUS() ;
	if (Max_Number_Count > Copy_u32TicksNumber )
	{
		/*	DISABLE TIMER  */
		CLR_BIT((STK -> STK_CTRL) , 0);
		/*	WRITING Copy_u32TicksNumber TO LOAD REGISTER	*/
		(STK -> STK_LOAD ) = Copy_u32TicksNumber ; 
		/*	ENABLE SYSTIC	*/
		SET_BIT((STK -> STK_CTRL) , 0);
		/*	SAVE CALLBACK	*/
		Copy_ptrIntFunc = Callback  ;
		/* Set Mode to Single */
		STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
		/*	ENABLE INTERRUPT	*/
		SET_BIT((STK -> STK_CTRL) , 1);

		
	}
	else{ /* <!TODO> ERROR */ }
}
void STK_voidStopInterval(void)
{
	/*	For ASynchronous	*/
	/*	DISABLE INTERRUPT	*/
	SET_BIT((STK -> STK_CTRL) , 1);
}
u32 STK_u32GetElapsedTicks(void)
{
	u32 LOC_u32ElapsedTicks = 0 ;
	LOC_u32ElapsedTicks = ( STK -> STK_LOAD ) - ( STK -> STK_VAL ) ;
	return LOC_u32ElapsedTicks ; 
}
u32 STK_u32GetElapsedTime_MS(void)
{
	u32 LOC_u32ElapsedTime = 0 ;
	LOC_u32ElapsedTime = ( STK -> STK_LOAD ) - ( STK -> STK_VAL ) ;
	LOC_u32ElapsedTime = LOC_u32ElapsedTime / STK_u32ConfigIntervalMS();
	return LOC_u32ElapsedTime ; 
}
u32 STK_u32GetElapsedTime_US(void)
{
	u32 LOC_u32ElapsedTime = 0 ;
	LOC_u32ElapsedTime = ( STK -> STK_LOAD ) - ( STK -> STK_VAL ) ;
	LOC_u32ElapsedTime = LOC_u32ElapsedTime / STK_u32ConfigIntervalUS();
	return LOC_u32ElapsedTime ; 
}
u32 STK_u32GetRemainingTicks(void)
{
	u32 LOC_u32RemainingTicks = 0 ;
	LOC_u32RemainingTicks = ( STK -> STK_VAL ) ;
	return LOC_u32RemainingTicks ; 
}
u32 STK_u32GetRemainingTime_MS(void)
{
	u32 LOC_u32RemainingTime = 0 ;
	LOC_u32RemainingTime = ( STK -> STK_VAL ) ;
	LOC_u32RemainingTime = LOC_u32RemainingTime /STK_u32ConfigIntervalMS();
	return LOC_u32RemainingTime ; 
}
u32 STK_u32GetRemainingTime_US(void)
{
	u32 LOC_u32RemainingTime = 0 ;
	LOC_u32RemainingTime = ( STK -> STK_VAL ) ;
	LOC_u32RemainingTime = LOC_u32RemainingTime / STK_u32ConfigIntervalUS();
	return LOC_u32RemainingTime ; 
}
void SysTick_Handler(void) {
	u8 Local_u8Temporary = 0;
	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->STK_CTRL, 1);
		/*	Stop Timer	*/
		CLR_BIT(STK->STK_CTRL, 0);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL  = 0;
	}
	
	/* Callback notification */
	Callback();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->STK_CTRL,16);

	
}
