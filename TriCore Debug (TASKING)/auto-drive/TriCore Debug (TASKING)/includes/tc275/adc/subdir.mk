################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.o 

SRC_SRCS += \
../auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.src 

OBJS += \
./auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.o 


# Each subdirectory must supply rules for building sources it contributes
auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.o: ../auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.src auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-tc275-2f-adc

clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-tc275-2f-adc:
	-$(RM) ./auto-drive/TriCore\ Debug\ (TASKING)/includes/tc275/adc/adc.o

.PHONY: clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-tc275-2f-adc

