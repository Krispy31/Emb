/*
 * NECIR.c
 *
 *  Created on: Dec 16, 2019
 *      Author: Christopher
 */

#include "msp.h"
#include "UART.h"

void SetupIR (void)
{
    TIMER_A0->R = 0x0;
    TIMER_A0->CTL = TIMER_A_CTL_IE; //enable interrupts
    TIMER_A0->TIMER_A_CTL_MC_2;


}








