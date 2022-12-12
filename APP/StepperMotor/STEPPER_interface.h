/**************************************************************/
/**************************************************************/
/*********		Author: Karim Hweidy		*******************/
/*********		File: STEPPER_interface.h	*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
#include "STEPPER_private.h"

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef struct {
	uint8 PORT;
	uint8 Blue_pin;
	uint8 Pink_pin;
	uint8 Yellow_pin;
	uint8 Orange_pin;
}StepperMotor_t;


uint8 STEPPER_u8Rotate(const StepperMotor_t* Copy_puStepperMotor, uint16 Copy_u16StepperAngle, uint8 Copy_u8StepperDirection);

#endif
