#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>

#include <util/delay.h>

void main(void)
{
	CLR_BIT(DDRD,2);
	SET_BIT(PORTD,2);
	CLR_BIT(DDRD,3);
	SET_BIT(PORTD,3);
	CLR_BIT(DDRD,4);
	SET_BIT(PORTD,4);
	DDRA = 0xFF;
	sint8 i;
	sint8 j;
	while (1)
	{
		uint8 x = GET_BIT(PIND,2);
		uint8 y = GET_BIT(PIND,3);
		uint8 z = GET_BIT(PIND,4);
		_delay_ms(250);

		if ((x==0) && (y==1) && (z==1))
		{
			for (i=0;i<=7;i++)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				_delay_ms(250);
			}
		}
		else if ((x==1) && (y==0) && (z==1))
		{
			for (i=7;i>=0;i--)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				_delay_ms(250);
			}
		}
		else if ((x==1) && (y==1) && (z==0))
		{
			for (i=0;i<=7;i++)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				_delay_ms(250);
			}
			for (i=7;i>=0;i--)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				_delay_ms(250);
			}
		}
		else if ((x==0) && (y==1) && (z==0))
		{
			for (i=0;i<=7;i++)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);

			}
			PORTA=0;
			_delay_ms(250);
			for (i=7;i>=0;i--)
			{
				SET_BIT(PORTA,i);
				_delay_ms(250);
			}
			PORTA=0;
			_delay_ms(250);
		}
		else if ((x==0) && (y==0) && (z==1))
		{
			for (i=0 , j=7; i<=j , j>=i ; i++, j--)
			{
				SET_BIT(PORTA,i);
				SET_BIT(PORTA,j);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				CLR_BIT(PORTA,j);
				_delay_ms(250);
			}
		}
		else if ((x==1) && (y==0) && (z==0))
		{
			for (i=3 , j=4; i>=0 , j<=7 ; i--, j++)
			{
				SET_BIT(PORTA,i);
				SET_BIT(PORTA,j);
				_delay_ms(250);
				CLR_BIT(PORTA,i);
				CLR_BIT(PORTA,j);
				_delay_ms(250);
			}
		}
		else if ((x==0) && (y==0) && (z==0))
		{
			for (i=0 , j=7; i<=j , j>=i ; i++, j--)
			{
				SET_BIT(PORTA,i);
				SET_BIT(PORTA,j);
				_delay_ms(250);

			}
			for (i=3 , j=4; i>=0 , j<=7 ; i--, j++)
			{
				CLR_BIT(PORTA,i);
				CLR_BIT(PORTA,j);
				_delay_ms(250);
			}
		}


	}
}
