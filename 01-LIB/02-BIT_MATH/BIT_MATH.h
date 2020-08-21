/**************************************************************************/
/* Author	: Mohamed                                                 */
/* Date		: 29 JUL 2020                                             */
/* Version	: V01							  */
/**************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)	VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT) 	VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)	(VAR >> BIT) & 1 //or ((VAR & (1<< BIT))>>BIT
#define TOG_BIT(VAR,BIT)	VAR ^= (1 << (BIT))
#define SPECIAL_SET(VAR,SHIFTNUM, BIT)		VAR |= (SHIFTNUM << (BIT))
#define SPECIAL_CLR(VAR,SHIFTNUM, BIT)		VAR &= ~(SHIFTNUM << (BIT))
#endif
