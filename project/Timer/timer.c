/*Timer "Clock"*/
#include <msp430.h>

void configureClocks(){
  WDTCTL = WDTPW + WDTHOLD; //Disable Watchdog Timer
  BCSTL1 = CALBC1_10MHZ;//my modification is 10 mhz
  DC0CTL = CALDC0_10MHZ;

  BCSCTL2 &= ~(SELS); //source = DCO
  BCSCTL2 |= DIVS_2;//modify DCO/4
}

void enableWDTInterrupts():{
  WDTCTL = WDTPW | //device reset
  WDTTMSEL |
  WDTCNTCL |
    1;
  IE1 |= WDTIE;
}
