/*******************************************************************************
* File Name: ADC_Input.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ADC_Input_H) /* Pins ADC_Input_H */
#define CY_PINS_ADC_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADC_Input_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADC_Input__PORT == 15 && ((ADC_Input__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ADC_Input_Write(uint8 value);
void    ADC_Input_SetDriveMode(uint8 mode);
uint8   ADC_Input_ReadDataReg(void);
uint8   ADC_Input_Read(void);
void    ADC_Input_SetInterruptMode(uint16 position, uint16 mode);
uint8   ADC_Input_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ADC_Input_SetDriveMode() function.
     *  @{
     */
        #define ADC_Input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ADC_Input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ADC_Input_DM_RES_UP          PIN_DM_RES_UP
        #define ADC_Input_DM_RES_DWN         PIN_DM_RES_DWN
        #define ADC_Input_DM_OD_LO           PIN_DM_OD_LO
        #define ADC_Input_DM_OD_HI           PIN_DM_OD_HI
        #define ADC_Input_DM_STRONG          PIN_DM_STRONG
        #define ADC_Input_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ADC_Input_MASK               ADC_Input__MASK
#define ADC_Input_SHIFT              ADC_Input__SHIFT
#define ADC_Input_WIDTH              1u

/* Interrupt constants */
#if defined(ADC_Input__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ADC_Input_SetInterruptMode() function.
     *  @{
     */
        #define ADC_Input_INTR_NONE      (uint16)(0x0000u)
        #define ADC_Input_INTR_RISING    (uint16)(0x0001u)
        #define ADC_Input_INTR_FALLING   (uint16)(0x0002u)
        #define ADC_Input_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ADC_Input_INTR_MASK      (0x01u) 
#endif /* (ADC_Input__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_Input_PS                     (* (reg8 *) ADC_Input__PS)
/* Data Register */
#define ADC_Input_DR                     (* (reg8 *) ADC_Input__DR)
/* Port Number */
#define ADC_Input_PRT_NUM                (* (reg8 *) ADC_Input__PRT) 
/* Connect to Analog Globals */                                                  
#define ADC_Input_AG                     (* (reg8 *) ADC_Input__AG)                       
/* Analog MUX bux enable */
#define ADC_Input_AMUX                   (* (reg8 *) ADC_Input__AMUX) 
/* Bidirectional Enable */                                                        
#define ADC_Input_BIE                    (* (reg8 *) ADC_Input__BIE)
/* Bit-mask for Aliased Register Access */
#define ADC_Input_BIT_MASK               (* (reg8 *) ADC_Input__BIT_MASK)
/* Bypass Enable */
#define ADC_Input_BYP                    (* (reg8 *) ADC_Input__BYP)
/* Port wide control signals */                                                   
#define ADC_Input_CTL                    (* (reg8 *) ADC_Input__CTL)
/* Drive Modes */
#define ADC_Input_DM0                    (* (reg8 *) ADC_Input__DM0) 
#define ADC_Input_DM1                    (* (reg8 *) ADC_Input__DM1)
#define ADC_Input_DM2                    (* (reg8 *) ADC_Input__DM2) 
/* Input Buffer Disable Override */
#define ADC_Input_INP_DIS                (* (reg8 *) ADC_Input__INP_DIS)
/* LCD Common or Segment Drive */
#define ADC_Input_LCD_COM_SEG            (* (reg8 *) ADC_Input__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADC_Input_LCD_EN                 (* (reg8 *) ADC_Input__LCD_EN)
/* Slew Rate Control */
#define ADC_Input_SLW                    (* (reg8 *) ADC_Input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADC_Input_PRTDSI__CAPS_SEL       (* (reg8 *) ADC_Input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADC_Input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADC_Input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADC_Input_PRTDSI__OE_SEL0        (* (reg8 *) ADC_Input__PRTDSI__OE_SEL0) 
#define ADC_Input_PRTDSI__OE_SEL1        (* (reg8 *) ADC_Input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADC_Input_PRTDSI__OUT_SEL0       (* (reg8 *) ADC_Input__PRTDSI__OUT_SEL0) 
#define ADC_Input_PRTDSI__OUT_SEL1       (* (reg8 *) ADC_Input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADC_Input_PRTDSI__SYNC_OUT       (* (reg8 *) ADC_Input__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ADC_Input__SIO_CFG)
    #define ADC_Input_SIO_HYST_EN        (* (reg8 *) ADC_Input__SIO_HYST_EN)
    #define ADC_Input_SIO_REG_HIFREQ     (* (reg8 *) ADC_Input__SIO_REG_HIFREQ)
    #define ADC_Input_SIO_CFG            (* (reg8 *) ADC_Input__SIO_CFG)
    #define ADC_Input_SIO_DIFF           (* (reg8 *) ADC_Input__SIO_DIFF)
#endif /* (ADC_Input__SIO_CFG) */

/* Interrupt Registers */
#if defined(ADC_Input__INTSTAT)
    #define ADC_Input_INTSTAT            (* (reg8 *) ADC_Input__INTSTAT)
    #define ADC_Input_SNAP               (* (reg8 *) ADC_Input__SNAP)
    
	#define ADC_Input_0_INTTYPE_REG 		(* (reg8 *) ADC_Input__0__INTTYPE)
#endif /* (ADC_Input__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADC_Input_H */


/* [] END OF FILE */
