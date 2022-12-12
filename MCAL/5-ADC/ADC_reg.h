#ifndef ADC_REG_H_
#define ADC_REG_H_


#define ADMUX              *((volatile uint8*)0x27)        /*@brief Global interrupt control register*/
#define ADMUX_REFS1         7u                              /*@breif INT1 control bit*/
#define ADMUX_REFS0         6u                              /*@breif INT0 control bit*/
#define ADMUX_ADLAR         5u                              /*@breif INT2 control bit*/
#define ADMUX_MUX4			4u
#define ADMUX_MUX3		    3u
#define ADMUX_MUX2		    2u
#define ADMUX_MUX1		    1u
#define ADMUX_MUX0		    0u  
					      
#define ADCSRA             *((volatile uint8*)0x26)
#define ADCSRA_ADPS0           0u
#define ADCSRA_ADPS1           1u
#define ADCSRA_ADPS2           2u
#define ADCSRA_ADIE            3u
#define ADCSRA_ADIF            4u
#define ADCSRA_ADATE           5u
#define ADCSRA_ADSC            6u
#define ADCSRA_ADEN            7u					      
					      
					      
#define ADCH            *((volatile uint8*)0x25)
#define ADCL            *((volatile uint8*)0x24)


#define SFIOR            *((volatile uint8*)0x50)
#define SFIOR_ADTS2       7u
#define SFIOR_ADTS1       6u
#define SFIOR_ADTS0       5u
#define SFIOR_RES         4u





#endif