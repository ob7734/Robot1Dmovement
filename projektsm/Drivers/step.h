/*
 * step.h
 *
 *  Created on: Jan 24, 2023
 *      Author: tomas
 */

#ifndef INC_STEP_H_
#define INC_STEP_H_

#include "tim.h"

#define IN1_PIN GPIO_PIN_1
#define IN1_PORT GPIOA
#define IN2_PIN GPIO_PIN_2
#define IN2_PORT GPIOA
#define IN3_PIN GPIO_PIN_3
#define IN3_PORT GPIOA
#define IN4_PIN GPIO_PIN_4
#define IN4_PORT GPIOA


_Bool in1, in2, in3, in4;
void microDelay (uint16_t delay);
void move_anticlockwise (int steps, uint16_t delay);
void move_clockwise (int steps, uint16_t delay);

#endif /* INC_STEP_H_ */
