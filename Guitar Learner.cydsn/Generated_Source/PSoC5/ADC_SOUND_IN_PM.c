/*******************************************************************************
* File Name: ADC_SOUND_IN_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SOUND_IN.h"

static ADC_SOUND_IN_BACKUP_STRUCT ADC_SOUND_IN_backup =
{
    ADC_SOUND_IN_DISABLED,
    ADC_SOUND_IN_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: ADC_SOUND_IN_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_SOUND_IN_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void ADC_SOUND_IN_SaveConfig(void) 
{
    ADC_SOUND_IN_backup.deccr = ADC_SOUND_IN_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: ADC_SOUND_IN_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_SOUND_IN_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void ADC_SOUND_IN_RestoreConfig(void) 
{
    ADC_SOUND_IN_DEC_CR_REG = ADC_SOUND_IN_backup.deccr;
}


/*******************************************************************************
* Function Name: ADC_SOUND_IN_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_SOUND_IN_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_SOUND_IN_Sleep(void) 
{
    /* Save ADC enable state */
    if((ADC_SOUND_IN_ACT_PWR_DEC_EN == (ADC_SOUND_IN_PWRMGR_DEC_REG & ADC_SOUND_IN_ACT_PWR_DEC_EN)) &&
       (ADC_SOUND_IN_ACT_PWR_DSM_EN == (ADC_SOUND_IN_PWRMGR_DSM_REG & ADC_SOUND_IN_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        ADC_SOUND_IN_backup.enableState = ADC_SOUND_IN_ENABLED;
        if((ADC_SOUND_IN_DEC_CR_REG & ADC_SOUND_IN_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            ADC_SOUND_IN_backup.enableState |= ADC_SOUND_IN_STARTED;
        }
		
        /* Stop the configuration */
        ADC_SOUND_IN_Stop();
    }
    else
    {
        /* Component is disabled */
        ADC_SOUND_IN_backup.enableState = ADC_SOUND_IN_DISABLED;
    }

    /* Save the user configuration */
    ADC_SOUND_IN_SaveConfig();
}


/*******************************************************************************
* Function Name: ADC_SOUND_IN_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_SOUND_IN_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_SOUND_IN_Wakeup(void) 
{
    /* Restore the configuration */
    ADC_SOUND_IN_RestoreConfig();

    /* Enables the component operation */
    if(ADC_SOUND_IN_backup.enableState != ADC_SOUND_IN_DISABLED)
    {
        ADC_SOUND_IN_Enable();
        if((ADC_SOUND_IN_backup.enableState & ADC_SOUND_IN_STARTED) != 0u)
        {
            ADC_SOUND_IN_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
