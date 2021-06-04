################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_Driver/Keypad.c 

OBJS += \
./HAL/Keypad_Driver/Keypad.o 

C_DEPS += \
./HAL/Keypad_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad_Driver/Keypad.o: ../HAL/Keypad_Driver/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/HAL/Include" -I../Inc -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad_Driver/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

