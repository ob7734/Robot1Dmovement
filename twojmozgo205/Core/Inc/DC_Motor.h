/*
 * DC_Motor.h
 *
 *  Created on: Feb 8, 2023
 *      Author: tomas
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

#include "main.h"
#include "stdlib.h"

struct Motor{
	TIM_HandleTypeDef* TIMER;
	uint32_t PWM_CHANNEL;
	GPIO_TypeDef* DIR1_PORT;
	GPIO_TypeDef* DIR2_PORT;
	uint16_t DIR1_PIN;
	uint16_t DIR2_PIN;
	float DUTY;
};
void Motor_INIT(struct Motor* motor, TIM_HandleTypeDef* htim, uint32_t PWM_CHANNEL, GPIO_TypeDef* DIR1_PORT, GPIO_TypeDef* DIR2_PORT, uint16_t DIR1_PIN, uint16_t DIR2_PIN);
void Motor_SET_DIR(struct Motor* motor, _Bool dir);
void Motor_MOVE(struct Motor* motor, float  duty);
void Motor_STOP(struct Motor* motor);

#endif /* INC_DC_MOTOR_H_ */
