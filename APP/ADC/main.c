#include "STD_TYPES.h"
#include "defines.h"

#include "ADC_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"


void main(void)
{
	uint8 Local_u8DATA;
	PORT_voidInit();
	ADC_voidInit();
	while(1)
	{
		Local_u8DATA = ADC_u8GetChannelReading(0b00000);
		DIO_u8SetPortValue(DIO_u8PORTB,Local_u8DATA);

	}

}
