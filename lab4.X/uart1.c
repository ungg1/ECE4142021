#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF
/*
 * File:   uart1.c
 * Author: gxmun
 *
 * Created on September 21, 2021, 1:08 PM
 */
void uart1_init(uint32_t baudrate){
    /*The module shall include a function to initialize the UART to communicate using
    eight data bits and no parity bits at a specific baud rate:*/
    OpenUART1(UART_EN | UART_BRGH_FOUR |  UART_NO_PAR_8BIT, UART_TX_PIN_NORMAL | UART_RX_ENABLE | UART_TX_ENABLE, baudrate);
}   
uint8_t uart1_txrdy(){
  /*The module shall include a function to write a character to the UART: */
  if(!BusyUART1())
    return 1;
  else
    return 0;
}

void uart1_txwrite(char c){
  /*The module shall include a function to write a null-terminated string to the
  UART:*/
  putsUART1(c);
}

void uart1_txwrite_str(char *c){
    /*This function must not overflow the transmitter ? if the transmitter is not ready, it
should suspend execution and wait until ready before sending more characters
(this is known as blocking I/O)*/
  int *i = c;
  while(*i !="\0"){
    uart1_txwrite(i);
    i++;
  }
}

uint8_t uart1_rxrdy(){
    /*The module shall include a function that returns true when the UART receiver has
a character ready for reading: */
  while(1){
    while(DataReadyUART1()){
      return true;
    }
  }
}

uint8_t uart1_rxread(){
    /*The module shall include a function that reads a received character from the
UART. */
  getcUART1();
}
