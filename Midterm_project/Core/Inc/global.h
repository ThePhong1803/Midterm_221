/*
 * global.h
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "led7Segment.h"

//global define
#define IDLE 		1
#define COUNT_DOWN 	2
#define INC			3
#define DEC			4

//button input macro
#define BUTTON_RESET 	0
#define BUTTON_INC	 	1
#define BUTTON_DEC		2

//time out duration
#define TIMEOUT			1000 // 10 second count down to back to auto mode

//global declaration
extern int status;
extern int counter;

#endif /* INC_GLOBAL_H_ */
