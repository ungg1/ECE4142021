/* 
 * File:   main.c
 * Author: gxmun
 *
 * Created on September 14, 2021, 1:21 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "ball.h"
//#include "fsmTest.h"
#include "debounce.h"
#include "porta_in.h"
#include "portb_out.h"
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

int main() {
    uint8_t in, RA4, set;
    uint16_t out;
    uint16_t test2=1;
    BallState = init;
    porta_in_init();
    portb_out_init();
    uint32_t t1a, t2a, t1b, t2b, delay; 
    const uint16_t PERIODA = 400;
    const uint16_t PERIODB = 100;
    timer1_init();
    
    //BallState = init;
    //DBState = noPush;
    
    t1a = t1b = t2a = t2b = timer1_read();
    uint16_t val = 0b10101010;
    portb_out_write(val);
    while (1) {
        t2a = t2b = timer1_read();
        
        //TEST FSM SECTION
        /*
        if(timer1_ms_elapsed(t1a,t2a)> 400){
            tickTest();
            
        //    if(test2==0x80)
        //        test2=1;
        //    test2=test2<<1;
        //    portb_out_write(test2);
            
            t1a=t2a;
        }
        */
        //END TEST FSM
        //REAL FSM SECTION
        ///*
        if (timer1_ms_elapsed(t1a, t2a) > PERIODA) {
            tickBall();
            t1a = t2a;
        }
        if (timer1_ms_elapsed(t1b, t2b) > PERIODB) {
            tickDebounce();
            t1b = t2b;
        }
        //*/
       //END REAL FSM
    }
    return (EXIT_SUCCESS);
}
