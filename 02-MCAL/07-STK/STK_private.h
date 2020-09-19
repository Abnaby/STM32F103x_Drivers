/***********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                                 */
/* Version   : V02                                                                 */
/* Date      : 3 September 2020                                                    */
/***********************************************************************************/




#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS	0xE000ED00 
		/*		REGISTER BOUNDARY ADDRESSES 		*/	
typedef struct {
	volatile u32 STK_CTRL ; 
	volatile u32 STK_LOAD ; 
	volatile u32 STK_VAL ; 
	volatile u32 STK_CALIB ; 
}STK_type;

#define STK ((STK_type *) STK_BASE_ADDRESS ) 


#define STK_AHB			 0
#define STK_AHB_OVER_8 	 1

/*
	2 power Resolution 
*/
#define Max_Number_Count 16777216

/*	MS AND US */
#define STK_GENERATE_1_MS	1000
#define STK_GENERATE_1_US	1000000

#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1

/*	PRIVATE FUNCTIONS	*/
static u32 STK_u32ConfigIntervalMS(void);
static u32 STK_u32ConfigIntervalUS(void);


#endif
