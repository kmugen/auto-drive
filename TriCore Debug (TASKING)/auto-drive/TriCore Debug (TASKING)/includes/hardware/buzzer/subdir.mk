################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.o 

SRC_SRCS += \
../auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.src 

OBJS += \
./auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.o 


# Each subdirectory must supply rules for building sources it contributes
auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.o: ../auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.src auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-hardware-2f-buzzer

clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-hardware-2f-buzzer:
	-$(RM) ./auto-drive/TriCore\ Debug\ (TASKING)/includes/hardware/buzzer/buzzer.o

.PHONY: clean-auto-2d-drive-2f-TriCore-20-Debug-20--28-TASKING-29--2f-includes-2f-hardware-2f-buzzer

