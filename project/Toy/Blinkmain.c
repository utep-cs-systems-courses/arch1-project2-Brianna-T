#include <msp430.h>
#include "libTimer.h"
#include "Blinkled.h"

int main(void){
  configureClocks();
  led_init();
  enableWDTInterrupts(); /*timer interrupt*/

  or_sr(0x18); /*CPU off, GIE on, power save*/
}
