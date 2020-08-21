/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define SSD_COMMON_CATHOD 			1
#define SSD_COMMON_ANNOD			0

/*******************************************************************
*	Description : Initialize Seven Segment and Display Given number  
*	Parameters  : Port , Number
*	Return		: None
*******************************************************************/	
void SSD_voidInitAndDisplay(u8 Copy_u8Port , u8 Copy_u8Number) ;

#endif