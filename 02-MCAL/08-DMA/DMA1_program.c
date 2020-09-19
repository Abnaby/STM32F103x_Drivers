/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V01                                                                 */
/* Date      : 17 September 2020                                                   */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA1_interface.h"
#include "DMA1_private.h"
#include "DMA1_config.h"
/* Define Callback Global Variable */


void DMA1_voidChannelInit(void)
{
	/*	AT FIRST MAKE SURE CHANNEL IS DISABLED	*/
	for(u8 Channel_ID = 0 ; Channel_ID < 7 ; Channel_ID++)
	{
		DMA1 -> Channel[Channel_ID].CCR   = 0x00000000 ; 
		DMA1 -> Channel[Channel_ID].CNDTR = 0x00000000 ; 
		DMA1 -> Channel[Channel_ID].CPAR  = 0x00000000 ; 
		DMA1 -> Channel[Channel_ID].CMAR  = 0x00000000 ; 
	}
	DMA1 -> IFCR = 0x11111111 ;
	#if CHANNEL1_ENABLE == 1
		/*	WRITE ADDRESSES	*/
		DMA1 -> Channel[0].CPAR  = CHANNEL1_SOURCE_ADDRESS ; 
		DMA1 -> Channel[0].CMAR  = CHANNEL1_DESTINATION_ADDRESS ;
		/*	BLOCK LENGTH */
		DMA1 -> Channel[0].CNDTR = CHANNEL1_BLOCK_LENGTH ;
		/*	DATA DIRECTION	*/
		#if CHANNEL1_DIR == 1 
		SET_BIT(DMA1 -> Channel[0].CCR ,	DIR ) ; 
		#endif
		/*	CIRCULAR MODE	*/
		#if CHANNEL1_CIRCLE_PATTERN == 1 
		SET_BIT(DMA1 -> Channel[0].CCR ,	CIRC ) ;
		#endif
		/*	Peripheral increment mod	*/
		#if CHANNEL1_PINC == 1
		SET_BIT (DMA1 -> Channel[0].CCR , PINC );
		#endif
		/*	Memory increment mod */
		
		#if CHANNEL1_MINC == 1 
		SET_BIT (DMA1 -> Channel[0].CCR , MINC );
		#endif
		
		/*	Peripheral size	*/
		#if CHANNEL1_PSIZE == 8 
			CLR_BIT(DMA1 -> Channel[0].CCR , PSIZE0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , PSIZE1 );
		#elif CHANNEL1_PSIZE == 16
			SET_BIT(DMA1 -> Channel[0].CCR , PSIZE0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , PSIZE1 );
		#elif CHANNEL1_PSIZE == 32 
			CLR_BIT(DMA1 -> Channel[0].CCR , PSIZE0 );
			SET_BIT(DMA1 -> Channel[0].CCR , PSIZE1 );		
		#else
			//<! TODO ERROR >
		#endif
		
		/*	Memory size	*/
		#if CHANNEL1_MSIZE == 8 
			CLR_BIT(DMA1 -> Channel[0].CCR , MSIZE0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , MSIZE1 );
		#elif CHANNEL1_MSIZE == 16
			SET_BIT(DMA1 -> Channel[0].CCR , MSIZE0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , MSIZE1 );
		#elif CHANNEL1_MSIZE == 32 
			CLR_BIT(DMA1 -> Channel[0].CCR , MSIZE0 );
			SET_BIT(DMA1 -> Channel[0].CCR , MSIZE1 );		
		#else
			//<! TODO ERROR >
		#endif
		/*	Channel priority level	*/
		#if CHANNEL1_PL == 0
			CLR_BIT(DMA1 -> Channel[0].CCR , PL0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , PL1 );
		#elif CHANNEL1_PL == 1
			SET_BIT(DMA1 -> Channel[0].CCR , PL0 );
			CLR_BIT(DMA1 -> Channel[0].CCR , PL1 );
		#elif CHANNEL1_PL == 2
			CLR_BIT(DMA1 -> Channel[0].CCR , PL0 );
			SET_BIT(DMA1 -> Channel[0].CCR , PL1 );
		#elif CHANNEL1_PL == 3
			SET_BIT(DMA1 -> Channel[0].CCR , PL0 );
			SET_BIT(DMA1 -> Channel[0].CCR , PL1 );
		#else 
			// <! TODO ERROT >
		#endif
		/* MEMMORY TO MEMMORY	*/
		#if CHANNEL1_MEM2MEM == 1 
			SET_BIT(DMA1 -> Channel[0].CCR , MEM2MEM );
		#endif
		/*	FINALLY ENABLE CHANNEL */
		SET_BIT(DMA1 -> Channel[0].CCR ,	EN ) ; 	
	#endif
	
	#if CHANNEL2_ENABLE	== 1
		/*	WRITE ADDRESSES	*/
		DMA1 -> Channel[1].CPAR  = CHANNEL2_SOURCE_ADDRESS ; 
		DMA1 -> Channel[1].CMAR  = CHANNEL2_DESTINATION_ADDRESS ;
		/*	BLOCK LENGTH */
		DMA1 -> Channel[1].CNDTR = CHANNEL2_BLOCK_LENGTH ;
		/*	DATA DIRECTION	*/
		#if CHANNEL2_DIR == 1 
		SET_BIT(DMA1 -> Channel[1].CCR ,	DIR ) ; 
		#endif
		/*	CIRCULAR MODE	*/
		#if CHANNEL2_CIRCLE_PATTERN == 1 
		SET_BIT(DMA1 -> Channel[1].CCR ,	CIRC ) ;
		#endif
		/*	Peripheral increment mod	*/
		#if CHANNEL2_PINC == 1
		SET_BIT (DMA1 -> Channel[1].CCR , PINC );
		#endif
		/*	Memory increment mod */
		
		#if CHANNEL2_MINC == 1 
		SET_BIT (DMA1 -> Channel[1].CCR , MINC );
		#endif
		
		/*	Peripheral size	*/
		#if CHANNEL2_PSIZE == 8 
			CLR_BIT(DMA1 -> Channel[1].CCR , PSIZE0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , PSIZE1 );
		#elif CHANNEL2_PSIZE == 16
			SET_BIT(DMA1 -> Channel[1].CCR , PSIZE0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , PSIZE1 );
		#elif CHANNEL2_PSIZE == 32 
			CLR_BIT(DMA1 -> Channel[1].CCR , PSIZE0 );
			SET_BIT(DMA1 -> Channel[1].CCR , PSIZE1 );		
		#else
			//<! TODO ERROR >
		#endif
		
		/*	Memory size	*/
		#if CHANNEL2_MSIZE == 8 
			CLR_BIT(DMA1 -> Channel[1].CCR , MSIZE0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , MSIZE1 );
		#elif CHANNEL2_MSIZE == 16
			SET_BIT(DMA1 -> Channel[1].CCR , MSIZE0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , MSIZE1 );
		#elif CHANNEL2_MSIZE == 32 
			CLR_BIT(DMA1 -> Channel[1].CCR , MSIZE0 );
			SET_BIT(DMA1 -> Channel[1].CCR , MSIZE1 );		
		#else
			//<! TODO ERROR >
		#endif
		/*	Channel priority level	*/
		#if CHANNEL2_PL == 0
			CLR_BIT(DMA1 -> Channel[1].CCR , PL0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , PL1 );
		#elif CHANNEL2_PL == 1
			SET_BIT(DMA1 -> Channel[1].CCR , PL0 );
			CLR_BIT(DMA1 -> Channel[1].CCR , PL1 );
		#elif CHANNEL2_PL == 2
			CLR_BIT(DMA1 -> Channel[1].CCR , PL0 );
			SET_BIT(DMA1 -> Channel[1].CCR , PL1 );
		#elif CHANNEL2_PL == 3
			SET_BIT(DMA1 -> Channel[1].CCR , PL0 );
			SET_BIT(DMA1 -> Channel[1].CCR , PL1 );
		#else 
			// <! TODO ERROT >
		#endif
		/* MEMMORY TO MEMMORY	*/
		#if CHANNEL2_MEM2MEM == 1 
			SET_BIT(DMA1 -> Channel[1].CCR , MEM2MEM );
		#endif
		/*	FINALLY ENABLE CHANNEL */
		SET_BIT(DMA1 -> Channel[1].CCR ,	EN ) ; 
	#endif
	#if CHANNEL3_ENABLE	== 1
	#endif
	#if CHANNEL4_ENABLE	== 1
	#endif
	#if CHANNEL5_ENABLE	== 1
	#endif
	#if CHANNEL6_ENABLE	== 1
	#endif
	#if CHANNEL7_ENABLE	== 1
	#endif
}
void DMA1_voidChannelFullControl(u8 Copy_u8ChannelNum , u32 *Copy_Pu32SourceAddress 			,
								 u32 *Copy_Pu32DistinationAddress , u16 Copy_u16BlockLength 	,
								 u8 Copy_u8ReadDir ,u8 Copy_u8CircularMode , u8 Copy_u8PerINC	,
								 u8 Copy_u8MemINC , u8 Copy_u8PerSize ,u8 Copy_u8MemSize		,
								 u8 Copy_u8ChannelPriority , u8 Copy_u8EnableMEM2MEM )
{
	if(Copy_u8ChannelNum >= 1 && Copy_u8ChannelNum <= 7)
	{
		/*	INTIT	*/
		/*	AT FIRST MAKE SURE CHANNEL IS DISABLED	*/
		for(u8 Channel_ID = 0 ; Channel_ID < 7 ; Channel_ID++)
		{
			DMA1 -> Channel[Channel_ID].CCR   = 0x00000000 ; 
			DMA1 -> Channel[Channel_ID].CNDTR = 0x00000000 ; 
			DMA1 -> Channel[Channel_ID].CPAR  = 0x00000000 ; 
			DMA1 -> Channel[Channel_ID].CMAR  = 0x00000000 ; 
		}
		DMA1 -> IFCR = 0x11111111 ;
		/*	Channel Number From 1 : 7 ---> 0 : 6 In Array */
		Copy_u8ChannelNum = Copy_u8ChannelNum - 1 ; 
		DMA1 -> Channel[Copy_u8ChannelNum].CPAR  = Copy_Pu32SourceAddress ; 
		DMA1 -> Channel[Copy_u8ChannelNum].CMAR  = Copy_Pu32DistinationAddress ;
		/*	BLOCK LENGTH RANGE CHEEKER	*/
		if ( Copy_u16BlockLength <= DMA1_MAX_NUM_OF_DATA_TRANSFERRED)
		{
			DMA1 -> Channel[Copy_u8ChannelNum].CNDTR = Copy_u16BlockLength ;
		}
		else{
			// <!TODO DATA BLOCK OUTOF AVG >
		}
		/*	DATA DIRECTION	*/
		switch(Copy_u8ReadDir)
		{
			case DMA1_READ_FROM_PER	:CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , DIR );	break; 
			case DMA1_READ_FROM_MEM :SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , DIR );	break;
			default					: /* <! TODO WRONG CHOICSE	*/	break ; 
		}
		switch(Copy_u8CircularMode)
		{
			case DMA1_DISABLE_CIRC_MODE	:CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , CIRC );	break; 
			case DMA1_ENABLE_CIRC_MODE  :SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , CIRC );	break;
			default					: /* <! TODO WRONG CHOICSE	*/	break ; 
		}
		switch(Copy_u8PerINC)
		{
			case DMA1_DISABLE_PINC	:CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PINC );	break; 
			case DMA1_ENABLE_PINC   :SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PINC );	break;
			default					: /* <! TODO WRONG CHOICSE	*/	break ; 
		}
		switch(Copy_u8MemINC)
		{
			case DMA1_DISABLE_MINC	:CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MINC );	break; 
			case DMA1_ENABLE_MINC   :SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MINC );	break;
			default					: /* <! TODO WRONG CHOICSE	*/	break ; 
		}
		switch(Copy_u8PerSize)
		{
			case DMA1_PER_8BIT 	  :
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE0 );
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE1 );
									break; 
			case DMA1_PER_16BIT   :
									SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE0 );
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE1 );
									break;
			case DMA1_PER_32BIT   :
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE0 );
									SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PSIZE1 );
									break;
			default				  : /* <! TODO WRONG CHOICSE	*/	break ; 
		}
		switch(Copy_u8MemSize)
		{
			case DMA1_MEM_8BIT 	  :
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE0 );
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE1 );
									break; 
			case DMA1_MEM_16BIT   :
									SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE0 );
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE1 );
									break;
			case DMA1_MEM_32BIT   :
									CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE0 );
									SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MSIZE1 );
									break;
			default				  : /* <! TODO WRONG CHOICSE	*/	break ; 
		}		
		switch(Copy_u8ChannelPriority)
		{
			case DMA1_PL_VERY_HIGH 	  :
										SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL0 );
										SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL1 );
										break; 
			case DMA1_PL_HIGH    	  :
										CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL0 );
										SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL1 );
										break;
			case DMA1_PL_MEDIUM  	  :
										SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL0 );
										CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL1 );
										break;
			case DMA1_PL_LOW 		 :
										CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL0 );
										CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , PL1 );
										break;
			default				     : /* <! TODO WRONG CHOICSE	*/	break ; 
		}		
		switch(Copy_u8EnableMEM2MEM)
		{
			case DMA1_ENABLE_MEM2MEM  :
										SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MEM2MEM );
										break; 
			case DMA1_DISABLE_MEM2MEM :
										CLR_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR , MEM2MEM );
										break;
			default				      : /* <! TODO WRONG CHOICSE	*/	break ; 
		}		

		/*	ENABLE CHANNEL */
		SET_BIT(DMA1 -> Channel[Copy_u8ChannelNum].CCR ,	EN ) ; 
		
	}
	else
	{
		// <! TODO Channel Number Error > 
	}
	
}
void DMA1_voidTransferCompleteINT(void (*Ref_CallBack) (void))
{
	Global_u8IntType = 2 ; 
	Global_Callback = Ref_CallBack ;
}
void DMA1_voidTransferHalfCompleteINT(void (*Ref_CallBack) (void))
{
	Global_u8IntType = 4 ;
	Global_Callback = Ref_CallBack ;
}
void DMA1_voidTransferErrorINT(void (*Ref_CallBack) (void))
{
	Global_u8IntType = 6 ;
	Global_Callback = Ref_CallBack ;
} 

static void DMA1_Channel1_IRQHandler(void)
{
	/* Clear GIF	*/
	SET_BIT(DMA1 -> IFCR , CGIF1);
	Global_Callback();
	if (Global_u8IntType == 2 )
	{
		/* 	TC INTIT	*/
		/* Clear TCF	*/
		SET_BIT(DMA1 ->IFCR , CTCIF1) ; 
	}		
	if (Global_u8IntType == 4 )
	{
		/* 	HTC INTIT	*/
		SET_BIT(DMA1 ->IFCR , CHTIF1) ; 
	}		
	if (Global_u8IntType == 6 )
	{
		/* 	EC INTIT	*/
		SET_BIT(DMA1 ->IFCR , CTEIF1) ; 
	}		
}
static void DMA2_Channel2_IRQHandler(void)
{
		Global_Callback();
}
static void DMA1_Channel3_IRQHandler(void)
{
		Global_Callback();
}
static void DMA1_Channel4_IRQHandler(void)
{
		Global_Callback();
}
static void DMA1_Channel5_IRQHandler(void)
{
		Global_Callback();
}
static void DMA1_Channel6_IRQHandler(void)
{
		Global_Callback();
}
static void DMA1_Channel7_IRQHandler(void)
{
		Global_Callback();
}
