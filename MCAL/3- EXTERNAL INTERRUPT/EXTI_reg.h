#ifndef EXTI_REG_H_
#define EXTI_REG_H_


#define GICR              *((volatile uint8*)0x5B)        /*@brief Global interrupt control register*/
#define GICR_INT1         7u                              /*@breif INT1 control bit*/
#define GICR_INT0         6u                              /*@breif INT0 control bit*/
#define GICR_INT2         5u                              /*@breif INT2 control bit*/
					      
					      
#define MCUCR             *((volatile uint8*)0x55)
#define MCUCR_ISC00       0u
#define MCUCR_ISC01       1u
#define MCUCR_ISC10       2u
#define MCUCR_ISC11       3u
					      
					      
					      
#define MCUCSR            *((volatile uint8*)0x54)
#define MCUCSR_ISC2       6u




#endif