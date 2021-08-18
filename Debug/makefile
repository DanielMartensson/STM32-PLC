################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_DEVICE/Target/subdir.mk
-include USB_DEVICE/App/subdir.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Logics/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Hardware/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Frames/Tools/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Frames/SAE\ J1939\ Frames/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Frames/subdir.mk
-include Core/Src/STM32\ PLC/Touch\ Screen/Dialogs/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/SAE\ J1939/SAE\ J1939-81\ Network\ Management\ Layer/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/SAE\ J1939/SAE\ J1939-73\ Diagnostics\ Layer/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/SAE\ J1939/SAE\ J1939-71\ Application\ Layer/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/SAE\ J1939/SAE\ J1939-21\ Transport\ Layer/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/Open\ SAE\ J1939/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/ISO\ 11783/ISO\ 11783-7\ Application\ Layer/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/Hardware/Memory/subdir.mk
-include Core/Src/STM32\ PLC/Open\ SAE\ J1939/Hardware/CAN\ Network/subdir.mk
-include Core/Src/STM32\ PLC/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := PLC STM32
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PLC\ STM32.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PLC\ STM32.list \

OBJCOPY_BIN += \
PLC\ STM32.bin \


# All Target
all: main-build

# Main-build Target
main-build: PLC\ STM32.elf secondary-outputs

# Tool invocations
PLC\ STM32.elf: $(OBJS) $(USER_OBJS) C:\Users\danie\Documents\STM32CubeIDE-Workspace\PLC\ STM32\STM32F373VBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "PLC STM32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\danie\Documents\STM32CubeIDE-Workspace\PLC STM32\STM32F373VBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PLC STM32.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PLC\ STM32.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PLC STM32.list"
	@echo 'Finished building: $@'
	@echo ' '

PLC\ STM32.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PLC STM32.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SIZE_OUTPUT)$(OBJDUMP_LIST)$(EXECUTABLES)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(OBJCOPY_BIN) "PLC STM32.elf"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
