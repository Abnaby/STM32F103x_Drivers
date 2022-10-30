/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 27 August 2020                                                    */
/*********************************************************************************/



#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

#define AFIO_BASE_ADDRESS	0x40010400 
		/*		REGISTER BOUNDARY ADDRESSES 		*/		
typedef struct
{
	volatile u32 AFIO_EVCR	;
	volatile u32 AFIO_MAPR	;
	volatile u32 AFIO_EXTICR[4]	;
	volatile u32 AFIO_MAPR2	;
}AFIO_Type;

#define AFIO ((volatile AFIO_Type * )AFIO_BASE_ADDRESS)


		
#endif
