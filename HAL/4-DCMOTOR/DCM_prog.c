

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DCM_interface.h"


void DCM_voidCW(DCM_cfg * Copy_pDCMcfg)
{
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch1Pin,DIO_u8PIN_LOW);
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch2Pin,DIO_u8PIN_HIGH);
   
}

void DCM_voidCCW(DCM_cfg * Copy_pDCMcfg)
{
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch2Pin,DIO_u8PIN_LOW);
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch1Pin,DIO_u8PIN_HIGH);
}

void DCM_voidBrake(DCM_cfg * Copy_pDCMcfg)
{
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch1Pin,DIO_u8PIN_LOW);
    DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8SwitchPort,Copy_pDCMcfg->DCM_u8Switch2Pin,DIO_u8PIN_LOW);
 }
