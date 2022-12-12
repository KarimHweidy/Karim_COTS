/**************************************************************/
/**************************************************************/
/*********		Author: Karim Hweidy			*******************/
/*********		File: CLCD_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SSD_private.h"
#include "SSD_cfg.h"
#include "SSD_interface.h"


uint8 SSD_u8SetNumber(SSD_Object * Copy_pSSDObject, uint8 Copy_Data)
{
    uint8 Local_u8ErrorState=OK;
    if (Copy_pSSDObject!=NULL)
    {
    	if ((Copy_pSSDObject->SSD_u8Type) == (CommonAnode))
    	{
    		if (Copy_pSSDObject->SSD_u8Pin==DIO_u8PIN0)
    		{
    			DIO_u8SetPortValue(Copy_pSSDObject->SSD_u8Port,~(Copy_Data));
    			DIO_u8SetPinValue(Copy_pSSDObject->SSD_u8EnablePort,Copy_pSSDObject->SSD_u8EnablePin,DIO_u8PIN_HIGH);
    		}
    		else if (Copy_pSSDObject->SSD_u8Pin==DIO_u8PIN1)
    		{
    			DIO_u8SetPortValue(Copy_pSSDObject->SSD_u8Port,~(Copy_Data<<1));
    			DIO_u8SetPinValue(Copy_pSSDObject->SSD_u8EnablePort,Copy_pSSDObject->SSD_u8EnablePin,DIO_u8PIN_HIGH);
    		}
    		else
    		{
    			Local_u8ErrorState= NOK;
    		}
    	}
    	else if (Copy_pSSDObject->SSD_u8Type==CommonCathod)
    	{
    		if (Copy_pSSDObject->SSD_u8Pin==DIO_u8PIN0)
       		{
      			DIO_u8SetPortValue(Copy_pSSDObject->SSD_u8Port,(Copy_Data));
      			DIO_u8SetPinValue(Copy_pSSDObject->SSD_u8EnablePort,Copy_pSSDObject->SSD_u8EnablePin,DIO_u8PIN_HIGH);
       		}
    		else if (Copy_pSSDObject->SSD_u8Pin==DIO_u8PIN1)
    		{
    			DIO_u8SetPortValue(Copy_pSSDObject->SSD_u8Port,(Copy_Data<<1));
    			DIO_u8SetPinValue(Copy_pSSDObject->SSD_u8EnablePort,Copy_pSSDObject->SSD_u8EnablePin,DIO_u8PIN_HIGH);
    		}
    		else
    		{
    			Local_u8ErrorState= NOK;
    		}
    	}

    }
    else
    {
    	Local_u8ErrorState=NULL_PTR_ERR;
    }
    return Local_u8ErrorState;
}
