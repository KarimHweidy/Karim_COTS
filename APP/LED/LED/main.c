#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_private.h"
#include "PORT_interface.h"
#include "LED_interface.h"

#include <util/delay.h>



void main(void)

{
	PORT_voidInit();

	uint8 Local_u8LedPort=DIO_u8PORTA;
	uint8 Local_u8LedPin=DIO_u8PIN1;
	uint8 Local_u8LedConnetion=SourceConnection;

	while(1)
	{

        //LED_voidLedOn(Local_u8LedPort,Local_u8LedPin,Local_u8LedConnetion);
		LED_voidLedToggle(Local_u8LedPort,Local_u8LedPin);
		_delay_ms(250);
		//LED_voidLedOff(Local_u8LedPort,Local_u8LedPin,Local_u8LedConnetion);
		LED_voidLedToggle(Local_u8LedPort,Local_u8LedPin);
		_delay_ms(250);
	}
}


