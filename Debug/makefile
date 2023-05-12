################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Amit_Grad_Proj.lss \

FLASH_IMAGE += \
Amit_Grad_Proj.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Amit_Grad_Proj.elf secondary-outputs

# Tool invocations
Amit_Grad_Proj.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Amit_Grad_Proj.map -mmcu=atmega32 -o "Amit_Grad_Proj.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Amit_Grad_Proj.lss: Amit_Grad_Proj.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Amit_Grad_Proj.elf  >"Amit_Grad_Proj.lss"
	@echo 'Finished building: $@'
	@echo ' '

Amit_Grad_Proj.hex: Amit_Grad_Proj.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Amit_Grad_Proj.elf  "Amit_Grad_Proj.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Amit_Grad_Proj.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Amit_Grad_Proj.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Amit_Grad_Proj.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
