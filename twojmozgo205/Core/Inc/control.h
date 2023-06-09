/*
 * control.h
 *
 *  Created on: Feb 10, 2023
 *      Author: tomas
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

#include "main.h"
#include "stdlib.h"

struct Controller{
	float MAX_SIGNAL;
	float MIN_SIGNAL;
	float MAX_ERROR;
	float MIN_ERROR;
	float prev_error;
	float prev_distance;
	float current_velocity;
	_Bool start;


};

void control_INIT(struct Controller* controller, float MAX_SIGNAL, float MIN_SIGNAL, float MAX_ERROR, float MIN_ERROR);

float control_GET_SIGNAL(struct Controller*, float y, float y_ref);

float control_GET_VELOCITY(struct Controller*, float distance);

#endif /* INC_CONTROL_H_ */
