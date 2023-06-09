/*
 * hc_sr04.c
 *
 *  Created on: Jan 23, 2023
 *      Author: tomas
 */

#define HC_SR04_US_TO_CM_CONVERTER	58
#include "hc_sr04.h"

void hc_sr04_INIT(struct us_sensor_str *us_sensor, GPIO_TypeDef* ECHO_PORT, uint16_t ECHO_PIN, TIM_HandleTypeDef *htim_echo, TIM_HandleTypeDef *htim_trig, TIM_Channel channel){
	us_sensor->ECHO_PORT = ECHO_PORT;
	us_sensor->ECHO_PIN = ECHO_PIN;
	us_sensor->htim_echo = htim_echo;
	us_sensor->htim_trig = htim_trig;
	us_sensor->trig_channel = channel;

	HAL_TIM_PWM_Start(us_sensor->htim_trig, us_sensor->trig_channel);
}
float hc_sr04_GET_VALUE(uint16_t GPIO_PIN, struct us_sensor_str *us_sensor){
	_Bool state = HAL_GPIO_ReadPin(us_sensor->ECHO_PORT, us_sensor->ECHO_PIN);
	float x = 0;
	if(state == 1){
		__HAL_TIM_SET_COUNTER(us_sensor->htim_echo, 0);
		HAL_TIM_Base_Start(us_sensor->htim_echo);
		return -1;
	}
	else{
		HAL_TIM_Base_Stop(us_sensor->htim_echo);
		x = __HAL_TIM_GET_COUNTER(us_sensor->htim_echo);
		return x / HC_SR04_US_TO_CM_CONVERTER;
	}
}

