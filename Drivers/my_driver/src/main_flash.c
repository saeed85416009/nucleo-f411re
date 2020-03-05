#include "main.h"
extern My_Flash_TypeDef hflash;
static uint32_t my_flash_TypeDefConf(uint8_t sector, uint32_t sect_offset, DataTypeDef dataType);

uint32_t main_flash(void){
	uint16_t wrBuf[5]= {0x3333,0x1111,0x0000,0x4444,0x5555};
	uint16_t rdBuf[100];
//	FLASH_SetSectorAddrs(7, 0x08060000);
	//FLASH_WriteN(10, wrBuf, 5, DATA_TYPE_16);

	my_flash_TypeDefConf(FLASH_SECT7,10,DATA_TYPE_8);
	FLASH_WriteN(wrBuf, sizeof(wrBuf));
	FLASH_ReadN(rdBuf, sizeof(wrBuf));
//	while (1);
	return 0;
}

static uint32_t my_flash_TypeDefConf(uint8_t sector, uint32_t sect_offset, DataTypeDef dataType){

	hflash.sector=sector;
	hflash.sect_offset=sect_offset;
	hflash.dataType=dataType;
	Flash_SectConf();
	return 0;
}



/*
typedef struct  {
	uint8_t sector;
	uint32_t baseAddr;
	DataTypeDef dataType;
	void *wrBuf;
	void *rdBuf;
}My_Flash_TypeDef;*/
