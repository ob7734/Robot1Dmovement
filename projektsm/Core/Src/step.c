/*
 * step.c
 *
 *  Created on: Jan 24, 2023
 *      Author: tomas
 */

#include "step.h"

void microDelay (uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim3, 0);
  while (__HAL_TIM_GET_COUNTER(&htim3) < delay);
}

void move_anticlockwise (int steps, uint16_t delay)
{
  for(int i=0; i<steps; i=i+1)
  {
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    microDelay(delay);
  }
}

void move_clockwise (int steps, uint16_t delay) // CV - Clockwise
{
  for(int i=0; i<steps; i=i+1)
  {
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
    in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
    in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
    in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_SET);   // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_SET);   // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_RESET); // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_SET);   // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
    HAL_GPIO_WritePin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin, GPIO_PIN_SET);   // IN1
    HAL_GPIO_WritePin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin, GPIO_PIN_RESET); // IN2
    HAL_GPIO_WritePin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin, GPIO_PIN_RESET); // IN3
    HAL_GPIO_WritePin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin, GPIO_PIN_RESET); // IN4
    in1 = HAL_GPIO_ReadPin(GPIO_PIN_1_GPIO_Port, GPIO_PIN_1_Pin);
	in2 = HAL_GPIO_ReadPin(GPIO_PIN_2_GPIO_Port, GPIO_PIN_2_Pin);
	in3 = HAL_GPIO_ReadPin(GPIO_PIN_3_GPIO_Port, GPIO_PIN_3_Pin);
	in4 = HAL_GPIO_ReadPin(GPIO_PIN_4_GPIO_Port, GPIO_PIN_4_Pin);

    microDelay(delay);
  }
}
