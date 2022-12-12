#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "PORT_interface.h"
#include "SSD_private.h"
#include "SSD_cfg.h"
#include "SSD_interface.h"


void main (void)
{
	/*Configure SSD type options 1- CommonAnode
	 *                           2- CommonCathod*/
	SSD_cfg. SSD_u8Type = CommonCathod;

	/*Please choose which port to connect SSD PINS
	 * options:  1- DIO_u8PORTA
	 * 			 2- DIO_u8PORTB
	 * 			 3- DIO_u8PORTC
	 * 			 4- DIO_u8PORTD
	 * 	*/
	 SSD_cfg.SSD_u8Port = DIO_u8PORTA;

	/*Please chose the start pin of the port you want to connect
	 * options     1- DIO_u8PIN0
	 *             2- DIO_u8PIN1*/

	 SSD_cfg. SSD_u8Pin = DIO_u8PIN1;

	/*Please choose which port to connect SSD Enable PIN
	 * options:  1- DIO_u8PORTA
	 * 			 2- DIO_u8PORTB
	 * 			 3- DIO_u8PORTC
	 * 			 4- DIO_u8PORTD
	 * 	*/

	 SSD_cfg.SSD_u8EnablePort = DIO_u8PORTC;

	/*Please choose the Enable Pin
	 * options      1- DIO_u8PIN0
	 *              2- DIO_u8PIN1
	 *              3- DIO_u8PIN2
	 *              4- DIO_u8PIN3
	 *              5- DIO_u8PIN4
	 *              6- DIO_u8PIN5
	 *              7- DIO_u8PIN6
	 *              8- DIO_u8PIN7
	 *              */

	 SSD_cfg.SSD_u8EnablePin = DIO_u8PIN6;

	PORT_voidInit();

	uint8 Local_u8LoopCounter;

	uint8 SSD_ARR[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b00000111,0b1111111,0b1100111};


	for (Local_u8LoopCounter=0;Local_u8LoopCounter<10;Local_u8LoopCounter++)
	{
		SSD_u8SetNumber(&SSD_cfg,SSD_ARR[Local_u8LoopCounter]);
		_delay_ms(250);
	}

	while (1)
	{

	}



}








