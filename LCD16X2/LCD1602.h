#ifndef INC_LCD1602_H_
#define INC_LCD1602_H_
#endif /* INC_LCD1602_H_ */

#include "stm32f1xx_hal.h"

/*
	Defined these in Cube, otherwise define here:
	#define LCD_RS_Pin 			GPIO_PIN_5
	#define LCD_RS_GPIO_Port 	GPIOA
	#define LCD_EN_Pin 			GPIO_PIN_6
	#define LCD_EN_GPIO_Port 	GPIOA
	#define LCD_D4_Pin 			GPIO_PIN_1
	#define LCD_D4_GPIO_Port 	GPIOA
	#define LCD_D5_Pin 			GPIO_PIN_2
	#define LCD_D5_GPIO_Port 	GPIOA
	#define LCD_D6_Pin 			GPIO_PIN_3
	#define LCD_D6_GPIO_Port	GPIOA
	#define LCD_D7_Pin 			GPIO_PIN_4
*/
extern TIM_HandleTypeDef htim2; //use a timer at 1MHZ

void DelayMicroseconds(uint32_t Delay);
void LCD_Clear (void);
void LCD_Write(char Data, int RS);
void LCD_init();
void LCD_Clear();
void LCD_GotoXY(int x, int y);
void LCD_SendString(char* str);
