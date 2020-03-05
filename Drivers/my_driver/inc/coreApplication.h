#ifndef __CORE_APPLICATION_H
#define __CORE_APPLICATION_H

#include "main.h"
#define MAIN_APPLICATION (MainFunction)Flash

/*defining the type of application
 * MAIN
 * FLASH_TEST
 * */
#define FLASH_TEST     1

typedef enum{
	Flash,
}MainFunction;

#endif
