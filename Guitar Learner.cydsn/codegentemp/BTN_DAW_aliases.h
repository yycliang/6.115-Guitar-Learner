/*******************************************************************************
* File Name: BTN_DAW.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BTN_DAW_ALIASES_H) /* Pins BTN_DAW_ALIASES_H */
#define CY_PINS_BTN_DAW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define BTN_DAW_0			(BTN_DAW__0__PC)
#define BTN_DAW_0_INTR	((uint16)((uint16)0x0001u << BTN_DAW__0__SHIFT))

#define BTN_DAW_INTR_ALL	 ((uint16)(BTN_DAW_0_INTR))

#endif /* End Pins BTN_DAW_ALIASES_H */


/* [] END OF FILE */
