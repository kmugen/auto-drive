################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.o 

SRC_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.src 

OBJS += \
./tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.o: ../tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.src tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Configurations-2f-Debug

clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Configurations-2f-Debug:
	-$(RM) ./tmp/TriCore\ Debug\ (TASKING)/Configurations/Debug/sync_on_halt.o

.PHONY: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Configurations-2f-Debug

