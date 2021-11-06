#include <stdio.h>
#include <stdlib.h> 
#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
#include "ball.h"
#include "debounce.h"
#include "timer.h"

unsigned char ball,highestScore;
uint16_t p1Score,p2Score;
unsigned char count1,count2 = 0;

BallStateType BallState;
uint16_t t1,t2,flashCount,fVec,rVec,randTime;
char shiftCount = 0;
void tickBall(){
    switch(BallState){
        case init:{
            randTime=timer1_read();
            if(randTime%10>=5){
                BallState=p1Dir;
            }else{
                BallState=p2Dir;
            }
        }
        break;
        case p1Dir:{
            if(shiftCount<7)
                BallState = p1Dir;
            else{
            shiftCount = 0;
            BallState = p1End;
            }
        }
        break;
        case p2Dir:{
            if(shiftCount<7)
                BallState = p2Dir;
            else{
            shiftCount = 0;
            BallState = p2End;
            }
        }
        break;
        case p1End:{
            if(btndown==1)
                BallState = p2Dir;
            else{
                if(p1Score<5)
                    BallState = flash1;
                else
                    BallState = win;
            }
        }
        break;
        case p2End:{
            if(btndown==1)
                BallState = p1Dir;
            else{
                if(p2Score<5)
                    BallState = flash1;
                else
                    BallState = win;
            }
        }
        break;
        break;
        case flash1:{
            BallState = flash2;
        }
        break;
        case flash2:{
            flashCount++;
            if(flashCount<3)
                BallState = flash1;
            else
                BallState = init;
        }
        break;
        case win:{
            BallState = init;
        }
        break;
    }
    switch(BallState){
        case init:{
            ball = 0b00010000;
        }
        break;
        case p1Dir:
        {
            rVec=1;
            portb_out_write(ball);
            ball = ball << 1;
            shiftCount++;       
        }
        break;
        case p2Dir:
        {
            rVec=0;
            portb_out_write(ball);
            ball = ball >> 1;
            shiftCount++;
        }
        break;
        case p1End:{
            if(btndown!=1){
                p1Score++;
                fVec=1;
                flashCount=0;
            }
        }
        break;
        case p2End:{
            if(btndown!=1){
                p2Score++;
                fVec=2;
                flashCount=0;
            }
        }
        break;
        case flash1:{
            if(fVec==1)
                portb_out_write(0b00000001);
            else
                portb_out_write(0b10000000);
        }
        break;
        case flash2:{
            portb_out_write(0b00000000);
        }
        break;
        case win:{
            p1Score=p2Score=0;
            portb_out_write(0b11111111);
        }
        break;
    }
}
/*
void tickBall(){
    
    if(p1Score > p2Score){
        highestScore = p1Score;
    }else{
        highestScore = p2Score;
    }
    
    switch (BallState){
        case init:
        {
            ball = 0x10;
            BallState = p1Dir;
        }
        break;
        case p1Dir:
        {
        if(ball=0x01)
            BallState = p1End;
        portb_out_write(ball);
        ball = ball>>1;
        BallState = p1Dir;
      }
      break;
      case p2Dir:
      {
        if(ball=0x80)
            BallState = p2End;
        portb_out_write(ball);
        ball = ball<<1;
        BallState = p2Dir;
        }
      break;
      case p1End:
      {
          ball = 0x01;
        portb_out_write(ball);
        if(btndown){
            BallState = p2Dir;
        }else{
            p2Score++;
            if(p2Score=5)
                BallState = P2Win;
            //BallState = p2Point;
            BallState = init;
        }
      }
      break;
        case p2End:
        {
            ball = 0x80;
            portb_out_write(ball);
          if(btndown){
              BallState = p1Dir;
          }else{
              p1Score++;
              if(p1Score=5)
                  BallState = P1Win;
              //BallState = p1Point;
              BallState = init;
          }
        }
        break;
        case p1Point:
        {
            if(count1==6){
                count1=0;
                BallState = init;
            }
            if((count1==0)||(count1%2==0))
                portb_out_write(0x01);
            else
                portb_out_write(0);
            count1++;
            BallState = p1Point;
        }
        break;
        case p2Point:
        {
            if(count2==6){
                count2=0;
                BallState = init;
            }
            if((count2==0)||(count2%2==0))
                portb_out_write(0x80);
            else
                portb_out_write(0);
            count2++;
            BallState = p2Point;
        }
        break;
        case P1Win:{
            BallState = init;
            }
        break;
        case P2Win:{
            BallState = init;
            }
        break;
    }
}
*/

        

