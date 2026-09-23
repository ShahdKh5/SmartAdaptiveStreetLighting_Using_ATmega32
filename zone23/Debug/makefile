################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SLAVE/03-APP/subdir.mk
-include SLAVE/02-HAL/04-LED/subdir.mk
-include SLAVE/02-HAL/03-ULTRASONIC/subdir.mk
-include SLAVE/01-MCAL/04-USART/subdir.mk
-include SLAVE/01-MCAL/03-TIMER/subdir.mk
-include SLAVE/01-MCAL/01-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
zone23.lss \

FLASH_IMAGE += \
zone23.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: zone23.elf secondary-outputs

# Tool invocations
zone23.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,zone23.map -mmcu=atmega32 -o "zone23.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

zone23.lss: zone23.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S zone23.elf  >"zone23.lss"
	@echo 'Finished building: $@'
	@echo ' '

zone23.hex: zone23.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex zone23.elf  "zone23.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: zone23.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 zone23.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) zone23.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
