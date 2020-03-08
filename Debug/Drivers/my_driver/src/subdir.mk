################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/my_driver/src/coreApplication.c \
../Drivers/my_driver/src/main_flash.c \
../Drivers/my_driver/src/main_lcd16x2.c \
../Drivers/my_driver/src/main_timer.c \
../Drivers/my_driver/src/my_LCD16x2.c \
../Drivers/my_driver/src/my_flash.c \
../Drivers/my_driver/src/my_timer.c 

OBJS += \
./Drivers/my_driver/src/coreApplication.o \
./Drivers/my_driver/src/main_flash.o \
./Drivers/my_driver/src/main_lcd16x2.o \
./Drivers/my_driver/src/main_timer.o \
./Drivers/my_driver/src/my_LCD16x2.o \
./Drivers/my_driver/src/my_flash.o \
./Drivers/my_driver/src/my_timer.o 

C_DEPS += \
./Drivers/my_driver/src/coreApplication.d \
./Drivers/my_driver/src/main_flash.d \
./Drivers/my_driver/src/main_lcd16x2.d \
./Drivers/my_driver/src/main_timer.d \
./Drivers/my_driver/src/my_LCD16x2.d \
./Drivers/my_driver/src/my_flash.d \
./Drivers/my_driver/src/my_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/my_driver/src/coreApplication.o: ../Drivers/my_driver/src/coreApplication.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/coreApplication.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/main_flash.o: ../Drivers/my_driver/src/main_flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/main_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/main_lcd16x2.o: ../Drivers/my_driver/src/main_lcd16x2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/main_lcd16x2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/main_timer.o: ../Drivers/my_driver/src/main_timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/main_timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/my_LCD16x2.o: ../Drivers/my_driver/src/my_LCD16x2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/my_LCD16x2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/my_flash.o: ../Drivers/my_driver/src/my_flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/my_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/my_driver/src/my_timer.o: ../Drivers/my_driver/src/my_timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/my_timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

