#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>

#include <util/delay.h>

void main(void)
{


	uint8 arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	sint8 i;
	DDRC =0xFF;
	DDRD =0xFF;
	DDRA |= 0b00000111;
	while (1)
	{
		SET_BIT(PORTA,0);
			PORTC=arr[1];
			for (i=5 ; i>=0 ;i--)
			{
				PORTD = arr[i];
				_delay_ms(1000);
			}
			PORTC=arr[0];
			for (i=9;i>=1;i--)
			{
				PORTD = arr[i];
				_delay_ms(1000);
			}
		CLR_BIT(PORTA,0);
		SET_BIT(PORTA,2);
			PORTC=arr[1];
			for (i=5 ; i>=0 ;i--)
			{
				PORTD = arr[i];
				_delay_ms(1000);
			}
			PORTC=arr[0];
			for (i=9;i>=1;i--)
			{
				PORTD = arr[i];
				_delay_ms(1000);
			}

		CLR_BIT(PORTA,2);
		SET_BIT(PORTA,1);
			PORTC=arr[0];
			for (i=3 ; i>=1 ;i--)
			{
				PORTD = arr[i];
				_delay_ms(1000);
			}

		    CLR_BIT(PORTA,1);
	}
}
