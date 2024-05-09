/*
 * KeyPad.c
 *
 *  Created on: May 8, 2024
 *      Author: ALIG
 */
#include "KeyPad.h"
const char KeypadPattern[16]={	'1','2','3','A',
								'4','5','6','B',
								'7','8','9','C',
								'*','0','#','D'};
char GetKey(void){
	int KeyCode;

	HAL_GPIO_WritePin(Col1_GPIO_Port, Col1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Col2_GPIO_Port, Col2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col3_GPIO_Port, Col3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col4_GPIO_Port, Col4_Pin, GPIO_PIN_RESET);
	if		(HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) )KeyCode=1;
	else if	(HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) )KeyCode=2;
	else if	(HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) )KeyCode=3;
	else if	(HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) )KeyCode=4;

	HAL_GPIO_WritePin(Col1_GPIO_Port, Col1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col2_GPIO_Port, Col2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Col3_GPIO_Port, Col3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col4_GPIO_Port, Col4_Pin, GPIO_PIN_RESET);
	if		(HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) )KeyCode=5;
	else if	(HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) )KeyCode=6;
	else if	(HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) )KeyCode=7;
	else if	(HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) )KeyCode=8;

	HAL_GPIO_WritePin(Col1_GPIO_Port, Col1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col2_GPIO_Port, Col2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col3_GPIO_Port, Col3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Col4_GPIO_Port, Col4_Pin, GPIO_PIN_RESET);
	if		(HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) )KeyCode=9;
	else if	(HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) )KeyCode=10;
	else if	(HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) )KeyCode=11;
	else if	(HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) )KeyCode=12;

	HAL_GPIO_WritePin(Col1_GPIO_Port, Col1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col2_GPIO_Port, Col2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col3_GPIO_Port, Col3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Col4_GPIO_Port, Col4_Pin, GPIO_PIN_SET);
	if		(HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) )KeyCode=13;
	else if	(HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) )KeyCode=14;
	else if	(HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) )KeyCode=15;
	else if	(HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) )KeyCode=16;

	if ( KeyCode > 16 || KeyCode <0 ) return -1;
	return KeypadPattern[KeyCode-1];
}
