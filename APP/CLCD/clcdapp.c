#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "PORT_interface.h"

#include "CLCD_interface.h"

void main(void)
{
	/*uint8 Local_u8MyPattern[8]={0,0b00010001,0b00010001,0b00010001,0b00011111,0b00011111,0b00000100,0};
	/*LCD pins initialization
	PORT_voidInit();
	CLCD_voidInit();
   /* CLCD_voidGoToXY(0u,0u);
    char Local_chSrting[]="Karim";
  	CLCD_u8SendString(Local_chSrting);
  CLCD_voidSendSpecialCharacter(Local_u8MyPattern,0,0,0);*/
	/*LCD Pins Initialization*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);	/*RS Pins*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);	/*E Pins*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_OUTPUT);	/*D4 Pins*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);	/*D5 Pins*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);	/*D6 Pins*/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_OUTPUT);	/*D7 Pins*/
		//DIO_u8SetPortDirection(DIO_u8PORTB,0xff);	/*Data port*/

		CLCD_voidInit();

	uint8 Local_u8Array[8]={'S','A','P','O','N','B','C','O'};
	sint8 Local_s8Counter1=0;
	sint8 Local_s8Counter2=0;
	uint8 Local_u8Temp=0;

	for (Local_s8Counter1=0;Local_s8Counter1<7;Local_s8Counter1++)
	{
		for (Local_s8Counter2=Local_s8Counter1+1;Local_s8Counter2<8;Local_s8Counter2++)
		{
			if (Local_u8Array[Local_s8Counter1]>Local_u8Array[Local_s8Counter2])
			{
				Local_u8Temp=Local_u8Array[Local_s8Counter1];
				Local_u8Array[Local_s8Counter1]=Local_u8Array[Local_s8Counter2];
				Local_u8Array[Local_s8Counter2]=Local_u8Temp;

			}
		}

	}
	CLCD_voidGoToXY(16,0);
	for(Local_s8Counter1=16;Local_s8Counter1>=11;Local_s8Counter1--)
	{
		CLCD_voidGoToXY(Local_s8Counter1,1);
		CLCD_voidSendData(Local_u8Array[Local_s8Counter1-8]);
	}


	while(1)
	{

	}
}
