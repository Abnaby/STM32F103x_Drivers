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

	/*			PIN CONFIGRAUTIONS				*/
#define AFIO_PIN_A	0b0000
#define AFIO_PIN_B	0b0001
#define AFIO_PIN_C	0b0010
#define AFIO_PIN_D	0b0011
#define AFIO_PIN_E	0b0100
#define AFIO_PIN_F	0b0101
#define AFIO_PIN_G	0b0110

		
#endif
