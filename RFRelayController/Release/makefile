################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include VirtualWire/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
RFRelayController.lss \

FLASH_IMAGE += \
RFRelayController.hex \

EEPROM_IMAGE += \
RFRelayController.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: RFRelayController.elf secondary-outputs

# Tool invocations
RFRelayController.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-gcc -Os -Wl,--gc-sections  -L"/home/xum/workspace-arduino2/Arduino_Duemilanove_w__ATmega328/Release" -mmcu=atmega328p -o"RFRelayController.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '

RFRelayController.lss: RFRelayController.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RFRelayController.elf  >"RFRelayController.lss"
	@echo 'Finished building: $@'
	@echo ' '

RFRelayController.hex: RFRelayController.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex RFRelayController.elf  "RFRelayController.hex"
	@echo 'Finished building: $@'
	@echo ' '

RFRelayController.eep: RFRelayController.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex RFRelayController.elf  "RFRelayController.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RFRelayController.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p RFRelayController.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(ELFS)$(FLASH_IMAGE)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) RFRelayController.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
