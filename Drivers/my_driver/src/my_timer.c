#include "my_timer.h"
#include "coreApplication.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;

// timeout is in ms
void my_timer_timeConf(uint32_t timeout){

	uint64_t a,b,e;

	uint32_t clk;
	htim3.Instance = TIM3;
	SystemCoreClockUpdate();
	clk=HAL_RCC_GetSysClockFreq();

	a=(clk/1000);
	b= timeout*a;

	e=sqrt(b);

	htim3.Init.Prescaler = (uint32_t) e;
//	tim_period = (timeout*(clk/1000))/(prescaler+1);


	htim3.Init.Period = (uint32_t) e;
	if( HAL_TIM_Base_Init(&htim3) != HAL_OK )
	{
		my_Error_Handler();
	}



}
