/*
 * hc_sr04.h
 *
 *  Created on: Jan 23, 2023
 *      Author: tomas
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_

#include "tim.h"

typedef uint32_t TIM_Channel;

struct us_sensor_str
{
	GPIO_TypeDef* ECHO_PORT;
	uint16_t ECHO_PIN;
	TIM_HandleTypeDef *htim_echo;
	TIM_HandleTypeDef *htim_trig;
	TIM_Channel trig_channel;

	volatile float distance_cm;
};

void hc_sr04_INIT(struct us_sensor_str *us_sensor, GPIO_TypeDef* ECHO_PORT, uint16_t ECHO_PIN, TIM_HandleTypeDef *htim_echo, TIM_HandleTypeDef *htim_trig, TIM_Channel channel);
float hc_sr04_GET_VALUE(uint16_t GPIO_PIN, struct us_sensor_str *us_sensor);


#endif /* INC_HC_SR04_H_ */
