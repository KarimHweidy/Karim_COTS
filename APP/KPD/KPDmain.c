#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


void main(void)
{
uint8 Local_u8PressedKey= 0xff;
PORT_voidInit();
CLCD_voidInit();
//CLCD_u8SendString("karim");

while(1)
{
	Local_u8PressedKey = KPD_u8GetPressedKey();
	if(Local_u8PressedKey != 0xff)
	{
		CLCD_voidSendCmd(1);
		CLCD_voidSendNumber(Local_u8PressedKey);
	}


}
}
