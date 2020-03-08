

/*
Library:     STM32f411 - nucleo board
programmer:	 Saeed Pourghasemy
Last modified:	2019/03/04

Description:
functions:
-
- Set sectos address
- Flash Sector Erase
- Flash Write
- Flash Read

*/

#include "my_flash.h"

//Private variables
// sector start address
My_Flash_TypeDef hflash;

/* Erase Sector */
static void FLASH_EraseSector(void)
{
	HAL_FLASH_Unlock();
	//Erase the required Flash sector
	FLASH_Erase_Sector(hflash.sector, FLASH_VOLTAGE_RANGE_3);
	HAL_FLASH_Lock();
}

void Flash_SectConf(void){
	switch (hflash.sector){
	case FLASH_SECT0:
		hflash.baseAddr=FLASH_ADDR_SECT0;
		break;
	case FLASH_SECT1:
		hflash.baseAddr=FLASH_ADDR_SECT1;
		break;
	case FLASH_SECT2:
		hflash.baseAddr=FLASH_ADDR_SECT2;
		break;
	case FLASH_SECT3:
		hflash.baseAddr=FLASH_ADDR_SECT3;
		break;
	case FLASH_SECT4:
		hflash.baseAddr=FLASH_ADDR_SECT4;
		break;
	case FLASH_SECT5:
		hflash.baseAddr=FLASH_ADDR_SECT5;
		break;
	case FLASH_SECT6:
		hflash.baseAddr=FLASH_ADDR_SECT6;
		break;
	case FLASH_SECT7:
		hflash.baseAddr=FLASH_ADDR_SECT7;
			break;
	default:
		break;
			 }

}



/* Write Flash */
void FLASH_WriteN(void *wrBuf, uint32_t Nsize)
{
	uint32_t flashAddress = hflash.baseAddr + hflash.sect_offset;

	//Erase sector before write
	FLASH_EraseSector();

	//Unlock Flash
	HAL_FLASH_Unlock();
	//Write to Flash
	switch(hflash.dataType)
	{
		case DATA_TYPE_8:
				for(uint32_t i=0; i<Nsize; i++)
				{
					HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, flashAddress , ((uint8_t *)wrBuf)[i]);
					flashAddress++;
				}
			break;

		case DATA_TYPE_16:
				for(uint32_t i=0; i<Nsize; i++)
				{
					HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, flashAddress , ((uint16_t *)wrBuf)[i]);
					flashAddress+=2;
				}
			break;

		case DATA_TYPE_32:
				for(uint32_t i=0; i<Nsize; i++)
				{
					HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flashAddress , ((uint32_t *)wrBuf)[i]);
					flashAddress+=4;
				}
			break;
	}
	//Lock the Flash space
	HAL_FLASH_Lock();
}
/* Read Flash */
void FLASH_ReadN(void *rdBuf, uint32_t Nsize)
{
	uint32_t flashAddress = hflash.baseAddr + hflash.sect_offset;

	switch(hflash.dataType)
	{
		case DATA_TYPE_8:
				for(uint32_t i=0; i<Nsize; i++)
				{
					*((uint8_t *)rdBuf + i) = *(uint8_t *)flashAddress;
					flashAddress++;
				}
			break;

		case DATA_TYPE_16:
				for(uint32_t i=0; i<Nsize; i++)
				{
					*((uint16_t *)rdBuf + i) = *(uint16_t *)flashAddress;
					flashAddress+=2;
				}
			break;

		case DATA_TYPE_32:
				for(uint32_t i=0; i<Nsize; i++)
				{
					*((uint32_t *)rdBuf + i) = *(uint32_t *)flashAddress;
					flashAddress+=4;
				}
			break;
	}
}

