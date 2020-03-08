#include "main_LCD16x2.h"

uint32_t main_lcd16x2(void){

	HAL_Delay(1000);
	LCD1602_Begin8BIT(LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_Pin, LCD_D0_GPIO_Port, LCD_D0_Pin, LCD_D1_Pin, LCD_D2_Pin, LCD_D3_Pin, LCD_D4_GPIO_Port, LCD_D4_Pin, LCD_D5_Pin, LCD_D6_Pin, LCD_D7_Pin);
	HAL_Delay(1000);
	//LCD1602_print("hello world I am SAEED PG FROM IRAN");
	LCD1602_PrintFloat(4.2, 3);

	return 0;
}
