#include "msp.h"
#include <stdio.h>
#include <time.h>

#include "UART.h"
/**
 * main.c
 */
#define UART
void main()
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;	// stop watchdog timer
	int counter = 0;
	int TimerSecOnes;
	int TimerSecTens;
	int TimerMinOnes;
	int TimerMinTens;
	int TimerHourOnes;
	int TimerHourTens;
	char THT[20];
	char THO[20];
	char TMT[20];
	char TMO[20];
	char TST[20];
	char TSO[20];

#ifdef UART
         P4DIR |= 0x20;
         P4IN |= 0x20;
           config_UART();
           LCD_reset();
           TimerHourTens = 0;
           TimerHourOnes = 4;
           TimerMinTens = 3;
           TimerMinOnes = 2;
           TimerSecTens = 0;
           TimerSecOnes = 0;

  for(;;)
  {



           volatile int i = 0;
           int c;
           if (TimerSecOnes >= 9)
           {
               TimerSecOnes = 0;
               TimerSecTens++;
           }
           else
           {
               TimerSecOnes++;

           }

           if (TimerSecTens > 5)
           {
               TimerSecTens = 0;
               TimerMinOnes++;
           }
           if (TimerMinOnes > 9)
           {
               TimerMinOnes = 0;
               TimerMinTens++;
           }
           if (TimerMinTens > 5)
           {
               TimerMinTens = 0;
               TimerHourOnes++;
           }
           if (TimerHourOnes > 5 )
           {
               TimerHourOnes = 0;
               TimerHourTens++;
           }



           for (c = 1; c <= 327670; c++)
               {}
           sprintf(THT, "%lu", TimerHourTens);
           sprintf(THO, "%lu", TimerHourOnes);
           sprintf(TMT, "%lu", TimerMinTens);
           sprintf(TMO, "%lu", TimerMinOnes);
           sprintf(TST, "%lu", TimerSecTens);
           sprintf(TSO, "%lu", TimerSecOnes);
           LCD_reset();
           UART_send(THT, 1);
           UART_send(THO, 1);
           UART_send(":", 1);
           UART_send(TMT, 1);
           UART_send(TMO, 1);
           UART_send(":", 1);
           UART_send(TST, 1);
           UART_send(TSO, 1);
           UART_send("                 ", 8);
           UART_send("Alarm::", 7);





  }







#endif


}
