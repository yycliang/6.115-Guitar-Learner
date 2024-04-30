/*******************************************************************************
* File Name: DAC_SOUND_OUT_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DAC_SOUND_OUT.h"

static DAC_SOUND_OUT_backupStruct DAC_SOUND_OUT_backup;


/*******************************************************************************
* Function Name: DAC_SOUND_OUT_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void DAC_SOUND_OUT_SaveConfig(void) 
{
    if (!((DAC_SOUND_OUT_CR1 & DAC_SOUND_OUT_SRC_MASK) == DAC_SOUND_OUT_SRC_UDB))
    {
        DAC_SOUND_OUT_backup.data_value = DAC_SOUND_OUT_Data;
    }
}


/*******************************************************************************
* Function Name: DAC_SOUND_OUT_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void DAC_SOUND_OUT_RestoreConfig(void) 
{
    if (!((DAC_SOUND_OUT_CR1 & DAC_SOUND_OUT_SRC_MASK) == DAC_SOUND_OUT_SRC_UDB))
    {
        if((DAC_SOUND_OUT_Strobe & DAC_SOUND_OUT_STRB_MASK) == DAC_SOUND_OUT_STRB_EN)
        {
            DAC_SOUND_OUT_Strobe &= (uint8)(~DAC_SOUND_OUT_STRB_MASK);
            DAC_SOUND_OUT_Data = DAC_SOUND_OUT_backup.data_value;
            DAC_SOUND_OUT_Strobe |= DAC_SOUND_OUT_STRB_EN;
        }
        else
        {
            DAC_SOUND_OUT_Data = DAC_SOUND_OUT_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: DAC_SOUND_OUT_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  DAC_SOUND_OUT_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void DAC_SOUND_OUT_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(DAC_SOUND_OUT_ACT_PWR_EN == (DAC_SOUND_OUT_PWRMGR & DAC_SOUND_OUT_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        DAC_SOUND_OUT_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        DAC_SOUND_OUT_backup.enableState = 0u;
    }
    
    DAC_SOUND_OUT_Stop();
    DAC_SOUND_OUT_SaveConfig();
}


/*******************************************************************************
* Function Name: DAC_SOUND_OUT_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  DAC_SOUND_OUT_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DAC_SOUND_OUT_Wakeup(void) 
{
    DAC_SOUND_OUT_RestoreConfig();
    
    if(DAC_SOUND_OUT_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        DAC_SOUND_OUT_Enable();

        /* Restore the data register */
        DAC_SOUND_OUT_SetValue(DAC_SOUND_OUT_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
