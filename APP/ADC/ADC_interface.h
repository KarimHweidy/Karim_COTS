#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8Prescaler2_0              1u
#define ADC_u8Prescaler2                2u
#define ADC_u8Prescaler4                3u
#define ADC_u8Prescaler8                4u
#define ADC_u8Prescaler16               5u
#define ADC_u8Prescaler32               6u
#define ADC_u8Prescaler64               7u
#define ADC_u8Prescaler128              8u


#define ADC_u8AREF                      1u
#define ADC_u8AVCC                      2u
#define ADC_u8Reserved                  3u
#define ADC_u8Internal_Voltage_REF      4u


void ADC_voidInit(void);

uint8 ADC_u8GetChannelReading(uint8 Copy_u8Channel);







#endif
