/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duraiotn);
void setTimer3(int duration);
void setTimer4(int duration);


void clearTimer0();
void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();

int isTimer0Expired();
int isTimer1Expired();
int isTimer2Expired();
int isTimer3Expired();
int isTimer4Expired();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
