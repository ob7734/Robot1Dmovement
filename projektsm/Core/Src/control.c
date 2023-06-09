/*
 * control.c
 *
 *  Created on: Feb 10, 2023
 *      Author: tomas
 */

#include "control.h"

void control_INIT(struct Controller* controller, float MAX_SIGNAL, float MIN_SIGNAL, float MAX_ERROR, float MIN_ERROR){
	controller->MAX_SIGNAL = MAX_SIGNAL;
	controller->MIN_SIGNAL = MIN_SIGNAL;
	controller->MAX_ERROR = MAX_ERROR;
	controller->MIN_ERROR = MIN_ERROR;
	controller->prev_error = 0;
	controller->prev_distance = 0;
	controller->current_velocity = 0;
	controller->start = 0;


}

float control_GET_SIGNAL(struct Controller* controller, float y, float y_ref){
	float error = y_ref - y;
	float duty = error/5.0 * 100;
	if(abs(error) <= controller->MIN_ERROR){
		controller->start = 0;
		return 0;
	}
	else if(abs(error) > controller->MAX_ERROR && error>0) {
		controller->start = 1;
		return -100.0f;
	}
	else if(abs(error) > controller->MAX_ERROR && error<0){
		controller->start = 1;
		return 100.0f;
	}

	else if(controller->start == 1){
		if(abs(duty) <= 94 && error<0) return 94.0f;
		else if(abs(duty) <= 94 && error>0) return -94.0f;
	}
	else{
		if(error>0){
			controller->start = 1;
			return	 -100.0f;
		}
		else{
			controller->start = 1;
			return 100.0f;
		}
	}
	return duty;
}


	float control_GET_VELOCITY(struct Controller* controller, float distance){
		if(controller->prev_distance == 0) controller->prev_distance = distance;
		float velocity  = (distance-controller->prev_distance)/0.05;
		controller->prev_distance = distance;
		controller->current_velocity = velocity;
		return velocity;
	}



