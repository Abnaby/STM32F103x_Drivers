/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V01                                                                 */
/* Date      : 17 September 2020                                                   */
/***********************************************************************************/


#ifndef DMA1_INTERFACE_H
#define DMA1_INTERFACE_H
		/*			USER KEYWORDS						*/
#define	DMA1_READ_FROM_PER		0
#define	DMA1_READ_FROM_MEM		1

#define DMA1_ENABLE_CIRC_MODE 	1
#define DMA1_DISABLE_CIRC_MODE 	0

#define DMA1_ENABLE_PINC		1
#define DMA1_DISABLE_PINC		0

#define DMA1_ENABLE_MINC		1
#define DMA1_DISABLE_MINC		0

#define DMA1_PER_8BIT			8
#define DMA1_PER_16BIT			16
#define DMA1_PER_32BIT			32

#define DMA1_MEM_8BIT			8
#define DMA1_MEM_16BIT			16
#define DMA1_MEM_32BIT			32

#define DMA1_PL_VERY_HIGH		20
#define DMA1_PL_HIGH			10
#define	DMA1_PL_MEDIUM			5
#define DMA1_PL_LOW				0

#define DMA1_ENABLE_MEM2MEM		1
#define DMA1_DISABLE_MEM2MEM	0

#define	DMA1_CHANNEL1	1
#define	DMA1_CHANNEL2	2
#define	DMA1_CHANNEL3	3
#define	DMA1_CHANNEL4	4
#define	DMA1_CHANNEL5	5
#define	DMA1_CHANNEL6	6
#define	DMA1_CHANNEL7	7


		/*			PUBLIC FUNCTIONS  					*/	
		
/******************************************************************************
* Description : Apply Channel choices from config file
* Parameters  : void								
* Return type : void 
******************************************************************************/
void DMA1_voidChannelInit(void);
/*****************************************************************************************************************
* Description : Configure Channel
* Parameters  : Channel Number ( 1 -> 7 )
				Source and Distination Address
				Data Block Length (up to 65536 ) 
				DMA Read Directio ( from Memory or Peripheral)
				Circular Mode ( 1 For Enable and 0 For Disable)
				Memory and Peripheral Increment( 1 For Enable and 0 For Disable)
				Peripheral Size (8, 16 or 32-Bit) - Dependent  on data bus -
				Memory Size     (8, 16 or 32-Bit) - Dependent  on data bus -
				Channel Priority ( 20 -> Very High , 10 -> High
								   5  -> Medium    , 0  -> Low)
				Memory to Memory ( 1 For Enable and 0 For Disable) -Peripheral Works as Source Memory-
* Return type : void 
******************************************************************************************************************/
void DMA1_voidChannelFullControl(u8 Copy_u8ChannelNum , u32 *Copy_Pu32SourceAddress 			,
								 u32 *Copy_Pu32DistinationAddress , u16 Copy_u16BlockLength 	,
								 u8 Copy_u8ReadDir ,u8 Copy_u8CircularMode , u8 Copy_u8PerINC	,
								 u8 Copy_u8MemINC , u8 Copy_u8PerSize ,u8 Copy_u8MemSize		,
								 u8 Copy_u8ChannelPriority , u8 Copy_u8EnableMEM2MEM );

/******************************************************************************
* Description : Apply Channel choices from config file
* Parameters  : void								
* Return type : void 
******************************************************************************/
void DMA1_voidTransferCompleteINT(void (*Ref_CallBack) (void)) ;
void DMA1_voidTransferHalfCompleteINT(void (*Ref_CallBack) (void)) ;
void DMA1_voidTransferErrorINT(void (*Ref_CallBack) (void)) ;


#endif
