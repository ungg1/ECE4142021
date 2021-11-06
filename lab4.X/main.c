#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib.h>

void main(){
  ANSELA();
  TRISA();
  PORTSetPinsDigitalIn(IOPORT_A,0000);
  PORTSetPinsDigitalOut(IOPORT_A,0001);
  PPSInput(U1RXR);
  PPSOutput(RPA0R);
}
