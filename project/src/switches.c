#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_down, switch_changed;

static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES); //switch if up
  P2IES &= (p2val | ~SWITCHES);//switch if down
  return p2val;
}

void
switch_init(){   // setup switch
  P1REN |= SWITCHES; // enable internal resistor
  P1IE |= SWITCHES; //enable interrupts
  P1OUT |= SWITCHES; //pull up
  P1DIR &= ~SWITCHES; // Setup for input
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  if((p2val & SW1) == 0){ //Button 1 pressed
    button_state = 0;
  }
  else if((p2val & SW2) == 0){//Button 2 pressed
    button_state = 1;
  }
  else if ((p2val & SW3) == 0){// Button 3 pressed
    button_state = 2;
  }
  else if((p2val & SW4) == 0){// Button 4 pressed
    button_state = 3;
  }
}
