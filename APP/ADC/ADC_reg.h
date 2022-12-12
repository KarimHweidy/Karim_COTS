#ifndef ADC_REG_H_
#define ADC_REG_H_


#define ADMUX              *((volatile uint8*)0x27)        /*@brief ADC Multiplexer selection register*/
#define ADMUX_REFS1         7u                              /*@Brief REFS1 reference selection bit to select the voltage reference for the ADC*/
#define ADMUX_REFS0         6u                              /*@Brief REFS0 reference selection bit to select the voltage reference for the ADC*/
#define ADMUX_ADLAR         5u                              /*@breif ADC Left adjust result */
#define ADMUX_MUX4			4u                              /*@breif MUX4:0 analog channel and gain selection bits */
#define ADMUX_MUX3		    3u                              /*@breif MUX4:0 analog channel and gain selection bits */
#define ADMUX_MUX2		    2u                              /*@breif MUX4:0 analog channel and gain selection bits */
#define ADMUX_MUX1		    1u                              /*@breif MUX4:0 analog channel and gain selection bits */
#define ADMUX_MUX0		    0u                              /*@breif MUX4:0 analog channel and gain selection bits */
					      
#define ADCSRA             *((volatile uint8*)0x26)         /*@breif Control & status register A */
#define ADCSRA_ADPS0           0u                           /*ADPS 2:0 ADC prescaler select bits to determine the division factor between the XTAL frequency and the input clk to ADC*/
#define ADCSRA_ADPS1           1u                           /*ADPS 2:0 ADC prescaler select bits to determine the division factor between the XTAL frequency and the input clk to ADC*/
#define ADCSRA_ADPS2           2u                           /*ADPS 2:0 ADC prescaler select bits to determine the division factor between the XTAL frequency and the input clk to ADC*/
#define ADCSRA_ADIE            3u                           /*ADIE ADC interrupt enable*/
#define ADCSRA_ADIF            4u                           /*ADIF: ADC Interrupt Flag*/
#define ADCSRA_ADATE           5u                           /*ADATE: ADC Auto Trigger Enable*/
#define ADCSRA_ADSC            6u                           /*ADSC: ADC Start Conversion*/
#define ADCSRA_ADEN            7u					        /*ADEN: ADC Enable*/
					      
					      
#define ADCH            *((volatile uint8*)0x25)            /*The ADC Data Register*/
#define ADCL            *((volatile uint8*)0x24)            /*The ADC Data Register*/


#define SFIOR            *((volatile uint8*)0x50)           /*Special Function I/O Register*/
#define SFIOR_ADTS2       7u                                /*ADTS2:0: ADC Auto Trigger Source*/
#define SFIOR_ADTS1       6u                                /*ADTS2:0: ADC Auto Trigger Source*/
#define SFIOR_ADTS0       5u                                /*ADTS2:0: ADC Auto Trigger Source*/
#define SFIOR_RES         4u                                /*Res: Reserved Bit*/





#endif
