/*
 * lcd.h
 *
 *  Created on: Feb 20, 2023
 *      Author: tomas
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"



void LCD_Init(void);

void LCD_Put_Cursor(int row, int column);

void LCD_Send_cmd (char cmd);

void LCD_Send_data (char data);

void LCD_Send_string (char* str);

void LCD_Clear (void);
#endif /* INC_LCD_H_ */
