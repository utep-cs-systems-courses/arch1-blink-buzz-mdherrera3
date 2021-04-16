#include <msp430.h>
#include "switches.h"

// Switches on P2
void
__interrupt_vec(PORT2_VECTOR) PORT_2(){
  if(P2IFG & SWITCHES){//button press
    P2IFG &= ~SWITCHES;//clears other interrupts
    switch_interrupt_handler();//handler for switches
  }
}
