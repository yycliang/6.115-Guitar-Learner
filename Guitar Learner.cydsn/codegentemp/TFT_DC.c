/*******************************************************************************
* File Name: TFT_DC.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "TFT_DC.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TFT_DC__PORT == 15 && ((TFT_DC__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TFT_DC_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void TFT_DC_Write(uint8 value) 
{
    uint8 staticBits = (TFT_DC_DR & (uint8)(~TFT_DC_MASK));
    TFT_DC_DR = staticBits | ((uint8)(value << TFT_DC_SHIFT) & TFT_DC_MASK);
}


/*******************************************************************************
* Function Name: TFT_DC_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TFT_DC_DM_STRONG     Strong Drive 
*  TFT_DC_DM_OD_HI      Open Drain, Drives High 
*  TFT_DC_DM_OD_LO      Open Drain, Drives Low 
*  TFT_DC_DM_RES_UP     Resistive Pull Up 
*  TFT_DC_DM_RES_DWN    Resistive Pull Down 
*  TFT_DC_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TFT_DC_DM_DIG_HIZ    High Impedance Digital 
*  TFT_DC_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TFT_DC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TFT_DC_0, mode);
}


/*******************************************************************************
* Function Name: TFT_DC_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro TFT_DC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TFT_DC_Read(void) 
{
    return (TFT_DC_PS & TFT_DC_MASK) >> TFT_DC_SHIFT;
}


/*******************************************************************************
* Function Name: TFT_DC_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 TFT_DC_ReadDataReg(void) 
{
    return (TFT_DC_DR & TFT_DC_MASK) >> TFT_DC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TFT_DC_INTSTAT) 

    /*******************************************************************************
    * Function Name: TFT_DC_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 TFT_DC_ClearInterrupt(void) 
    {
        return (TFT_DC_INTSTAT & TFT_DC_MASK) >> TFT_DC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
