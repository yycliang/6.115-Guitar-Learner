/*******************************************************************************
* File Name: BTN_DAW.h  
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

#if !defined(CY_PINS_BTN_DAW_H) /* Pins BTN_DAW_H */
#define CY_PINS_BTN_DAW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BTN_DAW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BTN_DAW__PORT == 15 && ((BTN_DAW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BTN_DAW_Write(uint8 value);
void    BTN_DAW_SetDriveMode(uint8 mode);
uint8   BTN_DAW_ReadDataReg(void);
uint8   BTN_DAW_Read(void);
void    BTN_DAW_SetInterruptMode(uint16 position, uint16 mode);
uint8   BTN_DAW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BTN_DAW_SetDriveMode() function.
     *  @{
     */
        #define BTN_DAW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BTN_DAW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BTN_DAW_DM_RES_UP          PIN_DM_RES_UP
        #define BTN_DAW_DM_RES_DWN         PIN_DM_RES_DWN
        #define BTN_DAW_DM_OD_LO           PIN_DM_OD_LO
        #define BTN_DAW_DM_OD_HI           PIN_DM_OD_HI
        #define BTN_DAW_DM_STRONG          PIN_DM_STRONG
        #define BTN_DAW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BTN_DAW_MASK               BTN_DAW__MASK
#define BTN_DAW_SHIFT              BTN_DAW__SHIFT
#define BTN_DAW_WIDTH              1u

/* Interrupt constants */
#if defined(BTN_DAW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BTN_DAW_SetInterruptMode() function.
     *  @{
     */
        #define BTN_DAW_INTR_NONE      (uint16)(0x0000u)
        #define BTN_DAW_INTR_RISING    (uint16)(0x0001u)
        #define BTN_DAW_INTR_FALLING   (uint16)(0x0002u)
        #define BTN_DAW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BTN_DAW_INTR_MASK      (0x01u) 
#endif /* (BTN_DAW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BTN_DAW_PS                     (* (reg8 *) BTN_DAW__PS)
/* Data Register */
#define BTN_DAW_DR                     (* (reg8 *) BTN_DAW__DR)
/* Port Number */
#define BTN_DAW_PRT_NUM                (* (reg8 *) BTN_DAW__PRT) 
/* Connect to Analog Globals */                                                  
#define BTN_DAW_AG                     (* (reg8 *) BTN_DAW__AG)                       
/* Analog MUX bux enable */
#define BTN_DAW_AMUX                   (* (reg8 *) BTN_DAW__AMUX) 
/* Bidirectional Enable */                                                        
#define BTN_DAW_BIE                    (* (reg8 *) BTN_DAW__BIE)
/* Bit-mask for Aliased Register Access */
#define BTN_DAW_BIT_MASK               (* (reg8 *) BTN_DAW__BIT_MASK)
/* Bypass Enable */
#define BTN_DAW_BYP                    (* (reg8 *) BTN_DAW__BYP)
/* Port wide control signals */                                                   
#define BTN_DAW_CTL                    (* (reg8 *) BTN_DAW__CTL)
/* Drive Modes */
#define BTN_DAW_DM0                    (* (reg8 *) BTN_DAW__DM0) 
#define BTN_DAW_DM1                    (* (reg8 *) BTN_DAW__DM1)
#define BTN_DAW_DM2                    (* (reg8 *) BTN_DAW__DM2) 
/* Input Buffer Disable Override */
#define BTN_DAW_INP_DIS                (* (reg8 *) BTN_DAW__INP_DIS)
/* LCD Common or Segment Drive */
#define BTN_DAW_LCD_COM_SEG            (* (reg8 *) BTN_DAW__LCD_COM_SEG)
/* Enable Segment LCD */
#define BTN_DAW_LCD_EN                 (* (reg8 *) BTN_DAW__LCD_EN)
/* Slew Rate Control */
#define BTN_DAW_SLW                    (* (reg8 *) BTN_DAW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BTN_DAW_PRTDSI__CAPS_SEL       (* (reg8 *) BTN_DAW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BTN_DAW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BTN_DAW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BTN_DAW_PRTDSI__OE_SEL0        (* (reg8 *) BTN_DAW__PRTDSI__OE_SEL0) 
#define BTN_DAW_PRTDSI__OE_SEL1        (* (reg8 *) BTN_DAW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BTN_DAW_PRTDSI__OUT_SEL0       (* (reg8 *) BTN_DAW__PRTDSI__OUT_SEL0) 
#define BTN_DAW_PRTDSI__OUT_SEL1       (* (reg8 *) BTN_DAW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BTN_DAW_PRTDSI__SYNC_OUT       (* (reg8 *) BTN_DAW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BTN_DAW__SIO_CFG)
    #define BTN_DAW_SIO_HYST_EN        (* (reg8 *) BTN_DAW__SIO_HYST_EN)
    #define BTN_DAW_SIO_REG_HIFREQ     (* (reg8 *) BTN_DAW__SIO_REG_HIFREQ)
    #define BTN_DAW_SIO_CFG            (* (reg8 *) BTN_DAW__SIO_CFG)
    #define BTN_DAW_SIO_DIFF           (* (reg8 *) BTN_DAW__SIO_DIFF)
#endif /* (BTN_DAW__SIO_CFG) */

/* Interrupt Registers */
#if defined(BTN_DAW__INTSTAT)
    #define BTN_DAW_INTSTAT            (* (reg8 *) BTN_DAW__INTSTAT)
    #define BTN_DAW_SNAP               (* (reg8 *) BTN_DAW__SNAP)
    
	#define BTN_DAW_0_INTTYPE_REG 		(* (reg8 *) BTN_DAW__0__INTTYPE)
#endif /* (BTN_DAW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BTN_DAW_H */


/* [] END OF FILE */
