#include <msp430.h>

unsigned char red=0, green=0;
unsigned char led=0;

static char redVal[]={0,LED_RED}, greenVal[]={0,LED_GREEN};

void led():{
  P1DIR |= LEDS; //attaching leds
  led=1;
  update();
}

void update():{
  if(led){
    char flags=redVal[red]|greenVal[green];

    P1OUT &= (0xff^LEDS)|ledFlags; //clearing off leds
    P1OUT|=flags;//on leds
    led=0;
  }
}
