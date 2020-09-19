/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V01                                                                 */
/* Date      : 17 September 2020                                                    */
/***********************************************************************************/

#ifndef DMA1_CONFIG_H
#define DMA1_CONFIG_H

/*
	*OPTIONS
			1	FOR ENABLE
			0	FOR DISABLE
*/
#define CHANNEL1_ENABLE		1
#define CHANNEL2_ENABLE		0
#define CHANNEL3_ENABLE		0
#define CHANNEL4_ENABLE		0
#define CHANNEL5_ENABLE		0
#define CHANNEL6_ENABLE		0
#define CHANNEL7_ENABLE		0


/*
	-> CHANNEL1_SOURCE_ADDRESS (peripheral)
			WRITE ADDRESS IF USE THE CHANNEL 
			0	 IF NOT USE CHANNEL 
	->CHANNEL1_DESTINATION_ADDRESS (memory)
			WRITE ADDRESS IF USE THE CHANNEL 
			0	 IF NOT USE CHANNEL 	
	-> BLOCK LENGTH	
		* WRTIE BLOCK LENGTH FOR SELECTED CHANNEL
	->CIRCLER PATTERN	
		* 1	USE PATTERN
		* 0	NOT USE PATTERN
	->CHANNELx_DIR
		* 0: Read from peripheral
		* 1: Read from memory
	->CHANNELx_PINC	(Peripheral increment mode)
		* 0: Peripheral increment mode disabled
		* 1: Peripheral increment mode enabled
	->CHANNELx_MINC	(Memory increment mode)
		* 0: Memory increment mode disabled
		* 1: Memory increment mode enabled
	->CHANNELx_PSIZE (Peripheral size) -Dependent on data 
		* 8  : 8-bit
		* 16 : 16-bit
		* 32 : 32-bit
	->CHANNELx_MSIZE (Memory size)
		* 8  : 8-bit
		* 16 : 16-bit
		* 32 : 32-bit
	->CHANNELx_PL	(Channel priority level)
		* 0	 : Low
		* 1  : Medium
		* 2  : High
		* 3  : Very high
	->CHANNELx_MEM2MEM	(Memory to memory mode - peripheral works as source - )
		* 0  : Memory to memory mode disabled
		* 1  : Memory to memory mode enabled 
*/
#if	CHANNEL1_ENABLE == 1
	#define CHANNEL1_SOURCE_ADDRESS				0x200
	#define CHANNEL1_DESTINATION_ADDRESS		0x400
	#define	CHANNEL1_BLOCK_LENGTH				1000
	#define	CHANNEL1_CIRCLE_PATTERN				0
	#define CHANNEL1_TC							0
	#define CHANNEL1_HTIE						0
	#define CHANNEL1_DIR						0
	#define CHANNEL1_PINC						1
	#define CHANNEL1_MINC						1
	#define CHANNEL1_PSIZE						32
	#define CHANNEL1_MSIZE						32
	#define CHANNEL1_PL							3
	#define CHANNEL1_MEM2MEM					1
	
	
#endif 
#if	CHANNEL2_ENABLE == 1
	#define CHANNEL2_SOURCE_ADDRESS				0
	#define CHANNEL2_DESTINATION_ADDRESS		0
	#define	CHANNEL2_BLOCK_LENGTH				0
	#define	CHANNEL2_CIRCLE_PATTERN				0
	#define	CHANNEL2_CIRCLE_PATTERN				0
	#define CHANNEL2_TC							0
	#define CHANNEL2_HTIE						0
	#define CHANNEL2_DIR						0
	#define CHANNEL2_PINC						1
	#define CHANNEL2_MINC						1
	#define CHANNEL2_PSIZE						32
	#define CHANNEL2_MSIZE						32
	#define CHANNEL2_PL							3
	#define CHANNEL2_MEM2MEM					1
#endif
#if	CHANNEL3_ENABLE == 1
	#define CHANNEL3_SOURCE_ADDRESS				0
	#define CHANNEL3_DESTINATION_ADDRESS		0
	#define	CHANNEL3_BLOCK_LENGTH				0
	#define	CHANNEL3_CIRCLE_PATTERN				0
	#define	CHANNEL3_CIRCLE_PATTERN				0
	#define CHANNEL3_TC							0
	#define CHANNEL3_HTIE						0
	#define CHANNEL3_DIR						0
	#define CHANNEL3_PINC						1
	#define CHANNEL3_MINC						1
	#define CHANNEL3_PSIZE						32
	#define CHANNEL3_MSIZE						32
	#define CHANNEL3_PL							3
	#define CHANNEL3_MEM2MEM					1
#endif
#if	CHANNEL4_ENABLE == 1
	#define CHANNEL4_SOURCE_ADDRESS				0
	#define CHANNEL4_DESTINATION_ADDRESS		0
	#define	CHANNEL4_BLOCK_LENGTH				0
	#define	CHANNEL4_CIRCLE_PATTERN				0
	#define	CHANNEL4_CIRCLE_PATTERN				0
	#define CHANNEL4_TC							0
	#define CHANNEL4_HTIE						0
	#define CHANNEL4_DIR						0
	#define CHANNEL4_PINC						1
	#define CHANNEL4_MINC						1
	#define CHANNEL4_PSIZE						32
	#define CHANNEL4_MSIZE						32
	#define CHANNEL4_PL							3
	#define CHANNEL4_MEM2MEM					1
#endif
#if	CHANNEL5_ENABLE == 1
	#define CHANNEL5_SOURCE_ADDRESS				0
	#define CHANNEL5_DESTINATION_ADDRESS		0
	#define	CHANNEL5_BLOCK_LENGTH				0
	#define	CHANNEL5_CIRCLE_PATTERN				0
	#define	CHANNEL5_CIRCLE_PATTERN				0
	#define CHANNEL5_TC							0
	#define CHANNEL5_HTIE						0
	#define CHANNEL5_DIR						0
	#define CHANNEL5_PINC						1
	#define CHANNEL5_MINC						1
	#define CHANNEL5_PSIZE						32
	#define CHANNEL5_MSIZE						32
	#define CHANNEL5_PL							3
	#define CHANNEL5_MEM2MEM					1
#endif
#if	CHANNEL6_ENABLE == 1
	#define CHANNEL6_SOURCE_ADDRESS				0
	#define CHANNEL6_DESTINATION_ADDRESS		0
	#define	CHANNEL6_BLOCK_LENGTH				0
	#define	CHANNEL6_CIRCLE_PATTERN				0
	#define	CHANNEL6_CIRCLE_PATTERN				0
	#define CHANNEL6_TC							0
	#define CHANNEL6_HTIE						0
	#define CHANNEL6_DIR						0
	#define CHANNEL6_PINC						1
	#define CHANNEL6_MINC						1
	#define CHANNEL6_PSIZE						32
	#define CHANNEL6_MSIZE						32
	#define CHANNEL6_PL							3
	#define CHANNEL6_MEM2MEM					1
#endif
#if	CHANNEL7_ENABLE == 1
	#define CHANNEL7_SOURCE_ADDRESS				0
	#define CHANNEL7_DESTINATION_ADDRESS		0
	#define	CHANNEL7_BLOCK_LENGTH				0
	#define	CHANNEL7_CIRCLE_PATTERN				0
	#define	CHANNEL7_CIRCLE_PATTERN				0
	#define CHANNEL7_TC							0
	#define CHANNEL7_HTIE						0
	#define CHANNEL7_DIR						0
	#define CHANNEL7_PINC						1
	#define CHANNEL7_MINC						1
	#define CHANNEL7_PSIZE						32
	#define CHANNEL7_MSIZE						32
	#define CHANNEL7_PL							3
	#define CHANNEL7_MEM2MEM					1
#endif 


#endif

