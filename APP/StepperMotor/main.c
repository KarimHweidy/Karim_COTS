#include "STD_TYPES.h"
#include <util/delay.h>
#include "PORT_interface.h"
#include "DIO_interface.h"

#include "STEPPER_interface.h"

void main(void)
{
	/*PORT_voidInit();
	uint32 Local_u32Counter =0;
*/
	/*StepperMotor_t Stepper1;
	Stepper1.PORT = DIO_u8PORTC;
	Stepper1.Blue_pin = DIO_u8PIN0;
	Stepper1.Pink_pin = DIO_u8PIN1;
	Stepper1.Yellow_pin = DIO_u8PIN2;
	Stepper1.Orange_pin = DIO_u8PIN3;*/
	extern StepperMotor_t StepperOne;
	PORT_voidInit();
	STEPPER_u8Rotate(&StepperOne, 720, ClockWise);

	while (1)
	{
		/*for (Local_u32Counter=0;Local_u32Counter<=512;Local_u32Counter++)
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(2);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			_delay_ms(2);
		}
*/
	}
}
