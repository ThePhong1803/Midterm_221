/*
 * global.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */


#include "global.h"

//global variable implementation
//initialize fsm status
int status = IDLE;
//initialize counter with initial valued
int counter = 9;
//global function implementation

void toggleLedRed(){
	if(isTimer4Expired()){
		setTimer4(100); //1 second toggle;
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
}
