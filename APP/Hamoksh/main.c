#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "PORT_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>


void main(void)
{
	uint8 Local_u8HamokshaFace[8]={0b00001110,0b00011111,0b00010001,0b00011011,0b00010001,0b00011011,0b00001110,0};
	uint8 Local_u8HamokshaHi1[8]={0b00010101,0b00001110,0b00000100,0b00000100,0b00000100,0b00001010,0b00001010,0};
	uint8 Local_u8HamokshaHi2[8]={0b00000100,0b00000100,0b00011111,0b00000100,0b00000100,0b00001010,0b00001010,0};
	uint8 Local_u8BasketMode1[8]={0b00000100,0b00000100,0b00000111,0b00001101,0b00001100,0b00001010,0b00001010,0};
	uint8 Local_u8BasketMode2[8]={0b00000100,0b00000100,0b00000111,0b00001100,0b00001100,0b00001010,0b00001011,0};
	uint8 Local_u8DanceMode1[8]={0b00000100,0b00000111,0b00000100,0b00011100,0b00000100,0b00001010,0b00001010,0};
	uint8 Local_u8DanceMode2[8]={0b00000100,0b00011100,0b00000100,0b00000111,0b00000100,0b00001010,0b00010001,0};
	uint8 Local_u8RunMode[8]={0b00000100,0b00000101,0b00011111,0b00010100,0b00010100,0b00001010,0b00000010,0};
	uint8 Local_u8Gun[8]={0b00011111,0b00010001,0b00011111,0b00011000,0b00011000,0b00011000,0,0};
	uint8 Local_u8Serounded[8]={0b00010101,0b000101001,0b00011111,0b00000100,0b00000100,0b00001010,0b00001010,0};
	uint8 Local_u8Fire[8]={0b00000110,0b00000110,0,0,0,0,0,0};
	uint8 Local_u8LoopCounter=0;
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{
		CLCD_viodGoToXY(2,0);
		CLCD_u8SendString("Hello..");
		CLCD_viodGoToXY(2,1);
		CLCD_u8SendString("I'm Hamoksha");
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,0,0,0);
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<=15;Local_u8LoopCounter++)
		{
			CLCD_voidSendSpecialCharacter(Local_u8HamokshaHi1,2,0,1);
			_delay_ms(250);
			CLCD_voidSendSpecialCharacter(Local_u8HamokshaHi2,3,0,1);
			_delay_ms(250);
		}
		CLCD_voidSendCmd(1);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,0,0,0);
		CLCD_voidSendSpecialCharacter(Local_u8BasketMode1,1,0,1);
		CLCD_viodGoToXY(2,0);
		CLCD_u8SendString("I can play");
		CLCD_viodGoToXY(2,1);
		CLCD_u8SendString("Basketball");
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<=15;Local_u8LoopCounter++)
		{
			CLCD_voidSendSpecialCharacter(Local_u8BasketMode1,1,0,1);
			_delay_ms(250);
			CLCD_voidSendSpecialCharacter(Local_u8BasketMode2,5,0,1);
			_delay_ms(250);
		}
		CLCD_voidSendCmd(1);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,0,0,0);
		CLCD_voidSendSpecialCharacter(Local_u8DanceMode1,1,0,1);
		CLCD_viodGoToXY(5,0);
		CLCD_u8SendString("I can");
		CLCD_viodGoToXY(5,1);
		CLCD_u8SendString("Dance");
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<=15;Local_u8LoopCounter++)
		{
			CLCD_voidSendSpecialCharacter(Local_u8DanceMode1,1,0,1);
			_delay_ms(250);
			CLCD_voidSendSpecialCharacter(Local_u8DanceMode2,3,0,1);
			_delay_ms(250);
		}
		CLCD_voidSendCmd(1);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,0,6,0);
		CLCD_voidSendSpecialCharacter(Local_u8RunMode,1,6,1);
		CLCD_viodGoToXY(0,0);
		CLCD_u8SendString("I can ");
		CLCD_viodGoToXY(0,1);
		CLCD_u8SendString("Run");
		for (Local_u8LoopCounter=6;Local_u8LoopCounter<=15;Local_u8LoopCounter++)
		{
			CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,0,Local_u8LoopCounter,0);
			CLCD_voidSendSpecialCharacter(Local_u8RunMode,1,Local_u8LoopCounter,1);
			_delay_ms(250);
			CLCD_viodGoToXY(Local_u8LoopCounter,0);
			CLCD_voidSendData(' ');
			CLCD_viodGoToXY(Local_u8LoopCounter,1);
			CLCD_voidSendData(' ');
		}
		CLCD_voidSendCmd(1);
		CLCD_viodGoToXY(6,0);
		CLCD_u8SendString("Don't");
		CLCD_viodGoToXY(6,1);
		CLCD_u8SendString("Kill me");
		CLCD_voidSendSpecialCharacter(Local_u8Gun,7,0,0);
		_delay_ms(2000);
		CLCD_voidSendCmd(1);
		CLCD_voidSendSpecialCharacter(Local_u8Gun,7,0,0);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,1,3,0);
		CLCD_voidSendSpecialCharacter(Local_u8Serounded,2,3,1);
		for (Local_u8LoopCounter=3;Local_u8LoopCounter<=15;Local_u8LoopCounter++)
		{

			CLCD_voidSendSpecialCharacter(Local_u8Fire,3,Local_u8LoopCounter-1,0);
			CLCD_voidSendSpecialCharacter(Local_u8HamokshaFace,1,Local_u8LoopCounter,0);
			CLCD_voidSendSpecialCharacter(Local_u8Serounded,2,Local_u8LoopCounter,1);
			_delay_ms(250);
			CLCD_viodGoToXY(Local_u8LoopCounter,0);
			CLCD_voidSendData(' ');
			CLCD_viodGoToXY(Local_u8LoopCounter,1);
			CLCD_voidSendData(' ');
		}
		CLCD_voidSendCmd(1);
		CLCD_viodGoToXY(5,0);
		CLCD_u8SendString("THE END");
		_delay_ms(5000);
		CLCD_voidSendCmd(1);
	}





}
