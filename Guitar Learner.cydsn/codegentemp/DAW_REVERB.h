/*******************************************************************************
* File Name: DAW_REVERB.h  
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

#if !defined(CY_PINS_DAW_REVERB_H) /* Pins DAW_REVERB_H */
#define CY_PINS_DAW_REVERB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DAW_REVERB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DAW_REVERB__PORT == 15 && ((DAW_REVERB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DAW_REVERB_Write(uint8 value);
void    DAW_REVERB_SetDriveMode(uint8 mode);
uint8   DAW_REVERB_ReadDataReg(void);
uint8   DAW_REVERB_Read(void);
void    DAW_REVERB_SetInterruptMode(uint16 position, uint16 mode);
uint8   DAW_REVERB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DAW_REVERB_SetDriveMode() function.
     *  @{
     */
        #define DAW_REVERB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DAW_REVERB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DAW_REVERB_DM_RES_UP          PIN_DM_RES_UP
        #define DAW_REVERB_DM_RES_DWN         PIN_DM_RES_DWN
        #define DAW_REVERB_DM_OD_LO           PIN_DM_OD_LO
        #define DAW_REVERB_DM_OD_HI           PIN_DM_OD_HI
        #define DAW_REVERB_DM_STRONG          PIN_DM_STRONG
        #define DAW_REVERB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DAW_REVERB_MASK               DAW_REVERB__MASK
#define DAW_REVERB_SHIFT              DAW_REVERB__SHIFT
#define DAW_REVERB_WIDTH              1u

/* Interrupt constants */
#if defined(DAW_REVERB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DAW_REVERB_SetInterruptMode() function.
     *  @{
     */
        #define DAW_REVERB_INTR_NONE      (uint16)(0x0000u)
        #define DAW_REVERB_INTR_RISING    (uint16)(0x0001u)
        #define DAW_REVERB_INTR_FALLING   (uint16)(0x0002u)
        #define DAW_REVERB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DAW_REVERB_INTR_MASK      (0x01u) 
#endif /* (DAW_REVERB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DAW_REVERB_PS                     (* (reg8 *) DAW_REVERB__PS)
/* Data Register */
#define DAW_REVERB_DR                     (* (reg8 *) DAW_REVERB__DR)
/* Port Number */
#define DAW_REVERB_PRT_NUM                (* (reg8 *) DAW_REVERB__PRT) 
/* Connect to Analog Globals */                                                  
#define DAW_REVERB_AG                     (* (reg8 *) DAW_REVERB__AG)                       
/* Analog MUX bux enable */
#define DAW_REVERB_AMUX                   (* (reg8 *) DAW_REVERB__AMUX) 
/* Bidirectional Enable */                                                        
#define DAW_REVERB_BIE                    (* (reg8 *) DAW_REVERB__BIE)
/* Bit-mask for Aliased Register Access */
#define DAW_REVERB_BIT_MASK               (* (reg8 *) DAW_REVERB__BIT_MASK)
/* Bypass Enable */
#define DAW_REVERB_BYP                    (* (reg8 *) DAW_REVERB__BYP)
/* Port wide control signals */                                                   
#define DAW_REVERB_CTL                    (* (reg8 *) DAW_REVERB__CTL)
/* Drive Modes */
#define DAW_REVERB_DM0                    (* (reg8 *) DAW_REVERB__DM0) 
#define DAW_REVERB_DM1                    (* (reg8 *) DAW_REVERB__DM1)
#define DAW_REVERB_DM2                    (* (reg8 *) DAW_REVERB__DM2) 
/* Input Buffer Disable Override */
#define DAW_REVERB_INP_DIS                (* (reg8 *) DAW_REVERB__INP_DIS)
/* LCD Common or Segment Drive */
#define DAW_REVERB_LCD_COM_SEG            (* (reg8 *) DAW_REVERB__LCD_COM_SEG)
/* Enable Segment LCD */
#define DAW_REVERB_LCD_EN                 (* (reg8 *) DAW_REVERB__LCD_EN)
/* Slew Rate Control */
#define DAW_REVERB_SLW                    (* (reg8 *) DAW_REVERB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DAW_REVERB_PRTDSI__CAPS_SEL       (* (reg8 *) DAW_REVERB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DAW_REVERB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DAW_REVERB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DAW_REVERB_PRTDSI__OE_SEL0        (* (reg8 *) DAW_REVERB__PRTDSI__OE_SEL0) 
#define DAW_REVERB_PRTDSI__OE_SEL1        (* (reg8 *) DAW_REVERB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DAW_REVERB_PRTDSI__OUT_SEL0       (* (reg8 *) DAW_REVERB__PRTDSI__OUT_SEL0) 
#define DAW_REVERB_PRTDSI__OUT_SEL1       (* (reg8 *) DAW_REVERB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DAW_REVERB_PRTDSI__SYNC_OUT       (* (reg8 *) DAW_REVERB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DAW_REVERB__SIO_CFG)
    #define DAW_REVERB_SIO_HYST_EN        (* (reg8 *) DAW_REVERB__SIO_HYST_EN)
    #define DAW_REVERB_SIO_REG_HIFREQ     (* (reg8 *) DAW_REVERB__SIO_REG_HIFREQ)
    #define DAW_REVERB_SIO_CFG            (* (reg8 *) DAW_REVERB__SIO_CFG)
    #define DAW_REVERB_SIO_DIFF           (* (reg8 *) DAW_REVERB__SIO_DIFF)
#endif /* (DAW_REVERB__SIO_CFG) */

/* Interrupt Registers */
#if defined(DAW_REVERB__INTSTAT)
    #define DAW_REVERB_INTSTAT            (* (reg8 *) DAW_REVERB__INTSTAT)
    #define DAW_REVERB_SNAP               (* (reg8 *) DAW_REVERB__SNAP)
    
	#define DAW_REVERB_0_INTTYPE_REG 		(* (reg8 *) DAW_REVERB__0__INTTYPE)
#endif /* (DAW_REVERB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DAW_REVERB_H */


/* [] END OF FILE */
