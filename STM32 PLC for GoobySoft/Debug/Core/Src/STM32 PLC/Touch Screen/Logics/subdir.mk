################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.c 

OBJS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.o 

C_DEPS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.c Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Logics/Keyboard_logic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.c Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Logics/Main_logic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.c Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Logics/Numpad_logic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.c Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Logics/One_button_logic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.c Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Logics/Two_button_logic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Logics

clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Logics:
	-$(RM) ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.d ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.o ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Keyboard_logic.su ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.d ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.o ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Main_logic.su ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.d ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.o ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Numpad_logic.su ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.d ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.o ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/One_button_logic.su ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.cyclo ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.d ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.o ./Core/Src/STM32\ PLC/Touch\ Screen/Logics/Two_button_logic.su

.PHONY: clean-Core-2f-Src-2f-STM32-20-PLC-2f-Touch-20-Screen-2f-Logics

