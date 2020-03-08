#include "main_timer.h"

TIM_HandleTypeDef htim3;

uint32_t main_timer(void){
	//time = x ms < ‭(0xFFFF*1000/cpu_clock)‬
	  my_timer_timeConf(TIMER_3_TIMOUT);
	  HAL_TIM_Base_Start_IT(&htim3);


	return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);

}
