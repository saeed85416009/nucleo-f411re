//***** Header files *****//
#include "main.h"
#include "my_LCD16x2.h"

//***** Variables *****//
static const uint32_t writeTimeConstant = 1000;
static uint8_t mode_8_4_I2C = 1;
static GPIO_TypeDef* PORT_RS_and_E;							  // RS and E PORT
static uint16_t PIN_RS, PIN_E;									  // RS and E pins
static GPIO_TypeDef* PORT_LSB;										// LSBs D0, D1, D2 and D3 PORT
static uint16_t D0_PIN, D1_PIN, D2_PIN, D3_PIN;	// LSBs D0, D1, D2 and D3 pins
static GPIO_TypeDef* PORT_MSB;										// MSBs D5, D6, D7 and D8 PORT
static uint16_t D4_PIN, D5_PIN, D6_PIN, D7_PIN;	// MSBs D5, D6, D7 and D8 pins

static uint8_t DisplayControl = 0x0F;
static uint8_t FunctionSet = 0x38;
static Line = 2;
TIM_HandleTypeDef htim3;

//***** Functions definitions *****//
//Private functions
//1) Enable EN pulse
static void LCD1602_Enable(void)
{
	HAL_GPIO_WritePin(PORT_RS_and_E, PIN_E, GPIO_PIN_SET);
	HAL_Delay(LCD_ENABLE_DELAY);
	HAL_GPIO_WritePin(PORT_RS_and_E, PIN_E, GPIO_PIN_RESET);
	HAL_Delay(LCD_ENABLE_DELAY);
	//LCD1602_TIM_MicorSecDelay(600);
}
//2) RS control
static void LCD1602_RS(bool state)
{
	if(state) HAL_GPIO_WritePin(PORT_RS_and_E, PIN_RS, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(PORT_RS_and_E, PIN_RS, GPIO_PIN_RESET);
}

//3) Write Parallel interface
static void LCD1602_write(uint8_t byte)
{
	uint8_t LSB_nibble = byte&0xF, MSB_nibble = (byte>>4)&0xF;

	if(mode_8_4_I2C == 1)		//8bits mode
	{
		//write data to output pins
		//LSB data
		HAL_GPIO_WritePin(PORT_LSB, D0_PIN, (GPIO_PinState)(LSB_nibble&0x1));
		HAL_GPIO_WritePin(PORT_LSB, D1_PIN, (GPIO_PinState)(LSB_nibble&0x2));
		HAL_GPIO_WritePin(PORT_LSB, D2_PIN, (GPIO_PinState)(LSB_nibble&0x4));
		HAL_GPIO_WritePin(PORT_LSB, D3_PIN, (GPIO_PinState)(LSB_nibble&0x8));
		//MSB data
		HAL_GPIO_WritePin(PORT_MSB, D4_PIN, (GPIO_PinState)(MSB_nibble&0x1));
		HAL_GPIO_WritePin(PORT_MSB, D5_PIN, (GPIO_PinState)(MSB_nibble&0x2));
		HAL_GPIO_WritePin(PORT_MSB, D6_PIN, (GPIO_PinState)(MSB_nibble&0x4));
		HAL_GPIO_WritePin(PORT_MSB, D7_PIN, (GPIO_PinState)(MSB_nibble&0x8));
		//Write the Enable pulse
		LCD1602_Enable();
	}
	else if(mode_8_4_I2C == 2)	//4 bits mode
	{
		//write data to output pins
		//MSB data
		HAL_GPIO_WritePin(PORT_MSB, D4_PIN, (GPIO_PinState)(MSB_nibble&0x1));
		HAL_GPIO_WritePin(PORT_MSB, D5_PIN, (GPIO_PinState)(MSB_nibble&0x2));
		HAL_GPIO_WritePin(PORT_MSB, D6_PIN, (GPIO_PinState)(MSB_nibble&0x4));
		HAL_GPIO_WritePin(PORT_MSB, D7_PIN, (GPIO_PinState)(MSB_nibble&0x8));
		//Write the Enable pulse
		LCD1602_Enable();

		//LSB data
		HAL_GPIO_WritePin(PORT_MSB, D4_PIN, (GPIO_PinState)(LSB_nibble&0x1));
		HAL_GPIO_WritePin(PORT_MSB, D5_PIN, (GPIO_PinState)(LSB_nibble&0x2));
		HAL_GPIO_WritePin(PORT_MSB, D6_PIN, (GPIO_PinState)(LSB_nibble&0x4));
		HAL_GPIO_WritePin(PORT_MSB, D7_PIN, (GPIO_PinState)(LSB_nibble&0x8));
		//Write the Enable pulse
		LCD1602_Enable();
	}
}

//5) Write command
static void LCD1602_writeCommand(uint8_t command)
{
	//Set RS to 0
	LCD1602_RS(false);
	//Call low level write parallel function
	LCD1602_write(command);
}
//6) Write 8 bits data
static void LCD1602_writeData(uint8_t data)
{
	//Set RS to 1
	LCD1602_RS(true);
	//Call low level write parallel function
	LCD1602_write(data);
}
//7) Write 4 bits command, *FOR 4 BITS MODE ONLY*
static void LCD1602_write4bitCommand(uint8_t nibble)
{
	uint8_t LSB_nibble = nibble&0xF;
	//Set RS to 0
	LCD1602_RS(false);
	//LSB data
	HAL_GPIO_WritePin(PORT_MSB, D4_PIN, (GPIO_PinState)(LSB_nibble&0x1));
	HAL_GPIO_WritePin(PORT_MSB, D5_PIN, (GPIO_PinState)(LSB_nibble&0x2));
	HAL_GPIO_WritePin(PORT_MSB, D6_PIN, (GPIO_PinState)(LSB_nibble&0x4));
	HAL_GPIO_WritePin(PORT_MSB, D7_PIN, (GPIO_PinState)(LSB_nibble&0x8));
	//Write the Enable pulse
	LCD1602_Enable();
}

//Public functions
//1) LCD begin 8 bits function
void LCD1602_Begin8BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_LSBs0to3, uint16_t D0, uint16_t D1, uint16_t D2, uint16_t D3, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7)
{
	//Set GPIO Ports and Pins data
	PORT_RS_and_E = PORT_RS_E;
	PIN_RS = RS;
	PIN_E = E;
	PORT_LSB = PORT_LSBs0to3;
	D0_PIN = D0;
	D1_PIN = D1;
	D2_PIN = D2;
	D3_PIN = D3;
	PORT_MSB = PORT_MSBs4to7;
	D4_PIN = D4;
	D5_PIN = D5;
	D6_PIN = D6;
	D7_PIN = D7;
	//Initialise microsecond timer
	 my_timer_timeConf(TIMER_3_TIMOUT);
		//Set the mode to 8 bits
		mode_8_4_I2C = 1;
		//Function set variable to 8 bits mode
		FunctionSet = 0x38;

		//Initialise LCD
		//1. Wait at least 15ms
		HAL_Delay(20);
		/*
		 * 2
		 * Before you can send commands or data to the LCD module, the Module must be initialized.
          For eight bit mode, this is done using the following series of operations:*/

		LCD1602_writeCommand(0x30);
		HAL_Delay(5);
		LCD1602_writeCommand(0x30);
		HAL_Delay(1);
		LCD1602_writeCommand(0x30);
		HAL_Delay(1);


		//3. Function set; Enable 2 lines, Data length to 8 bits
		LCD1602_writeCommand(LCD_2_LINES_8);
		LCD1602_writeCommand(LCD_DISP_OFF_CUR_OFF);
		LCD1602_writeCommand(LCD_CLEAR_DISP);
		//4. Display control (Display ON, Cursor ON)
		LCD1602_writeCommand(LCD_RETURN_HOME);
		LCD1602_writeCommand(LCD_DISP_ON_CUR_ON);
		//5. Clear LCD and return home
			LCD1602_writeCommand(LCD_CLEARDISPLAY);
			HAL_Delay(2);
		HAL_Delay(2);
}
//2) LCD begin 4 bits function
void LCD1602_Begin4BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7)
{
	//Set GPIO Ports and Pins data
	PORT_RS_and_E = PORT_RS_E;
	PIN_RS = RS;
	PIN_E = E;
	PORT_MSB = PORT_MSBs4to7;
	D4_PIN = D4;
	D5_PIN = D5;
	D6_PIN = D6;
	D7_PIN = D7;
	//Initialise microsecond timer
	 my_timer_timeConf(TIMER_3_TIMOUT);
	//Set the mode to 4 bits
	mode_8_4_I2C = 2;
	//Function set variable to 4 bits mode
	FunctionSet = 0x28;

	//Initialise LCD
	//1. Wait at least 15ms
	HAL_Delay(20);
	/*
	 * 2
	 *  1. Wait more than 15 msecs after power is applied.
		2. Write 0x03 to LCD and wait 5 msecs for the instruction to complete
		3. Write 0x03 to LCD and wait 160 usecs for instruction to complete
		4. Write 0x03 AGAIN to LCD and wait 160 usecs (or poll the Busy Flag)
		5. Set the Operating Characteristics of the LCD
		6. Write 0x02 to the LCD to Enable Four Bit Mode*/
	LCD1602_write4bitCommand(0x3);
	HAL_Delay(5);
	LCD1602_write4bitCommand(0x3);
	HAL_Delay(1);
	LCD1602_write4bitCommand(0x3);
	HAL_Delay(1);
	LCD1602_write4bitCommand(0x2);  //4 bit mode
	HAL_Delay(1);


	//3. Display control (Display ON, Cursor ON, blink cursor)
	LCD1602_writeCommand(LCD_DISPLAYCONTROL | LCD_DISPLAY_B | LCD_DISPLAY_C | LCD_DISPLAY_D);
	//4. Clear LCD and return home
	LCD1602_writeCommand(LCD_CLEARDISPLAY);
	HAL_Delay(3);
	//4. Function set; Enable 2 lines, Data length to 8 bits
	LCD1602_writeCommand(LCD_FUNCTIONSET | LCD_FUNCTION_N);
	HAL_Delay(3);
}
//3) LCD print string
void LCD1602_print(char string[])
{
	uint32_t size=16;
	uint32_t line = 1, count_byte=0, c_count_byte=0;
	size = strlen(string);


	while(size>16){

		if( Line== 1){
					LCD1602_setCursor(2,1);
					Line=2;
				}else{
					HAL_Delay(100);
					LCD1602_clear();
					LCD1602_setCursor(1,1);
					Line=1;
				}

		for(uint8_t i=count_byte;  i< count_byte+16 ; i++)
		{
			LCD1602_writeData((uint8_t)string[i]);
			c_count_byte=c_count_byte+1;
		}
		count_byte=c_count_byte;
		size = size-16;


	}
		if( Line== 1){
					LCD1602_setCursor(2,1);
					Line=2;
				}else{

					HAL_Delay(100);
					LCD1602_clear();
					HAL_Delay(100);
					LCD1602_setCursor(1,1);
					Line=1;
				}
		for(uint8_t i=count_byte;  i< count_byte+16 ; i++)
				{
					LCD1602_writeData((uint8_t)string[i]);
					c_count_byte=c_count_byte+1;
				}

}
//4) set cursor position
void LCD1602_setCursor(uint8_t row, uint8_t col)
{
	uint8_t maskData;
	maskData = (col-1)&0x0F;
	if(row==1)
	{
		maskData |= (0x80);
		LCD1602_writeCommand(maskData);
	}
	else
	{
		maskData |= (0xc0);
		LCD1602_writeCommand(maskData);
	}
}
void LCD1602_1stLine(void)
{
	LCD1602_setCursor(1,1);
}
void LCD1602_2ndLine(void)
{
	LCD1602_setCursor(2,1);
}
//5) Enable two lines
void LCD1602_TwoLines(void)
{
	FunctionSet |= (0x08);
	LCD1602_writeCommand(FunctionSet);
}
void LCD1602_OneLine(void)
{
	FunctionSet &= ~(0x08);
	LCD1602_writeCommand(FunctionSet);
}
//6) Cursor ON/OFF
void LCD1602_noCursor(void)
{
	DisplayControl &= ~(0x02);
	LCD1602_writeCommand(DisplayControl);
}
void LCD1602_cursor(void)
{
	DisplayControl |= (0x02);
	LCD1602_writeCommand(DisplayControl);
}
//7) Clear display
void LCD1602_clear(void)
{
	LCD1602_writeCommand(LCD_CLEARDISPLAY);
	HAL_Delay(3);
}
//8) Blinking cursor
void LCD1602_noBlink(void)
{
	DisplayControl &= ~(0x01);
	LCD1602_writeCommand(DisplayControl);
}
void LCD1602_blink(void)
{
	DisplayControl |= 0x01;
	LCD1602_writeCommand(DisplayControl);
}
//9) Display ON/OFF
void LCD1602_noDisplay(void)
{
	DisplayControl &= ~(0x04);
	LCD1602_writeCommand(DisplayControl);
}
void LCD1602_display(void)
{
	DisplayControl |= (0x04);
	LCD1602_writeCommand(DisplayControl);
}
//10) Shift Display, right or left
void LCD1602_shiftToRight(uint8_t num)
{
	for(uint8_t i=0; i<num;i++)
	{
		LCD1602_writeCommand(0x1c);
	}
}
void LCD1602_shiftToLeft(uint8_t num)
{
	for(uint8_t i=0; i<num;i++)
	{
		LCD1602_writeCommand(0x18);
	}
}

//********** Print numbers to LCD **********//
//1. Integer
void LCD1602_PrintInt(int number)
{
	char numStr[16];
	sprintf(numStr,"%d", number);
	LCD1602_print(numStr);
}
//2. Float
void LCD1602_PrintFloat(float number, int decimalPoints)
{
	char numStr[16];
	sprintf(numStr,"%.*f",decimalPoints, number);
	LCD1602_print(numStr);
}
