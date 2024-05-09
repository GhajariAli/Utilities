#include "LCD1602.h"
#include "main.h"

void DelayMicroseconds(uint32_t us) {
		__HAL_TIM_SET_COUNTER(&htim2,0);
		while (__HAL_TIM_GET_COUNTER(&htim2) < us);
	}

void SendToLCD(char Data,int RS){
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, RS);
	DelayMicroseconds(20);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, ((Data>>3)&0x01) );
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, ((Data>>2)&0x01) );
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, ((Data>>1)&0x01) );
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, ((Data>>0)&0x01) );
	DelayMicroseconds(20);
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,1);
	if (!RS) HAL_Delay(5);
	else DelayMicroseconds(200);
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port,LCD_EN_Pin,0);
	DelayMicroseconds(20);

}

void LCD_Write(char Data, int RS){
	SendToLCD( ((Data>>4)&0x0f) , RS);
	SendToLCD( ((Data>>0)&0x0f) , RS);
}
void LCD_init(){
	  HAL_Delay(100);//need to wait for LCD voltage to rise to 4.5V
	  //3commands to get to 8 bit and back to 4bit:
	  LCD_Write(0x03, 0);
	  HAL_Delay(5);
	  LCD_Write(0x03, 0);
	  HAL_Delay(1);
	  LCD_Write(0x03, 0);
	  HAL_Delay(1);
	  LCD_Write(0x02, 0);
	  HAL_Delay(1);
	  //Normal init
	  LCD_Write(0x28, 0);//sets 4bit 2line 5x8dots
	  HAL_Delay(1);
	  LCD_Write(0x0C, 0);//sets display on cursor off blink off
	  HAL_Delay(1);
	  LCD_Write(0x01, 0);//clears display
	  HAL_Delay(2);
	  LCD_Write(0x06, 0);//increment cursor, no display shift
	  HAL_Delay(1);
}
void LCD_Clear (){
	//SendToLCD(0x01,0);//doesn't work for some reason
	  LCD_GotoXY(0,0);
	  LCD_SendString("                ");
	  LCD_GotoXY(0,1);
	  LCD_SendString("                ");
}
void LCD_GotoXY(int x, int y){
	switch (y){
	case 0:
		x |= 0x80;//first row starts at 0x80
		break;
	case 1:
		x |= 0xC0;//second row starts at 0xC0
		break;
	}
	LCD_Write(x, 0);
}
void LCD_SendString(char* str){
	while (*str) LCD_Write(*str++,1);
}
