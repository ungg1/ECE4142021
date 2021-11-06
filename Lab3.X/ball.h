/* 
 * File:   ball.h
 * Author: gxmun
 *
 * Created on September 28, 2021, 1:30 PM
 */

#ifndef BALL_H
#define	BALL_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* BALL_H */

extern unsigned char ball,highestScore;
extern uint16_t p1Score,p2Score;

typedef enum BallStates{
    init,
    p1Dir,
    p2Dir,
    p1End,
    p2End,
    flash1,
    flash2,
    win
} BallStateType;

extern BallStateType  BallState;

extern void tickBall();

