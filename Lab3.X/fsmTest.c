#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
#include "timer.h"
#include "fsmTest.h"
#define TESTPERIOD 400

StateType State;
uint16_t testVal =1;
char shiftCountt = 0;
void tickTest(){
    switch(State){
        case I:{
            if(shiftCountt<7)
                State = I;
            else{
            shiftCountt = 0;
            State = S1;
            }
        }
        break;
        case S1:{
            
        }
        case S2:{
            if(shiftCountt<7)
                State = S2;
            else{
            shiftCountt = 0;
            State = S1;
            }
        }
        break;
    }
    switch(State){
        case I:
        {
            portb_out_write(testVal);
            testVal = testVal << 1;
            shiftCountt++;       
        }
        break;
        case S2:
        {
            portb_out_write(testVal);
            testVal = testVal >> 1;
            shiftCountt++;
        }
        break;
    }
    //8 STATE CYLER BEGIN
    /*
    switch(State){
        case I:
              State = S1;
        break;
        case S1:
            portb_out_write(0x01);
            State = S2;
        break;
        case S2:
            portb_out_write(0x02);
            State = S3;
        break;
        case S3:
            portb_out_write(0x04);
            State = S4;
        break;
        case S4:
            portb_out_write(0x08);
            State = S5;
        break;
        case S5:
            portb_out_write(0x10);
            State = S6;
        break;
        case S6:
            portb_out_write(0x20);
            State = S7;
        break;
        case S7:
            portb_out_write(0x40);
            State = S8;
        break;
        case S8:
            portb_out_write(0x80);
            State = S1;
        break;
    }
    */
    //END
}

