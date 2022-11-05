/*
 * traffic_light.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */


#include "traffic_light.h"

#ifdef ACTIVE
#ifdef HARDWARE
#define LED0_GPIO_Port RED2_GPIO_Port
#define LED0_Pin       RED2_Pin
#define LED1_GPIO_Port YELLOW2_GPIO_Port
#define LED1_Pin       YELLOW2_Pin
#endif

void setRedLed1(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
#else
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
#endif
}

void setYellowLed1(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
#else
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
#endif
}

void setGreenLed1(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
#else
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
#endif
}

void setRedLed2(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
#else
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
#endif
}

void setYellowLed2(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
#else
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
#endif
}

void setGreenLed2(){
#ifndef HARDWARE
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
#else
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
#endif
}


void toggleRed1(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
}
void toggleYellow1(){
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
}
void toggleGreen1(){
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
}
void toggleRed2(){
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
}
void toggleYellow2(){
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}
void toggleGreen2(){
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
}

void clearAllLed(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);

	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}
#endif
