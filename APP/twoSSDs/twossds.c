#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
/* two SSDS with only 9 pins */
void main(void)
{
	uint8 SSD[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	DDRA=0xFF;
	SET_BIT(DDRC,6);
	SET_BIT(DDRC,7);
	while (1)
	{
		SET_BIT(PORTC,6);
		CLR_BIT(PORTC,7);
		PORTA=SSD[7]<<1;
		_delay_ms(10);
		CLR_BIT(PORTC,6);
		SET_BIT(PORTC,7);
		PORTA=SSD[3]<<1;
		_delay_ms(10);
	}
}
