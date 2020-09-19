/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V01                                                                 */
/* Date      : 17 September 2020                                                    */
/***********************************************************************************/




#ifndef DMA1_PRIVATE_H
#define DMA1_PRIVATE_H

#define DMA1_BASE_ADDRESS	0x40020000
		/*		REGISTER BOUNDARY ADDRESSES 		*/	
typedef struct{
	volatile u32 CCR		;
	volatile u32 CNDTR		;
	volatile u32 CPAR		;
	volatile u32 CMAR		;
	volatile u32 Reserved	;
	
}DMA1_Channels;

typedef struct{
	volatile u32 ISR 	 ;
	volatile u32 IFCR	 ;
	DMA1_Channels Channel[7] ;
}DMA1_type;

#define	DMA1 ((volatile DMA1_type *)DMA1_BASE_ADDRESS)
#define	DMA1_MAX_CHANNELS					7
#define	DMA1_MAX_NUM_OF_DATA_TRANSFERRED	65536

/*		DMA channel x configuration register (DMA_CCRx) 	*/
#define	EN 			0
#define	TCIE		1
#define	HTIE		2
#define	TEIE		3
#define	DIR			4
#define	CIRC		5
#define	PINC		6
#define	MINC		7
#define	PSIZE0		8
#define	PSIZE1		9
#define	MSIZE0		10
#define	MSIZE1		11
#define	PL0			12
#define	PL1			13
#define	MEM2MEM		14
/*		DMA interrupt flag clear register (DMA_IFCR)	*/
#define CGIF1		0
#define CTCIF1		1
#define CHTIF1		2
#define CTEIF1		3
#define CGIF2		4
#define CTCIF2		5
#define CHTIF2		6
#define CTEIF2		7
#define CGIF3		8
#define CTCIF3		9
#define CHTIF3		10
#define CTEIF3		11
#define CGIF4		12
#define CTCIF4		13
#define CHTIF4		14
#define CTEIF4		15
#define CGIF5		16
#define CTCIF5		17
#define CHTIF5		18
#define CTEIF5		19
#define CGIF6		20
#define CTCIF6		21
#define CHTIF6		22
#define CTEIF6		23
#define CGIF7		24
#define CTCIF7		25
#define CHTIF7		26
#define CTEIF7		27
		/*	PRIVATE FUNCTIONs AND VARs	*/
static void (*Global_Callback) (void) = NULL ;
static u8	Global_u8IntType = 200; 




#endif
