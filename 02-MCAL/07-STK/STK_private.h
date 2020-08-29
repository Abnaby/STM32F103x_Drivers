/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 28 August 2020                                                    */
/*********************************************************************************/



#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS	0xE000ED00 
		/*		REGISTER BOUNDARY ADDRESSES 		*/	
typedef struct {
	volatile u32 STK_CTRL ; 
	volatile u32 STK_LOAD ; 
	volatile u32 STK_VAL ; 
	volatile u32 STK_CALIB ; 
}STK_type	

#define STK ((STK_type *) STK_BASE_ADDRESS ) 


#define STK_AHB			 0
#define STK_AHB_OVER_8 	 1

/*
	2 power Resolution 
*/
#define Max_Number_Count 16777216

#endif
