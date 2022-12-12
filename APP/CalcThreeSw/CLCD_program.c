/*************************************************************/
/*************************************************************/
/***********       Author : Karim Hweidy       ***************/
/***********       File : CLCD_program.c       ***************/
/***********       Version : 1.0               ***************/
/*************************************************************/
/*************************************************************/


#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	    _delay_ms(2);
	    DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

#if CLCD_OP_MODE == FOUR_BIT_MODE
static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple)
{
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,GET_BIT(Copy_u8Nipple,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,GET_BIT(Copy_u8Nipple,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,GET_BIT(Copy_u8Nipple,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,GET_BIT(Copy_u8Nipple,3));
}
#endif

void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{
	/* Set RS pin to low for command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
#if CLCD_RW_CTRL_EN == ENABLED
	/* Set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
#endif

#if CLCD_OP_MODE == Eigh_BIT_MODE
	/*Send the command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Cmd);
	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Cmd>>4); /* send the most four bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Cmd);     /* send the least four bits to the LCD*/
	voidSendEnablePulse();
#endif
}


void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/* Set RS pin to high for data */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
#if CLCD_RW_CTRL_EN == ENABLED
	/* Set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
#endif


#if CLCD_OP_MODE == Eigh_BIT_MODE
	/*Send the command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Data>>4); /* send the most four bits to the LCD*/
		voidSendEnablePulse();

		voidSetLCDHalfDataPort(Copy_u8Data);     /* send the least four bits to the LCD*/
		voidSendEnablePulse();
#endif
}


void CLCD_voidInit(void)
{
	/* wait for more 30ms after power on */
	_delay_ms(40);

	/*function set command  2  lines    5*7  font size*/
#if CLCD_OP_MODE == EIGHT_BIT_MODE
	CLCD_voidSendCmd(0b00111000);
#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();
#endif

	/*display on/off control: display enable ,cursor and blink disable*/
	CLCD_voidSendCmd(0b00001100);

	/*Display clear*/
	CLCD_voidSendCmd(1);

}


uint8 CLCD_u8SendString(const char* Copy_chString)
{
	uint8 Local_u8ErrorState= OK;
	if(Copy_chString != NULL)
	{
		uint8 Local_u8Counter=0u;
		while(Copy_chString[Local_u8Counter] != '\0')
		{
		  CLCD_voidSendData(Copy_chString[Local_u8Counter]);
		  Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState= NOK;
	}
	return Local_u8ErrorState;
}


void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	char Local_chNumberArr[10];
	uint8 Local_u8RightDigit, Local_u8Counter=0;
	sint8 Local_s8Counter2;
	if (Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');
		return ;
	}

	else if (Copy_s32Number < 0)
	{
		CLCD_voidSendData('-');
		Copy_s32Number *= -1;
	}
	while (Copy_s32Number != 0)
	{
		Local_u8RightDigit = Copy_s32Number%10;  /* extract the right most digit*/
		Copy_s32Number /= 10;                    /* get rid of the most right digit*/
		Local_chNumberArr[Local_u8Counter] = Local_u8RightDigit + '0';   /* convert to ascii value*/
		Local_u8Counter ++;
	}
	for (Local_s8Counter2 = Local_u8Counter-1; Local_s8Counter2>=0; Local_s8Counter2--)
	{
		CLCD_voidSendData(Local_chNumberArr[Local_s8Counter2]);
	}

}

void CLCD_voidGoToXY(uint8 Copy_u8XPos,uint8 Copy_u8YPos)
{
	uint8 Local_u8DDRamAdd;
	if(Copy_u8YPos == 0u)
	{
		Local_u8DDRamAdd = Copy_u8XPos;
	}
	else if (Copy_u8YPos == 1u)
	{
		Local_u8DDRamAdd = 0x40 + Copy_u8XPos;

	}
	/* set bit 7 for set DDRam Address Command*/
	Local_u8DDRamAdd |= 1<<7u;
	CLCD_voidSendCmd(Local_u8DDRamAdd);
}

void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern, uint8 Copy_u8PatternNum,uint8 Copy_u8XPos, uint8 Copyu8YPos)
{
	uint8 Local_u8LoopCounter;
	uint8 Local_u8CGRAMAdd = Copy_u8PatternNum * 8u;
	/* set bit number 6 for set CGRAM Address command */
	Local_u8CGRAMAdd |= 1<<6u;
	/* set CGRAM address */
	CLCD_voidSendCmd(Local_u8CGRAMAdd);
	/* write the pattern into CGRAM*/
	for (Local_u8LoopCounter=0; Local_u8LoopCounter<8u;Local_u8LoopCounter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8LoopCounter]);
	}
	/* GoTo DDRAM to Display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copyu8YPos);
	/* Display the pattern written inside CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNum);

}
