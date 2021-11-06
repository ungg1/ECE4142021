#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "debounce.h"
#include "timer.h"
#include "porta_in.h"
unsigned char btn,btndown;

DBStateType DBState;    

void tickDebounce(){
    switch(DBState){
        case noPush:
        {
            btndown=0;
            if(btn){
                DBState = maybePush;
            }else{
                DBState = noPush;
            }
        }
        break;
        case maybePush:
        {
            if(btn){
                btndown = 1;
                DBState = pushed;
            }else{
                DBState = noPush;
            }
        }
        break;
        case pushed:
        {
            if(btn){
                DBState = pushed;
            }else{
                btndown=0;
                DBState = maybeNoPush;
            }
        }
        break;
        case maybeNoPush:
        {
            if(btn){
                DBState = pushed;
            }else{
                DBState = noPush;
            }
        }
        break;
    }
}
