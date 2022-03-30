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
#include "project.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    

    for(;;)
    {

//        if(1UL == Cy_GPIO_Read(Pin_sw_0_PORT, Pin_sw_0_NUM))
//        {
//            /* Insert logic for High pin state */
//            Cy_GPIO_Write(Pin_led_0_PORT,Pin_led_0_NUM, 1);
//        }
//        else
//        {
//            /* Insert logic for Low pin state */
//            Cy_GPIO_Write(Pin_led_0_PORT,Pin_led_0_NUM, 0);
//        }

        /* Place your application code here. */
    }
}

/* [] END OF FILE */
