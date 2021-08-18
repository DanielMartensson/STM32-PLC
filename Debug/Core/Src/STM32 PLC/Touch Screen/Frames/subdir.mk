################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Analog_input_settings_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Control_program_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Date_time_alarm_settings_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Encoder_revolutions_settings_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Logging_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Main_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Measurement_and_time_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/PWM_frequency_settings_frame.c \
../Core/Src/STM32\ PLC/Touch\ Screen/Frames/SDADC_settings_frame.c 

OBJS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Analog_input_settings_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Control_program_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Date_time_alarm_settings_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Encoder_revolutions_settings_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Logging_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Main_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Measurement_and_time_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/PWM_frequency_settings_frame.o \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/SDADC_settings_frame.o 

C_DEPS += \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Analog_input_settings_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Control_program_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Date_time_alarm_settings_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Encoder_revolutions_settings_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Logging_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Main_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/Measurement_and_time_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/PWM_frequency_settings_frame.d \
./Core/Src/STM32\ PLC/Touch\ Screen/Frames/SDADC_settings_frame.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Analog_input_settings_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Analog_input_settings_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Analog_input_settings_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Control_program_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Control_program_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Control_program_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Date_time_alarm_settings_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Date_time_alarm_settings_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Date_time_alarm_settings_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Encoder_revolutions_settings_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Encoder_revolutions_settings_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Encoder_revolutions_settings_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Logging_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Logging_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Logging_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Main_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Main_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Main_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/Measurement_and_time_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/Measurement_and_time_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/Measurement_and_time_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/PWM_frequency_settings_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/PWM_frequency_settings_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/PWM_frequency_settings_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/STM32\ PLC/Touch\ Screen/Frames/SDADC_settings_frame.o: ../Core/Src/STM32\ PLC/Touch\ Screen/Frames/SDADC_settings_frame.c Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F373xC -c -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/STM32 PLC/Touch Screen/Frames/SDADC_settings_frame.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

