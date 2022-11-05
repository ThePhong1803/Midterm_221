/*
 * button.h
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

// we aim to work with more than one buttons
#define NO_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we define time out duration for holding 1 key, if reach time out, key will enter repeat state
#define BUTTON_HOLD_TIMEOUT				300	//3 (second)
// we need to jump to the interrupt service routine 100 time
#define AUTO_REPEAT_RATE			 	100	//1 (second)
// the interval for detecting button is double press:
#define DOUBLE_PRESS_TIMEOUT			30	//300 ms

//define button state
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET

//define button flags
#define BUTTON_FLAG_SET					1
#define BUTTON_FLAG_CLEAR 				0

void initButton();
void button_reading(void);
unsigned char isButtonPressed(unsigned char index);
unsigned char isButtonPressed3s(unsigned char index);
unsigned char isButtonDoublePressed(unsigned char index);

#endif /* INC_BUTTON_H_ */
