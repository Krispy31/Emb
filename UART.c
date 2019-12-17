/*
 * UART.c
 *
 *  Created on: Dec 1, 2019
 *      Author: crist
 */


#include "msp.h"
#include "UART.h"
/*
 * RX->P3.2
 * TX->P3.3
 */
#define UCC

/********************************************************
 * Function Desciption
 * Must select TX and RX pins on MSP
 *  P3SEL0 |= (BIT2 | BIT3); // TX & RX Primary mode
 * Must find clock for UART
 ********************************************************/

void config_UART()
{
#ifdef UCC

     UCA2CTLW0 = UCSWRST;
//Initialize EUSCI (UART) Setting High
    UCA2CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;
//Setting Low
    UCA2CTLW0 &= ~EUSCI_A_CTLW0_PEN         // Parity disabled
    & ~EUSCI_A_CTLW0_MODE0                  // Set to uart mode
    & ~EUSCI_A_CTLW0_MODE1
    & ~EUSCI_A_CTLW0_MSB                    // LSB first
    & ~EUSCI_A_CTLW0_SEVENBIT               // 8 bit character length
    & ~EUSCI_A_CTLW0_SPB;                   // One stop bit one start bit is default

                        //Baud Rate
    UCA2BR0 = 19;                           // Set Baud Rate
    UCA2BR1 = 0x00;
    UCA2MCTLW = 0xAA | UCOS16 | 8;



    P3SEL0 |= (BIT2 | BIT3); // TX & RX Primary mode
    UCA2CTLW0 &= ~UCSWRST;                  // Initialize eUSCI
    //UCA2IE |= EUSCI_A_IE_RXIE;            // Enable interrupt for RX receive

    /***************************************/



#endif
}

void UART_1byte(uint8_t data)
{
    while(EUSCI_A_IFG_TXIFG & ~UCA2IFG);
    EUSCI_A2->TXBUF = data;

}

void UART_send(uint8_t * data, uint32_t length)
{
    volatile int i = 0;
    for (i; i< length; i++)
    {
        UART_1byte(data[i]);
    }
}



void LCD_reset()
{
    UART_1byte(0x7C);
    UART_1byte(0x2D);
}
