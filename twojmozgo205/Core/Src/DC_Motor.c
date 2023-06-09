/*
 * DC_Motor.c
 *
 *  Created on: Feb 8, 2023
 *      Author: tomas
 */
#include "DC_Motor.h"

void Motor_INIT(struct Motor* motor, TIM_HandleTypeDef* TIMER, uint32_t PWM_CHANNEL, GPIO_TypeDef* DIR1_PORT, GPIO_TypeDef* DIR2_PORT, uint16_t DIR1_PIN, uint16_t DIR2_PIN){
	motor->DUTY = 0.0f;
	motor->TIMER = TIMER;
	motor->PWM_CHANNEL = PWM_CHANNEL;
	motor->DIR1_PORT = DIR1_PORT;
	motor->DIR2_PORT = DIR2_PORT;
	motor->DIR1_PIN = DIR1_PIN;
	motor->DIR2_PIN = DIR2_PIN;

	Motor_STOP(motor);
}

void Motor_SET_DIR(struct Motor* motor, _Bool dir){
	if(dir == 1){
		HAL_GPIO_WritePin(motor->DIR1_PORT, motor->DIR1_PIN, 1);
		HAL_GPIO_WritePin(motor->DIR2_PORT, motor->DIR2_PIN, 0);
	}
	else{
		HAL_GPIO_WritePin(motor->DIR1_PORT, motor->DIR1_PIN, 0);
		HAL_GPIO_WritePin(motor->DIR2_PORT, motor->DIR2_PIN, 1);
	}
}
void Motor_MOVE(struct Motor* motor, float  duty){
	motor->DUTY = duty;
	if(motor->DUTY > 0){
		Motor_SET_DIR(motor, 1);
		__HAL_TIM_SET_COMPARE(motor->TIMER, motor->PWM_CHANNEL, abs(motor->DUTY));
	}
	if(motor->DUTY < 0){
		Motor_SET_DIR(motor, 0);
		__HAL_TIM_SET_COMPARE(motor->TIMER, motor->PWM_CHANNEL, abs(motor->DUTY));
	}
	if(motor->DUTY == 0){
		Motor_STOP(motor);
		__HAL_TIM_SET_COMPARE(motor->TIMER, motor->PWM_CHANNEL, abs(motor->DUTY));
	}
}

void Motor_STOP(struct Motor* motor){
	HAL_GPIO_WritePin(motor->DIR1_PORT, motor->DIR1_PIN, 0);
	HAL_GPIO_WritePin(motor->DIR2_PORT, motor->DIR2_PIN, 0);
	__HAL_TIM_SET_COMPARE(motor->TIMER, motor->PWM_CHANNEL, 0);
}
