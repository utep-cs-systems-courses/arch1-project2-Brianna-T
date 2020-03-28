/*Timer "Clock"*/
#include <msp430.h>
#include "timer.h"

void configureClocks(){
  WDTCTL = WDTPW + WDTHOLD; //Disable Watchdog Timer
  BCSCTL1 = CALBC1_1MHZ;//my modification is 1 mhz
  DCOCTL = CALDCO_1MHZ;

  BCSCTL2 &= ~(SELS); //source = DCO
  BCSCTL2 |= DIVS_2;//modify DCO/4
}

void interrupts(){
  WDTCTL = WDTPW | //device reset
  WDTTMSEL |
  WDTCNTCL |
    1;//divide SMCLK by 8192.. why?
  IE1 |= WDTIE;
}

void timerAUmode(){
  TA0CCR0 =0;
  TA0CCR1 =0;
  TA0CCTL1 = OUTMOD_3; /* Toggle p1.6 timer=1*/

  TACTL = TASSEL_2 +MC_1; /*Timer control, system clock (SMCLK)*/
}
