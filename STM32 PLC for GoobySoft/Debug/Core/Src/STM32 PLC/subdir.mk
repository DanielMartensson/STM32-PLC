################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/STM32\ PLC/Analog_Input.c \
../Core/Src/STM32\ PLC/Analog_Output.c \
../Core/Src/STM32\ PLC/CAN.c \
../Core/Src/STM32\ PLC/Digital_Input.c \
../Core/Src/STM32\ PLC/Encoder.c \
../Core/Src/STM32\ PLC/Flash.c \
../Core/Src/STM32\ PLC/Input_Capture.c \
../Core/Src/STM32\ PLC/LCD.c \
../Core/Src/STM32\ PLC/LED.c \
../Core/Src/STM32\ PLC/PWM.c \
../Core/Src/STM32\ PLC/RTC.c \
../Core/Src/STM32\ PLC/USB.c 

OBJS += \
./Core/Src/STM32\ PLC/Analog_Input.o \
./Core/Src/STM32\ PLC/Analog_Output.o \
./Core/Src/STM32\ PLC/CAN.o \
./Core/Src/STM32\ PLC/Digital_Input.o \
./Core/Src/STM32\ PLC/Encoder.o \
./Core/Src/STM32\ PLC/Flash.o \
./Core/Src/STM32\ PLC/Input_Capture.o \
./Core/Src/STM32\ PLC/LCD.o \
./Core/Src/STM32\ PLC/LED.o \
./Core/Src/STM32\ PLC/PWM.o \
./Core/Src/STM32\ PLC/RTC.o \
./Core/Src/STM32\ PLC/USB.o 

C_DEPS += \
./Core/Src/STM32\ PLC/Analog_Input.d \
./Core/Src/STM32\ PLC/Analog_Output.d \
./Core/Src/STM32\ PLC/CAN.d \
./Core/Src/STM32\ PLC/Digital_Input.d \
./Core/Src/STM32\ PLC/Encoder.d \
./Core/Src/STM32\ PLC/Flash.d \
./Core/Src/STM32\ PLC/Input_Capture.d \
./Core/Src/STM32\ PLC/LCD.d \
./Core/Src/STM32\ PLC/LED.d \
./Core/Src/STM32\ PLC/PWM.d \
./Core/Src/STM32\ PLC/RTC.d \
./Core/Src/STM32\ PLC/USB.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32\ PLC/Analog_Input.o: ../Core/Src/STM32\ PLC/Analog_Input.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Analog_Input.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Analog_Output.o: ../Core/Src/STM32\ PLC/Analog_Output.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Analog_Output.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/CAN.o: ../Core/Src/STM32\ PLC/CAN.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/CAN.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Digital_Input.o: ../Core/Src/STM32\ PLC/Digital_Input.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Digital_Input.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Encoder.o: ../Core/Src/STM32\ PLC/Encoder.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Encoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Flash.o: ../Core/Src/STM32\ PLC/Flash.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Input_Capture.o: ../Core/Src/STM32\ PLC/Input_Capture.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/Input_Capture.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/LCD.o: ../Core/Src/STM32\ PLC/LCD.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/LCD.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/LED.o: ../Core/Src/STM32\ PLC/LED.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/LED.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/PWM.o: ../Core/Src/STM32\ PLC/PWM.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/PWM.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/RTC.o: ../Core/Src/STM32\ PLC/RTC.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/RTC.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/USB.o: ../Core/Src/STM32\ PLC/USB.c Core/Src/STM32\ PLC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/STM32 PLC/USB.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-STM32-20-PLC

clean-Core-2f-Src-2f-STM32-20-PLC:
	-$(RM) ./Core/Src/STM32\ PLC/Analog_Input.cyclo ./Core/Src/STM32\ PLC/Analog_Input.d ./Core/Src/STM32\ PLC/Analog_Input.o ./Core/Src/STM32\ PLC/Analog_Input.su ./Core/Src/STM32\ PLC/Analog_Output.cyclo ./Core/Src/STM32\ PLC/Analog_Output.d ./Core/Src/STM32\ PLC/Analog_Output.o ./Core/Src/STM32\ PLC/Analog_Output.su ./Core/Src/STM32\ PLC/CAN.cyclo ./Core/Src/STM32\ PLC/CAN.d ./Core/Src/STM32\ PLC/CAN.o ./Core/Src/STM32\ PLC/CAN.su ./Core/Src/STM32\ PLC/Digital_Input.cyclo ./Core/Src/STM32\ PLC/Digital_Input.d ./Core/Src/STM32\ PLC/Digital_Input.o ./Core/Src/STM32\ PLC/Digital_Input.su ./Core/Src/STM32\ PLC/Encoder.cyclo ./Core/Src/STM32\ PLC/Encoder.d ./Core/Src/STM32\ PLC/Encoder.o ./Core/Src/STM32\ PLC/Encoder.su ./Core/Src/STM32\ PLC/Flash.cyclo ./Core/Src/STM32\ PLC/Flash.d ./Core/Src/STM32\ PLC/Flash.o ./Core/Src/STM32\ PLC/Flash.su ./Core/Src/STM32\ PLC/Input_Capture.cyclo ./Core/Src/STM32\ PLC/Input_Capture.d ./Core/Src/STM32\ PLC/Input_Capture.o ./Core/Src/STM32\ PLC/Input_Capture.su ./Core/Src/STM32\ PLC/LCD.cyclo ./Core/Src/STM32\ PLC/LCD.d ./Core/Src/STM32\ PLC/LCD.o ./Core/Src/STM32\ PLC/LCD.su ./Core/Src/STM32\ PLC/LED.cyclo ./Core/Src/STM32\ PLC/LED.d ./Core/Src/STM32\ PLC/LED.o ./Core/Src/STM32\ PLC/LED.su ./Core/Src/STM32\ PLC/PWM.cyclo ./Core/Src/STM32\ PLC/PWM.d ./Core/Src/STM32\ PLC/PWM.o ./Core/Src/STM32\ PLC/PWM.su ./Core/Src/STM32\ PLC/RTC.cyclo ./Core/Src/STM32\ PLC/RTC.d ./Core/Src/STM32\ PLC/RTC.o ./Core/Src/STM32\ PLC/RTC.su ./Core/Src/STM32\ PLC/USB.cyclo ./Core/Src/STM32\ PLC/USB.d ./Core/Src/STM32\ PLC/USB.o ./Core/Src/STM32\ PLC/USB.su

.PHONY: clean-Core-2f-Src-2f-STM32-20-PLC

