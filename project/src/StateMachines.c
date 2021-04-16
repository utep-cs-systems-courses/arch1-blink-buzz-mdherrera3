#include <msp430.h>
#include "StateMachines.h"
#include "led.h"
#include "buzzer.h"

static char sb = 1; //up or down

void turn_red_on(){
  red_on = 1;
  green_on = 0;
  led_update();
}
void turn_green_on(){
  red_on = 0;
  green_on = 1;
  led_update();
}
void buzzer_change(){
  static int x = 500;
  if(sb == 1){
    x += 225;
  }
  else{
    x -= 450;
  }
  short cycles = 2000000 / x;
  buzzer_set_period(cycles);
}
void notes(){
  static char note = 0;
  switch(note){
  case 0:
    buzzer_set_period(2551);//G
    note++;
    break;
  case 1://just hold for 2 "beats"
    buzzer_set_period(2863);//F
    note++;
    break;
  case 3:
    buzzer_set_period(3405);//D
    note = 0;
    break;
  default:
    note++;
  }
}
  
