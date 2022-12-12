#include "STD_TYPES.h"
#include <util/delay.h>
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
uint8 Global_u8FirstOp=0;
uint8 Global_u8SecOp=0;
uint8 Global_u8Operator=0;
sint32 Global_s32Result=0;
uint8 Global_u8FirstFloat=0;
uint8 Global_u8SecondFloat=0;
uint8 Global_u8FloatResult = 0;


void main(void)
{
	uint8 Local_u8PressedKey= 0xff;
	PORT_voidInit();
	CLCD_voidInit();
	uint8 Local_u8Digit;
	uint8 Local_u8Counter1 =0;
	uint8 Local_u8Number=0;
	uint8 Local_u8Clear=0;
	uint8 Local_u8Error=0;
	uint8 Local_u8XPos=0;
    uint8 Local_u8FirstFlag=0;
	uint8 Local_u8SecondFlag=0;
    uint8 Local_u8OperatorFlag=0;
	uint8 Local_u8Remnder=0;
	uint8 Local_u8FloatFlag=0;
	

	while(1)
	{

		Local_u8PressedKey = KPD_u8GetPressedKey();
		Local_u8Digit = Local_u8PressedKey;
		if(Local_u8PressedKey != 0xff)
		{   
			if(Local_u8Clear==1)
			{
				CLCD_voidSendCmd(1);
				Local_u8Clear=0;
			}

			if((Local_u8Digit>=0) && (Local_u8Digit<=9))
			{
				Local_u8Counter1++;
				CLCD_voidSendNumber(Local_u8Digit);
				Local_u8Number = Local_u8Number*10 + (Local_u8Digit);
				if((Local_u8FirstFlag==1) && (Local_u8OperatorFlag==1) && (Local_u8FloatFlag==0))
				{
					Global_u8SecOp=Local_u8Number;
					Local_u8SecondFlag=1;
				}
				else if ((Local_u8FirstFlag==1) && (Local_u8OperatorFlag==1) && (Local_u8FloatFlag==1))
				{

					Global_u8SecondFloat=Local_u8Number;
					Local_u8SecondFlag=1;
				}
				else if ((Local_u8FirstFlag==0) && (Local_u8FloatFlag==0))
				{
					Global_u8FirstOp=Local_u8Number;
				}
				else if ((Local_u8FirstFlag==0) && (Local_u8FloatFlag==1))
				{
					Global_u8FirstFloat=Local_u8Number;
				}
				Local_u8XPos++;
			}
			else
			{
				switch (Local_u8PressedKey)
				{
				case '+' :
				{
					Local_u8FirstFlag=1;
					Local_u8OperatorFlag=1;
					Local_u8Counter1 =0;
					Local_u8FloatFlag=0;
					Local_u8Number=0;
					Global_u8Operator='+';
					CLCD_u8SendString("+");
					Local_u8XPos++;
					break;
				}
				case '-' :
				{
					Local_u8FirstFlag=1;
					Local_u8OperatorFlag=1;
					Local_u8Counter1 =0;
					Local_u8FloatFlag=0;
					Local_u8Number=0;
					Global_u8Operator='-';
					CLCD_u8SendString("-");
					Local_u8XPos++;
					break;
				}
				case '*' :
				{
					Local_u8FirstFlag=1;
					Local_u8OperatorFlag=1;
					Local_u8Counter1 =0;
					Local_u8FloatFlag=0;
					Local_u8Number=0;
					Global_u8Operator='*';
					CLCD_u8SendString("*");
					Local_u8XPos++;
					break;
				}
				case '/' :
				{
					Local_u8FirstFlag=1;
					Local_u8OperatorFlag=1;
					Local_u8Counter1 =0;
					Local_u8FloatFlag=0;
					Local_u8Number=0;
					Global_u8Operator='/';
					CLCD_u8SendString("/");
					Local_u8XPos++;
					break;
				}
				case '.':
				{
					Local_u8FloatFlag=1;
					CLCD_u8SendString(".");
					Local_u8Number=0;
					break;
				}
				case '=':
				
					if (Local_u8Clear==1)
					{
						CLCD_voidSendCmd(1);
						
						Local_u8Clear=0;
					}
					else
					{

					    Local_u8Clear=1;

					
						CLCD_u8SendString("=");
						if (Local_u8FirstFlag && Local_u8OperatorFlag && Local_u8SecondFlag)
						{
							switch (Global_u8Operator)
							{
								case '+' : 
									Global_s32Result = Global_u8FirstOp + Global_u8SecOp;
									CLCD_voidSendNumber(Global_s32Result);
									CLCD_u8SendString(".");
									Global_u8FloatResult = Global_u8FirstFloat+Global_u8SecondFloat;
									CLCD_voidSendNumber(Global_u8FloatResult);
									break;
								case '*' : 
									Global_s32Result = Global_u8FirstOp * Global_u8SecOp;
									CLCD_voidSendNumber(Global_s32Result);
									break;
								case '/' :
									if (Global_u8SecOp==0 && Global_u8SecondFloat==0)
									{
										CLCD_voidSendCmd(1);
										 CLCD_voidGoToXY(3,0);
										 CLCD_u8SendString("ERROR");
										 CLCD_voidGoToXY(0,1);
										 CLCD_u8SendString("division by zero");
										 _delay_ms(1000);
										 CLCD_voidSendCmd(1);
									} 
									else
									{
									Global_s32Result = Global_u8FirstOp / Global_u8SecOp;
									CLCD_voidSendNumber(Global_s32Result);
									CLCD_u8SendString(".");
									Local_u8Remnder = Global_u8FirstOp % Global_u8SecOp;
									CLCD_voidSendNumber(Local_u8Remnder);
									
									}
									break;
								case '-' : 

									Global_s32Result = Global_u8FirstOp - Global_u8SecOp;
									CLCD_voidSendNumber(Global_s32Result);
									CLCD_u8SendString(".");
									Global_u8FloatResult=Global_u8FirstFloat-Global_u8SecondFloat;
									CLCD_voidSendNumber(Global_u8FloatResult);
									break;
								

							}
							Global_s32Result=0;
							Global_u8FirstOp=0;
							Global_u8SecOp=0;
							Global_u8Operator=0;
							Local_u8FirstFlag=0;
							Local_u8OperatorFlag=0;
							Local_u8SecondFlag=0;
							Local_u8Number=0;
							Local_u8FloatFlag=0;
							Global_u8FirstFloat=0;
							Global_u8SecondFloat=0;

						}

					}
					break;
				
				
				


				
				}
		    }
	    }
    }
}

