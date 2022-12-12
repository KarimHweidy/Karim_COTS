#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DAC_interface.h"


void main(void)
{
	PORT_voidInit();


	while(1)
	{
		DAC_voidSetAnalogeVolt(5000);
	}
}
