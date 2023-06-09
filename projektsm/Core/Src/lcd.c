/*
 * lcd.c
 *
 *  Created on: Feb 20, 2023
 *      Author: tomas
 */


#include "lcd.h"

void LCD_Init(void){
	//4 bit init
	// 4 bit initialisation
	    HAL_Delay(50);  // wait for >40ms
	    LCD_Send_cmd (0x30);
	    HAL_Delay(5);  // wait for >4.1ms
	    LCD_Send_cmd (0x30);
	    HAL_Delay(1);  // wait for >100us
	    LCD_Send_cmd (0x30);
	    HAL_Delay(10);
	    LCD_Send_cmd (0x20);  // 4bit mode
	    HAL_Delay(10);

	  // dislay initialisation
	    LCD_Send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	    HAL_Delay(1);
	    LCD_Send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	    HAL_Delay(1);
	    LCD_Send_cmd (0x01);  // clear display
	    HAL_Delay(1);
	    HAL_Delay(1);
	    LCD_Send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	    HAL_Delay(1);
	    LCD_Send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

}

void send_to_lcd (char data, int rs){
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, rs); //1 for data, 0 for command

	//Writing data to each pin
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, ((data>>3)&0x01));
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, ((data>>2)&0x01));
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, ((data>>1)&0x01));
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, ((data>>0)&0x01));

	//Toggle enable pin to send the data
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, 0);
}
void LCD_Send_cmd (char cmd){
	char data_to_send;

	data_to_send = ((cmd>>4)&0x0f);
	send_to_lcd(data_to_send, 0);

	data_to_send = ((cmd)&0x0f);
	send_to_lcd(data_to_send, 0);

}

void LCD_Send_data (char data){
	char data_to_send;
	data_to_send = ((data>>4)&0x0f);
	send_to_lcd(data_to_send, 1);

	data_to_send = ((data)&0x0f);
	send_to_lcd(data_to_send, 1);
}

void LCD_Put_Cursor(int row, int column){
	switch(row){
		case 0:
			column |= 0x80;
			break;
		case 1:
			column |= 0xC0;
			break;
	}

	LCD_Send_cmd(column);


}

void LCD_Send_string (char* str){
	while(*str){
		LCD_Send_data(*str++);
	}
}

void LCD_Clear (void){
	LCD_Send_cmd(0x01);
	HAL_Delay(2);
}
