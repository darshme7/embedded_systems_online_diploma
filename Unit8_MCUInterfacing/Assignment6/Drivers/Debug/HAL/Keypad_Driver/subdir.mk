################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_Driver/Keypad.c 

OBJS += \
./HAL/Keypad_Driver/Keypad.o 

C_DEPS += \
./HAL/Keypad_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad_Driver/%.o HAL/Keypad_Driver/%.su: ../HAL/Keypad_Driver/%.c HAL/Keypad_Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/HAL/Include" -I../Inc -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Keypad_Driver

clean-HAL-2f-Keypad_Driver:
	-$(RM) ./HAL/Keypad_Driver/Keypad.d ./HAL/Keypad_Driver/Keypad.o ./HAL/Keypad_Driver/Keypad.su

.PHONY: clean-HAL-2f-Keypad_Driver

