#include <msp430.h>
#include "Blinkled.c"

char toggle_red()/* always toggles */
{
  static char state = 0;

  switch (state) {
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1; /*changes an led */
}
