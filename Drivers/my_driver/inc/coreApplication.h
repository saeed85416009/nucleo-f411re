#ifndef __CORE_APPLICATION_H
#define __CORE_APPLICATION_H

#include "main.h"
#include "main_flash.h"
#include "main_lcd16x2.h"
#include "main_timer.h"
#include "math.h"

/*defining the type of application
 * MAIN
 * FLASH_TEST
 * LCD_16x2_TEST
 * TIMER_TEST
 * */
#define LCD_16x2_TEST   		  1
#define TIMER_3_TIMOUT        1000  //time = x ms < ‭(0xFFFF*1000/cpu_clock)
#define LCD_ENABLE_DELAY	1 //1ms

/*prototype*/
void my_Error_Handler(void);

#endif
