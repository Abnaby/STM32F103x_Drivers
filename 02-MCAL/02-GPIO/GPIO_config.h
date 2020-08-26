/*********************************************************************************/
/* Author    : Mohamed Abd El-Naby                                               */
/* Version   : V02                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H
/*	OPTIONS :
				GPIO_PORTA
				GPIO_PORTB
				GPIO_PORTC
*/
	
#define GPIO_PORT_SELECTION		GPIO_PORTA
/*	OPTIONS :
				GPIO_INPUT_#				# --> 
												ANALOG
												FLOATING
												PULLDOWN
				
				GPIO_OUTPUT_$MHZ_#			$ -->
												10
												2
												50
											# -- >
												PUSH_PULL
												OPEN_DRAIN
												AF_PUSH_PULL
												AF_OPEN_DRAIN	
*/

#define GPIO_IO_VAL			GPIO_OUTPUT_2MHZ_PUSH_PULL

/*
	*GPIO_LOCK_PIN 	:
						DISABLE
						ENABLE
*/


#endif

