
#include <msp430.h>
#include "StateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char button_state = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char count = 0;

  if(++count == 62 && button_state == 1){//1/4th of a sec
    notes();
    count = 0;
  }
  else if((count % 25) == 0 && button_state == 1){
    buzzer_change();
  }
  else if(button_state == 2){
    buzzer_set_period(0);
    turn_red_on();
  }
  else if(button_state == 3){
    buzzer_set_period(0);
    turn_green_on();
  }
}
