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
#include <stdio.h>

void func_interrupt()
{
 /* User Code Here */
    printf("Start interrupt\r\n");
    CyDelay(50);
    Cy_GPIO_Write(Pin_led_0_PORT,Pin_led_0_NUM, 1);
    CyDelay(50);
    while(1UL == Cy_GPIO_Read(Pin_sw_0_PORT, Pin_sw_0_NUM));
    CyDelay(50);
    printf("End of interrupt\r\n");
    CyDelay(50);
    Cy_GPIO_Write(Pin_led_0_PORT,Pin_led_0_NUM, 0);
    Cy_GPIO_ClearInterrupt(Pin_sw_0_PORT, Pin_sw_0_NUM); 
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_SetInterruptEdge(Pin_sw_0_PORT, Pin_sw_0_NUM, CY_GPIO_INTR_RISING);
    Cy_GPIO_SetInterruptMask(Pin_sw_0_PORT, Pin_sw_0_NUM, CY_GPIO_INTR_EN_MASK);

    
    Cy_SysInt_Init(&SysInt_1_cfg, func_interrupt);
    //NVIC_ClearPendingIRQ(SysInt_1_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)SysInt_1_cfg.intrSrc);
    
    UART_1_Start();
    setvbuf(stdin,NULL,_IONBF,0);
    
    printf("Start Uart\r\n");
    int i=0;

    for(;;)
    {
        /* Place your application code here. */
        printf("count = %d\r\n", i);
        i++;
        CyDelay(1000);
    }
}

/* [] END OF FILE */
