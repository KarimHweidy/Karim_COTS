#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "DIO_interface.h"

#include "CLCD_interface.h"


void main(void)
{
	/*LCD Pins Initialization*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);	/*RS Pins*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);	/*E Pins*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_OUTPUT);	/*D4 Pins*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);	/*D5 Pins*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);	/*D6 Pins*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_OUTPUT);	/*D7 Pins*/
	//DIO_u8SetPortDirection(DIO_u8PORTB,0xff);	/*Data port*/

	CLCD_voidInit();

	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_INPUT);

	CLCD_voidGoToXY(0,0);
	CLCD_voidSendNumber(1);
	uint8 Local_pu8Plus[8] = {0,0b00000100,0b00000100, 0b00011111, 0b00000100, 0b00000100, 0,0};
	uint8 Local_pu8Minus[8] = {0b00000000,0b00000000,0b00000000, 0b00011111, 0b00000000, 0b00000000, 0b00000000,0};
	uint8 Local_pu8Divid[8] = {0b00000000,0b00000001,0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00000000,0};
	uint8 Local_pu8Multip[8] = {0b00000000,0b00010001,0b00001010, 0b00011111, 0b00001010, 0b00010001, 0b00000000,0};
	uint8 Local_pu8Equal[8] = {0b00000000,0b00000000,0b00011111, 0b00000000, 0b00011111, 0b00000000, 0b00000000,0};
	uint8 Local_pu8Point[8] = {0b00000000,0b00000000,0b00000000,0b00000000, 0b00001110, 0b00001110, 0b00001110,0};

	CLCD_voidSendSpecialCharacter(Local_pu8Plus,0,1,0);
	CLCD_voidGoToXY(2,0);
	CLCD_voidSendNumber(1);
	uint8 Local_pu8Arrow[8] = {0b00000100,0b00001110,0b00010101, 0b00000100, 0b00000100, 0b00000100, 0b00000100,0};
	CLCD_voidSendSpecialCharacter(Local_pu8Arrow,5,0,1);

	//--------------------------------------------------------------------------------------------------------------

	sint8 PosOneValue = 1;
	sint8 PosTwoValue = 1;
	uint8 Local_u8XPos=0;
	sint8 Counter = 1;
	sint8 Result;

	while(1)
	{
		/*Reading of the first Sw.*/
		uint8 Local_u8FrSwValue;
		uint8 Local_u8LstFrSwValue;
		DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN2, &Local_u8FrSwValue);
		if (Local_u8FrSwValue == 0u && Local_u8LstFrSwValue == 1u)
		{
			if (Local_u8XPos == 0)
			{
				PosOneValue ++;
				if(PosOneValue > 9)
				{
					PosOneValue = 0;
				}
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendNumber(PosOneValue);
			}
			else if(Local_u8XPos == 2)
			{
				PosTwoValue ++;
				if(PosTwoValue > 9)
				{
					if (Counter == 3)
					{
						PosTwoValue = 1;
					}
					else
					{
						PosTwoValue = 0;
					}
				}
				CLCD_voidGoToXY(2,0);
				CLCD_voidSendNumber(PosTwoValue);
			}
			else if (Local_u8XPos == 1)
			{
				Counter++;
				if(Counter > 4)
				{
					Counter = 1;
				}
				else if(Counter == 3 && PosTwoValue == 0)
				{
					Counter ++;
				}
				switch(Counter)
				{
				case 1:	CLCD_voidSendSpecialCharacter(Local_pu8Plus,0,1,0); break;
				case 2:	CLCD_voidSendSpecialCharacter(Local_pu8Multip,2,1,0); break;
				case 3:	CLCD_voidSendSpecialCharacter(Local_pu8Divid,3,1,0); break;
				case 4:	CLCD_voidSendSpecialCharacter(Local_pu8Minus,4,1,0); break;
				}
			}

		}
		Local_u8LstFrSwValue = Local_u8FrSwValue;
		_delay_ms(1);

		/*Reading of the Second Sw.*/
		uint8 Local_u8SecSwValue;
		uint8 Local_u8LstSecSwValue;
		DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN3, &Local_u8SecSwValue);
		if (Local_u8SecSwValue == 0u && Local_u8LstSecSwValue == 1u)
		{
			Local_u8XPos ++;
			if (Local_u8XPos>3)
			{
				Local_u8XPos = 0;
			}
			CLCD_voidSendCmd(1);
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendNumber(PosOneValue);
			CLCD_voidSendSpecialCharacter(Local_pu8Arrow,5,Local_u8XPos,1);
			switch(Counter)
			{
			case 1:	CLCD_voidSendSpecialCharacter(Local_pu8Plus,0,1,0); break;
			case 2:	CLCD_voidSendSpecialCharacter(Local_pu8Multip,2,1,0); break;
			case 3:	CLCD_voidSendSpecialCharacter(Local_pu8Divid,3,1,0); break;
			case 4:	CLCD_voidSendSpecialCharacter(Local_pu8Minus,4,1,0); break;
			}
			CLCD_voidGoToXY(2,0);
			CLCD_voidSendNumber(PosTwoValue);
			if (Local_u8XPos == 3)
			{
				CLCD_voidSendSpecialCharacter(Local_pu8Equal,6,3,0);
				CLCD_voidGoToXY(4,0);
				switch(Counter)
				{
				case 1:	Result = PosOneValue + PosTwoValue; break;
				case 2:	Result = PosOneValue * PosTwoValue; break;
				case 3:	Result = PosOneValue / PosTwoValue; break;
				case 4:	Result = PosOneValue - PosTwoValue; break;
				}
				uint8 Reminder = ( (PosOneValue % PosTwoValue) *100 ) / PosTwoValue;
				CLCD_voidSendNumber(Result);
				if( Counter == 3 )
				{
					CLCD_voidGoToXY(5,0);
					CLCD_voidSendSpecialCharacter(Local_pu8Point,7,5,0);
					CLCD_voidGoToXY(6,0);
					CLCD_voidSendNumber(Reminder);
				}
			}

		}
		Local_u8LstSecSwValue = Local_u8SecSwValue;
		_delay_ms(1);

		/*Reading of the Third Sw.*/
		uint8 Local_u8ThSwValue;
		uint8 Local_u8LstThSwValue;
		DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN4, &Local_u8ThSwValue);
		if (Local_u8ThSwValue == 0u && Local_u8LstThSwValue == 1u)
		{
			if (Local_u8XPos == 0)
			{
				PosOneValue --;
				if(PosOneValue < 0)
				{
					PosOneValue = 9;
				}
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendNumber(PosOneValue);
			}
			else if(Local_u8XPos == 2)
			{
				PosTwoValue --;
				if (Counter == 3 && PosTwoValue <1)
				{
					PosTwoValue = 9;
				}
				else if (PosTwoValue < 0)
				{
					PosTwoValue = 9;
				}
				CLCD_voidGoToXY(2,0);
				CLCD_voidSendNumber(PosTwoValue);
			}
			else if (Local_u8XPos == 1)
			{
				Counter--;
				if(Counter < 1)
				{
					Counter = 4;
				}
				else if(Counter == 3 && PosTwoValue == 0)
				{
					Counter --;
				}
				CLCD_voidGoToXY(1,0);
				switch(Counter)
				{
				case 1:	CLCD_voidSendSpecialCharacter(Local_pu8Plus,0,1,0); break;
				case 2:	CLCD_voidSendSpecialCharacter(Local_pu8Multip,2,1,0);break;
				case 3:	CLCD_voidSendSpecialCharacter(Local_pu8Divid,3,1,0); break;
				case 4:	CLCD_voidSendSpecialCharacter(Local_pu8Minus,4,1,0); break;
				}
			}

		}

		Local_u8LstThSwValue = Local_u8ThSwValue;
		_delay_ms(1);

	}
}


