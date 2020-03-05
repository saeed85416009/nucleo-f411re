#ifndef __MY_FLASH_H
#define __MY_FLASH_H

#include "stm32f4xx_hal.h"

//Typedefs
// data size
typedef enum
{
	DATA_TYPE_8=0,
	DATA_TYPE_16,
	DATA_TYPE_32,
}DataTypeDef;

// flash instruction

/*typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                        !< Register base address

  DMA_InitTypeDef            Init;                                                             !< DMA communication parameters

  HAL_LockTypeDef            Lock;                                                             !< DMA locking object

  __IO HAL_DMA_StateTypeDef  State;                                                            !< DMA transfer state

  __IO uint32_t              ErrorCode;                                                        !< DMA Error code

  uint32_t                   StreamBaseAddress;                                                !< DMA Stream Base Address

  uint32_t                   StreamIndex;                                                      !< DMA Stream Index

}DMA_HandleTypeDef;*/

/* ...........    prototypes   .................. */

/* Erase Sector */
static void FLASH_EraseSector(void);

/* Set Sector Adress */
void FLASH_SetSectorAddrs(uint8_t sector, uint32_t addrs);
/* Write Flash */
void FLASH_WriteN(uint32_t idx, void *wrBuf, uint32_t Nsize, DataTypeDef dataType);
/* Read Flash */
void FLASH_ReadN(uint32_t idx, void *rdBuf, uint32_t Nsize, DataTypeDef dataType);


#endif
