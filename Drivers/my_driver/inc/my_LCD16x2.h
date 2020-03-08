/*
	Library: 				LCD 16X2
	Written by:  		Saeed Pourghasemy
	Date: 				2020/03/06

	funnctions:


*/


//***** Header files *****//
#include "coreApplication.h"
#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include <stdlib.h>

//***** List of COMMANDS *****//
#define LCD_CLEARDISPLAY 		0x01
#define LCD_RETURNHOME 			0x02
#define LCD_ENTRYMODESET 		0x04
#define LCD_DISPLAYCONTROL 	0x08
#define LCD_CURSORSHIFT 		0x10
#define LCD_FUNCTIONSET 		0x20
#define LCD_SETCGRAMADDR 		0x40
#define LCD_SETDDRAMADDR 		0x80


#define  LCD_1_LINES_8			0x30 	//1 lines and 5×7 matrix// 8 BIT MODE
#define  LCD_2_LINES_8			0x38 	//2 lines and 5×7 matrix// 8 BIT MODE
#define  LCD_1_LINES_4			0x20 	//1 lines and 5×7 matrix// 4 BIT MODE
#define  LCD_2_LINES_4			0x28 	//2 lines and 5×7 matrix// 4 BIT MODE
#define  LCD_ENTRY_MODE			0x06

#define  LCD_CLEAR_DISP			0x01 	//Clear display screen
#define  LCD_RETURN_HOME		0x02 	//Return home
#define  LCD_SH_CUR_R			0x04 	//Decrement cursor (shift cursor to left)
#define  LCD_SH_CUR_L			0x06 	//Increment cursor (shift cursor to right)
#define  LCD_SH_DISP_R			0x05 	//Shift display right
#define  LCD_SH_DISP_L			0x07 	//Shift display left
#define  LCD_DISP_OFF_CUR_OFF	0x08 	//Display off, cursor off
#define  LCD_DISP_OFF_CUR_ON	0x0A 	//Display off, cursor on
#define  LCD_DISP_ON_CUR_OFF	0x0C 	//Display on, cursor off
#define  LCD_DISP_ON_CUR_ON		0x0E 	//Display on, cursor blinking
#define  LCD_DISP_ON_CUR_BL		0x0F 	//Display on, cursor blinking
#define  LCD_SH_CUR_P_L			0x10 	//Shift cursor position to left
#define  LCD_SH_CUR_P_R			0x14 	//Shift cursor position to right
#define  LCD_SH_WH_DISP_L		0x18 	//Shift the entire display to the left
#define  LCD_SH_WH_DISP_R		0x1C 	//Shift the entire display to the right
#define  LCD_SH_CUR_BEGIN_1		0x80 	//Force cursor to beginning ( 1st line)
#define  LCD_SH_CUR_BEGIN_2		0xC0 	//Force cursor to beginning ( 2nd line)

//***** List of commands Bitfields *****//
//1) Entry mode Bitfields
#define LCD_ENTRY_SH		 				0x01
#define LCD_ENTRY_ID 						0x02
//2) Entry mode Bitfields
#define LCD_ENTRY_SH		 				0x01
#define LCD_ENTRY_ID 						0x02
//3) Display control
#define LCD_DISPLAY_B						0x01
#define LCD_DISPLAY_C						0x02
#define LCD_DISPLAY_D						0x04
//4) Shift control
#define LCD_SHIFT_RL						0x04
#define LCD_SHIFT_SC						0x08
//5) Function set control
#define LCD_FUNCTION_F					0x04
#define LCD_FUNCTION_N					0x08
#define LCD_FUNCTION_DL					0x10

//***** Functions prototypes *****//
//Private functions
//1) Enable EN pulse
static void LCD1602_Enable(void);
//2) RS control
static void LCD1602_RS(bool state);
//3) Write Parallel interface
static void LCD1602_write(uint8_t byte);
//5) Write command
static void LCD1602_writeCommand(uint8_t command);
//6) Write 8 bits data
static void LCD1602_writeData(uint8_t data);
//7) Write 4 bits command, *FOR 4 BITS MODE ONLY*
static void LCD1602_write4bitCommand(uint8_t nibble);

//Public functions
//1) LCD begin 8 bits function
void LCD1602_Begin8BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_LSBs0to3, uint16_t D0, uint16_t D1, uint16_t D2, uint16_t D3, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7);
//2) LCD begin 4 bits function
void LCD1602_Begin4BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7);
//3) LCD print string
void LCD1602_print(char string[]);
//4) set cursor position
void LCD1602_setCursor(uint8_t row, uint8_t col);
void LCD1602_1stLine(void);
void LCD1602_2ndLine(void);
//5) Enable two lines
void LCD1602_TwoLines(void);
void LCD1602_OneLine(void);
//6) Cursor ON/OFF
void LCD1602_noCursor(void);
void LCD1602_cursor(void);
//7) Clear display
void LCD1602_clear(void);
//8) Blinking cursor
void LCD1602_noBlink(void);
void LCD1602_blink(void);
//9) Display ON/OFF
void LCD1602_noDisplay(void);
void LCD1602_display(void);
//10) Shift Display, right or left
void LCD1602_shiftToRight(uint8_t num);
void LCD1602_shiftToLeft(uint8_t num);

//********** Print numbers to LCD **********//
//1. Integer
void LCD1602_PrintInt(int number);
//2. Float
void LCD1602_PrintFloat(float number, int decimalPoints);
