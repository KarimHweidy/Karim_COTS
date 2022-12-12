#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "STEPPER_interface.h"


/* please enter the values like this
 * StepperMotor_t VarName = {PORT,Blue_pin,Pink_pin,Yellow_pin,Orange_pin};
 */

/*Please select the port to connect the Motor  options :    1- DIO_u8PORTA
	 *                                                      2- DIO_u8PORTB
	 *                                                      3- DIO_u8PORTC
	 *                                                      4- DIO_u8PORTD */


/*Please select the pins to connect the motor options :     1- DIO_u8PIN0
	 *                                                      2- DIO_u8PIN1
	 *                                                      3- DIO_u8PIN2
	 *                                                      4- DIO_u8PIN3
	 *                                                      5- DIO_u8PIN4
	 *                                                      6- DIO_u8PIN5
	 *                                                      7- DIO_u8PIN6
	 *                                                      8- DIO_u8PIN7 */



StepperMotor_t StepperOne = {DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN1,DIO_u8PIN2,DIO_u8PIN3};

