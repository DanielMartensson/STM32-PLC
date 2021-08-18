################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Intro_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Keyboard_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Numpad_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Plot_frame.c 

OBJS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Intro_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Keyboard_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Numpad_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Plot_frame.o 

C_DEPS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Intro_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Keyboard_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Numpad_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Plot_frame.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Intro_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Intro_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Tools/Intro_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Keyboard_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Keyboard_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Tools/Keyboard_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Numpad_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Numpad_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Tools/Numpad_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Plot_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/Plot_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Tools/Plot_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
