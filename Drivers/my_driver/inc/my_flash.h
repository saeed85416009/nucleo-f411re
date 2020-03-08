#ifndef __MY_FLASH_H
#define __MY_FLASH_H

#include "main.h"
#include "stm32f4xx_hal.h"
#include "coreApplication.h"
#include "my_flash.h"

#define FLASH_ADDR_SECT0     0x08000000
#define FLASH_ADDR_SECT1     0x08004000
#define FLASH_ADDR_SECT2     0x08008000
#define FLASH_ADDR_SECT3     0x0800C000
#define FLASH_ADDR_SECT4     0x08010000
#define FLASH_ADDR_SECT5     0x08020000
#define FLASH_ADDR_SECT6     0x08040000
#define FLASH_ADDR_SECT7     0x08060000
#define FLASH_ADDR_OTP       0x1FFF7800

#define FLASH_SECT0     0
#define FLASH_SECT1     1
#define FLASH_SECT2     2
#define FLASH_SECT3     3
#define FLASH_SECT4     4
#define FLASH_SECT5     5
#define FLASH_SECT6     6
#define FLASH_SECT7     7
#define FLASH_OTP       0xFF

//Typedefs
// data size
typedef enum
{
	DATA_TYPE_8=0,
	DATA_TYPE_16,
	DATA_TYPE_32,
}DataTypeDef;



typedef struct  {
	uint8_t sector;
	uint32_t sect_offset;
	uint32_t baseAddr;
	DataTypeDef dataType;
	uint32_t MY_SectorAddrs;
}My_Flash_TypeDef;

/* ...........    prototypes   .................. */

void Flash_SectConf(void);
/* Erase Sector */
static void FLASH_EraseSector(void);

/* Write Flash */
void FLASH_WriteN(void *wrBuf, uint32_t Nsize);
/* Read Flash */
void FLASH_ReadN(void *rdBuf, uint32_t Nsize);


#endif
