################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.c 

OBJS += \
./STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/SPI/%.o STM32F103C6_Drivers/SPI/%.su: ../STM32F103C6_Drivers/SPI/%.c STM32F103C6_Drivers/SPI/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/HAL/Include" -I../Inc -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-SPI

clean-STM32F103C6_Drivers-2f-SPI:
	-$(RM) ./STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.d ./STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.o ./STM32F103C6_Drivers/SPI/stm32f103c6_spi_driver.su

.PHONY: clean-STM32F103C6_Drivers-2f-SPI

