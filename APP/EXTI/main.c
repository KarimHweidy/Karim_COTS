#include "STD_TYPES.h"
#include "defines.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
/*
#define MCUCR    *((volatile uint8*)0x55)
#define GICR     *((volatile uint8*)0x5B)
#define SREG     *((volatile uint8*)0x5F)



void main(void)
{
	PORT_voidInit();

	/*configure falling edge trigger on INT0*/

	/*CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

	/*Enable INT0 Interrupt*/
	/*SET_BIT(GICR,6);

	/*Enable GIE*/

/*	SET_BIT(SREG,7);


	while (1)
	{

	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
}*/
void main(void)
{
	PORT_voidInit();
	EXTI_voidInitInt0();
	EXTI_voidInitInt1();
	GIE_voidEnableGlobal();

	while (1)
	{

	}
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
}
