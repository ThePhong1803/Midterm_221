/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */


#include "fsm.h"

void fsm_simple_buttons_run(){
	//TODO
	switch (status){
		case IDLE:
			//check the counter, if zero mean that we system is stop counting
			//and wait for button event
			if(counter != 0) {
				//go to count down state with timer1 count down 1 second
				status = COUNT_DOWN;
				setTimer1(100);
			}

			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//update the fsm status and increase counter, quick response display
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				status = INC;
				//when leaving or entering auto mode, we need to set timer2 count down 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter, quick response display
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				status = DEC;
				//when leaving or entering auto mode, we need to set timer2 count down 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				//clear counter, and quick response display
				counter = 0;
				quickUpdate7Segment();
			}
			break;

		case COUNT_DOWN:
			//periodic task
			if(isTimer1Expired()){
				//decrease counter, display counter
				counter--;
				quickUpdate7Segment();
				setTimer1(100);
				if(counter == 0) {
					//if counter == 0 back to IDLE state
					status = IDLE;
				}
			}

			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//update the fsm status and increase counter
				status = INC;
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter
				status = DEC;
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				//reset counter
				counter = 0;
				quickUpdate7Segment();
				//return to IDLE state
				status = IDLE;
			}
			break;

//INCREASEMENT
		case INC:
			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//we're in INC state, just need to increase counter and display it
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed3s(BUTTON_INC)){
				status = INC_HOLD;
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				setTimer3(100);
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter
				status = DEC;
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				//when leave any, we need to set timer 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
			}

			//check timer2 to return to auto mode
			if(isTimer2Expired()) {
				status = COUNT_DOWN;
				setTimer1(100);
			}
			break;


//DECREASEMENT
		case DEC:
			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//update the fsm status and increase counter
				status = INC;
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				//when leave any, we need to set timer 10 second to return
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//we're in DEC state, just need to decrease counter
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed3s(BUTTON_DEC)){
				status = DEC_HOLD;
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				setTimer3(400);	//3 second wait for button hold flag  and 1 second delay check if button is release
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
			}

			//check timer2 to return to auto mode
			if(isTimer2Expired()) {
				status = COUNT_DOWN;
				setTimer1(100);
			}
			break;

//long button press event implement status
//button INC hold
		case INC_HOLD:
			//check for button hold flag and increase counter
			if(isButtonPressed3s(BUTTON_INC)){
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				setTimer3(100); // wait for repeat
			}
			//if button is pressed again, return button INC mode
			if(isButtonPressed(BUTTON_INC)){
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				status = INC;
				clearTimer3();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_DEC)){
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				status = DEC;
				clearTimer3();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
			}
			//if more than 1 second and no button hold flags, return to INC state
			if(isTimer3Expired()){
				status = INC;
				//refresh timeout duration for returning auto mode
				setTimer2(TIMEOUT - 100); //wait for timer3 1 second and then wait for timer 2 9 second
			}
			break;

//button DEC hold
		case DEC_HOLD:
			//check for button hold flag and increase counter
			if(isButtonPressed3s(BUTTON_DEC)){
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				setTimer3(100); // wait for repeat
			}
			//if button is pressed again, return button DEC mode
			if(isButtonPressed(BUTTON_DEC)){
				counter--;
				if(counter < 0) counter = 9;
				quickUpdate7Segment();
				status = DEC;
				clearTimer3();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_INC)){
				counter = (counter + 1) % 10;
				quickUpdate7Segment();
				status = INC;
				clearTimer3();
				setTimer2(TIMEOUT);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
			}
			//if more than 1 second and no button hold flags, return to INC state
			if(isTimer3Expired()){
				status = DEC;
				//refresh timeout duration for returning auto mode
				setTimer2(TIMEOUT - 100); //wait for timer3 for 1 second and then wait for timer 2 9 second
			}
			break;
		default:
			break;
	}
}
