#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DAC_interface.h"
#include "DAC_cfg.h"
#include <util/delay.h>


void DAC_voidSetAnalogeVolt(uint16 Copy_u16Volt)
{   
    sint16 Local_s16Loopcounter=0;
	uint16 Local_u16Step=(uint16)(((uint32)Copy_u16Volt*255ul/5ul)/1000ul);
	for(Local_s16Loopcounter=0;Local_s16Loopcounter<=Local_u16Step;Local_s16Loopcounter++)
	{

		DIO_u8SetPortValue(DAC_PORT,Local_s16Loopcounter);
        _delay_ms(20);
	}
	for(Local_s16Loopcounter=Local_u16Step;Local_s16Loopcounter>=0;Local_s16Loopcounter--)
	{

		DIO_u8SetPortValue(DAC_PORT,Local_s16Loopcounter);
		_delay_ms(20);
	}
}
