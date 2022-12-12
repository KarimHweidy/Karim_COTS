



#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

typedef struct
{
	uint8 DCM_u8SwitchPort;
	uint8 DCM_u8Switch1Pin;
	uint8 DCM_u8Switch2Pin;
	
}DCM_cfg;



void DCM_voidCW(const DCM_cfg * Copy_pDCMcfg);
void DCM_voidCCW(const DCM_cfg * Copy_pDCMcfg);
void DCM_voidBrake(const DCM_cfg * Copy_pDCMcfg);


#endif
