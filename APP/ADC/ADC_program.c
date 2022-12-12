/**
 * @file EXTI_program.c
 * @author Karim Hweidy
 * @brief this file implements the EXTI module functions
 * @version 1.0 
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"


#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "ADC_private.h"
#include "ADC_reg.h"
#include "DIO_interface.h"


void ADC_voidInit(void)
{

#if ADC_REFERENCE_VOLTAGE == ADC_u8AREF
	CLR_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);

#elif ADC_REFERENCE_VOLTAGE == ADC_u8AVCC
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

#elif ADC_REFERENCE_VOLTAGE == ADC_u8Reserved
	SET_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);


#elif ADC_REFERENCE_VOLTAGE == ADC_u8Internal_Voltage_REF
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else 
#error  ADC_REFERENCE_VOLTAGE configuration option
#endif



#if ADC_LEFT_ADJUST   == DISABLED
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_LEFT_ADJUST == ENABLED
	SET_BIT(ADMUX,ADMUX_ADLAR);
#else
#error wrong ADC_LEFT_ADJUST configuration option
#endif

#if ADC_PRESCALER == ADC_u8Prescaler2_0
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler2
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler4
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler8
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler16
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler32
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler64
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PRESCALER == ADC_u8Prescaler128
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#else
#error wrong ADC_PRESCALER configuration option
#endif

#if ADC_ENABLE   == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_ENABLE == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error wrong ADC_ENABLE configuration option
#endif

}

uint8 ADC_u8GetChannelReading(uint8 Copy_u8Channel)
{
	uint8 Local_u8ReadData;
	ADMUX |= Copy_u8Channel;
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	ADCSRA |= (1 << ADCSRA_ADIF);
	Local_u8ReadData = ADCH;
	return Local_u8ReadData;

}


