/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "GUI.h"
#include "tft.h"

void InitProject(void);

int main()
{         
    InitProject();                             // all of the emWin exmples use MainTask() as the entry point
    unsigned char lcd_position = 0;             // start LCD position and incremtn later
    int songStored[1000];                        // initialize an empty display array
    uint16 adcResult = 0;
    for(;;) {
    
        // ADC 
        AMux_1_Select(0); // Select the Sound Input     
        if( ADC_SOUND_IN_IsEndConversion(ADC_SOUND_IN_WAIT_FOR_RESULT) ) // Makes sure that conversion is done
        {
            LCD_Char_1_Position(0, lcd_position);
            LCD_Char_1_ClearDisplay();
            adcResult = ADC_SOUND_IN_GetResult16();		// read the adc and assign the value adcResult 
        if (adcResult & 0x8000)
        {
            adcResult = 0;       // ignore negative ADC results
        }
        else if (adcResult >= 0xfff)
        {
            adcResult = 0xfff;      // ignore high ADC results
        }
            LCD_Char_1_PrintNumber(adcResult); // Able to print 0 through A on LCD
            CyDelay(100);
        }
        // IF DAW BTN
        if (BTN_LEARN_Read() == 0) {
            LED_RED_Write(1);
            LED_YELLOW_Write(1);
            LED_GREEN_Write(1);
            
            //DAC 
            DAC_SOUND_OUT_SetValue(adcResult);
            GUI_DispStringAt("DAW MODE", 50, 50);
        }
        // IF LEARN BTN
        if (BTN_DAW_Read() == 0){ //When switch 2 is pressed 
            LED_RED_Write(0);
            LED_YELLOW_Write(0);
            LED_GREEN_Write(0);
            GUI_DispStringAt("LEARN MODE", 50, 50);
        }
        // DISPLAYING A SONG 
        
        
        // CORRECT AND INCORRECT
        
        // RECORDING AND PLAYING
    
    }
}

void InitProject()
{
    CyGlobalIntEnable;                      // Enable global interrupts
    SPIM_1_Start();                         // initialize SPIM component 
    GUI_Init();                             // initilize graphics library
    GUI_Clear();
    GUI_SetFont(&GUI_Font8x16);
    
    LCD_Char_1_Start();					// initialize lcd
	LCD_Char_1_ClearDisplay();
	ADC_SOUND_IN_Start();				// strt the ADC_SOUND_IN
	ADC_SOUND_IN_StartConvert();		// start the ADC_SOUND_IN conversion
    AMux_1_Start();                     // Start the MUX 
    DAC_SOUND_OUT_Start();  // starts DAC and calls enable()
}

/* [] END OF FILE */
