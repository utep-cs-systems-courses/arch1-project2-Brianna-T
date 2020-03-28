#include <msp430.h>

void buzzer()
{
    /* P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero */
    timerAUpmode(); /* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6; /*output to speaker(P2.6) */
}

void start(short cycles) /* buzzer clock = 2MHz(period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;/* one half cycle */
}


    
    
  

