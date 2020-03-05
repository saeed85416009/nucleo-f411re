#include "main.h"


uint32_t main_flash(void){
	uint16_t wrBuf[5]= {0x1111,0x2222,0x3333,0x4444,0x5555};
	FLASH_SetSectorAddrs(7, 0x08060000);
	FLASH_WriteN(10, wrBuf, 5, DATA_TYPE_16);
//	while (1);
	return 0;
}
