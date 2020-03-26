#include <msp430.h>
#include "Timer.c"
#include "Blinkled.c"

int main(void){
  configureClocks();
  led();
  interrupts(); /*timer interrupt*/

  or_sr(0x18); /*CPU off, GIE on, power save*/
}
