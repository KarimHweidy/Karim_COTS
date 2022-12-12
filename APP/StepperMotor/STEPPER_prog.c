/**************************************************************/
/**************************************************************/
/*********		Author: Karim Hweidy		*******************/
/*********		File: STEPPER_prog.c    	*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_private.h"



uint8 STEPPER_u8Rotate(const StepperMotor_t* Copy_puStepperMotor, uint16 Copy_u16StepperAngle, uint8 Copy_u8StepperDirection)
{
	uint8 Local_u8ErrorState = OK;
	if (Copy_puStepperMotor == NULL)
	{
		Local_u8ErrorState = NULL_PTR_ERR;
		return Local_u8ErrorState;
	}
	else 
	{
		uint16 Local_u16Counter;
		uint16 Local_u16Steps;

		Local_u16Steps = (uint16)(((uint32)Copy_u16StepperAngle * 2048ul) / 360ul);
		if ( Copy_u8StepperDirection == ClockWise )
		{
			for (Local_u16Counter=0 ; Local_u16Counter<=Local_u16Steps; Local_u16Counter++)
			{
				if (Local_u16Counter%4 == 0)
				{
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_LOW );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );
					_delay_ms(2);
				}
				else if (Local_u16Counter%4 == 1)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_LOW );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );	
				   _delay_ms(2);
				}
				else if (Local_u16Counter%4 == 2)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_LOW );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );	
				   _delay_ms(2);
				}
				else if (Local_u16Counter%4 == 3)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_LOW );	
				   _delay_ms(2);
				}
			}
		}
		else if ( Copy_u8StepperDirection == CounterClockWise )
		{
           for (Local_u16Counter=0 ; Local_u16Counter<=Local_u16Steps; Local_u16Counter++)
		   {
			
				if (Local_u16Counter%4 == 0)
				{
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
					DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_LOW );
					_delay_ms(2);
				}
				else if (Local_u16Counter%4 == 1)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_LOW );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );	
				   _delay_ms(2);
				}
				else if (Local_u16Counter%4 == 2)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_LOW );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );	
				   _delay_ms(2);
				}
				else if (Local_u16Counter%4 == 3)
				{
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Blue_pin, DIO_u8PIN_LOW );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Pink_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Yellow_pin, DIO_u8PIN_HIGH );
				   DIO_u8SetPinValue(Copy_puStepperMotor -> PORT, Copy_puStepperMotor -> Orange_pin, DIO_u8PIN_HIGH );	
				   _delay_ms(2);
				}
		   }
		}

	}
}
