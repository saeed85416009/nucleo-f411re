################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/my_driver/src/my_flash.c 

OBJS += \
./Drivers/my_driver/src/my_flash.o 

C_DEPS += \
./Drivers/my_driver/src/my_flash.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/my_driver/src/my_flash.o: ../Drivers/my_driver/src/my_flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Inc -I"C:/ST_workspace/nucleo-f411re-Saeed/Drivers/my_driver/inc" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/my_driver/src/my_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

