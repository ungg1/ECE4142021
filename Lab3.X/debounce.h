/* 
 * File:   debounce.h
 * Author: gxmun
 *
 * Created on September 28, 2021, 1:51 PM
 */

#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DEBOUNCE_H */

extern unsigned char btn,btndown;
typedef enum DBStates{
    noPush,
    maybePush,
    pushed,
    maybeNoPush
}DBStateType;

extern DBStateType DBState;    

extern void tickDebounce();