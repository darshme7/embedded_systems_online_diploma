################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/7Segment_Driver/7segment.c 

OBJS += \
./HAL/7Segment_Driver/7segment.o 

C_DEPS += \
./HAL/7Segment_Driver/7segment.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/7Segment_Driver/%.o HAL/7Segment_Driver/%.su: ../HAL/7Segment_Driver/%.c HAL/7Segment_Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/HAL/Include" -I../Inc -I"D:/Courses/Master_Embedded_systems_diploma/stm_workspace/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-7Segment_Driver

clean-HAL-2f-7Segment_Driver:
	-$(RM) ./HAL/7Segment_Driver/7segment.d ./HAL/7Segment_Driver/7segment.o ./HAL/7Segment_Driver/7segment.su

.PHONY: clean-HAL-2f-7Segment_Driver

