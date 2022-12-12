#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DCM_interface.h"
#include <util/delay.h>

void main (void)
{
	PORT_voidInit();
    CLCD_voidInit();
	DCM_cfg DCM_Object;
	DCM_Object.DCM_u8SwitchPort=DIO_u8PORTB;
	DCM_Object.DCM_u8Switch1Pin=DIO_u8PIN0;
	DCM_Object.DCM_u8Switch2Pin=DIO_u8PIN2;
	DCM_Object.DCM_u8Switch3Pin=DIO_u8PIN2;
	DCM_Object.DCM_u8Switch4Pin=DIO_u8PIN1;
    uint8 Local_u8Button1=1,Local_u8Button2=1,Local_u8Button3=1;



     CLCD_u8SendString("Press SW 1 CW");
     CLCD_viodGoToXY(0,1);
     CLCD_u8SendString("Press SW 2 CCW");

	while(1)
	{
		while(Local_u8Button1!=0 && Local_u8Button2!=0)
		{
			CLCD_viodGoToXY(0,0);
		    CLCD_u8SendString("Press SW 1 CW");
		    CLCD_viodGoToXY(0,1);
		    CLCD_u8SendString("Press SW 2 CCW");
		    DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8Button1);
		    DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8Button2);
	   	    DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Button3);
		}

		   if(Local_u8Button1==0)
		   {
			   CLCD_voidSendCmd(1);
			   CLCD_u8SendString("Press SW3 Stop");
			   DCM_voidCW(&DCM_Object);
			   while(Local_u8Button1==0)
			    {
			  	   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8Button1);
			    }
			   while(Local_u8Button3!=0)
			   {

				   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Button3);
			   }
			   if(Local_u8Button3==0)
			   {
				   DCM_voidBrake(&DCM_Object);
				   while(Local_u8Button3==0)
				    {
				  	   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Button3);
				    }
				   CLCD_voidSendCmd(1);
			   }
		   }
		   else if(Local_u8Button2==0)
		   {
			   CLCD_voidSendCmd(1);
			   CLCD_u8SendString("Press SW3 Stop");
			   DCM_voidCCW(&DCM_Object);
			   while(Local_u8Button2==0)
			    {
			  	   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8Button2);
			     }
			   while(Local_u8Button3!=0)
			   {

				   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Button3);
			   }
			   if(Local_u8Button3==0)
			   {
				   DCM_voidBrake(&DCM_Object);
				   while(Local_u8Button3==0)
				   {
					   DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Button3);
				   }
				   CLCD_voidSendCmd(1);
			   }
		   }


	}
}
