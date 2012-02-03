################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/opt/arduino-1.0/libraries/VirtualWire/VirtualWire.cpp 

OBJS += \
./VirtualWire/VirtualWire.o 

CPP_DEPS += \
./VirtualWire/VirtualWire.d 


# Each subdirectory must supply rules for building sources it contributes
VirtualWire/VirtualWire.o: /opt/arduino-1.0/libraries/VirtualWire/VirtualWire.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/opt/arduino-1.0/hardware/arduino/cores/arduino" -I"/opt/arduino-1.0/hardware/arduino/variants/standard" -I"/home/xum/workspace-arduino2/RFRelayController" -I"/opt/arduino-1.0/libraries/VirtualWire" -D__IN_ECLIPSE__=1 -DARDUINO=100 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


