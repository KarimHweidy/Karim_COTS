



#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

typedef struct
{
	uint8 DCM_u8SwitchPort;
	uint8 DCM_u8Switch1Pin;
	uint8 DCM_u8Switch2Pin;
	uint8 DCM_u8Switch3Pin;
	uint8 DCM_u8Switch4Pin;
}DCM_cfg;



void DCM_voidCW(DCM_cfg * Copy_pDCMcfg);
void DCM_voidCCW(DCM_cfg * Copy_pDCMcfg);
void DCM_voidBrake(DCM_cfg * Copy_pDCMcfg);


#endif
