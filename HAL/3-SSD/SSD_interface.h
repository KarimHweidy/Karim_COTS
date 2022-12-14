/**************************************************************/
/**************************************************************/
/*********		Author: Ahmed Abdelaziz			*******************/
/*********		File: CLCD_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/



#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	uint8  SSD_u8Type;
	uint8  SSD_u8Port;
	uint8  SSD_u8Pin;
	uint8  SSD_u8EnablePort;
	uint8  SSD_u8EnablePin;
} SSD_Object ;

SSD_Object SSD_cfg;

uint8 SSD_u8SetNumber(SSD_Object * Copy_pSSDObject, uint8 Copy_Data);

#endif
