/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */


#include "fsm.h"

void fsm_simple_buttons_run(){
	switch (status){
		case IDLE:
			if(counter != 0) {
				status = COUNT_DOWN;
				setTimer1(100);
			}

			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//update the fsm status and increase counter
				counter++;
				quickUpdate7Segment();
				status = INC;
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter
				counter--;
				quickUpdate7Segment();
				status = DEC;
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				//clear counter
				counter = 0;
				quickUpdate7Segment();
				//return to IDLE status
				status = IDLE;
			}
			break;

		case COUNT_DOWN:
			//periodic task
			if(isTimer1Expired()){
				//decrease counter
				counter--;
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
				counter++;
				quickUpdate7Segment();
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter
				status = DEC;
				counter--;
				quickUpdate7Segment();
				//when leave auto mode, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				//resset counter
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
				//we're in INC state, just need to increase counter
				counter++;
				quickUpdate7Segment();
			}
			if(isButtonPressed(BUTTON_DEC)){
				//update the fsm status and increase counter
				status = DEC;
				counter--;
				quickUpdate7Segment();
				//when leave any, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
				//return to IDLE state
				status = IDLE;
			}

			//check timer2 to return to auto mode
			if(isTimer2Expired()) status = COUNT_DOWN;
			break;


//DECREASEMENT
		case DEC:
			//check for button input
			if(isButtonPressed(BUTTON_INC)){
				//update the fsm status and increase counter
				status = DEC;
				counter++;
				quickUpdate7Segment();
				//when leave any, we need to set timer 10 second to return
				setTimer2(1000);
			}
			if(isButtonPressed(BUTTON_DEC)){
				//we're in DEC state, just need to decrease counter
				counter--;
				quickUpdate7Segment();
			}
			if(isButtonPressed(BUTTON_RESET)) {
				counter = 0;
				quickUpdate7Segment();
				//return to IDLE status
				status = IDLE;
			}

			//check timer2 to return to auto mode
			if(isTimer2Expired()) status = COUNT_DOWN;
			break;

		default:
			break;
	}
}
