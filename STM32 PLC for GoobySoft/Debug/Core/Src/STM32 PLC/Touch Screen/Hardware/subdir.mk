################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.c 

OBJS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.o 

C_DEPS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.c Core/Src/STM32\ PLC/Touch\ Screen/Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Hardware/ILI9341.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.c Core/Src/STM32\ PLC/Touch\ Screen/Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Hardware/TSC2046.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Hardware

clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Hardware:
	-$(RM) ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.d ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.o ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/ILI9341.su ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.d ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.o ./Core/Src/STM32\ PLC/Touch\ Screen/Hardware/TSC2046.su

.PHONY: clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Hardware

