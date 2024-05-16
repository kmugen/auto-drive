################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.o \
../tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.o \
../tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.o 

SRC_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.src \
../tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.src \
../tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.src 

OBJS += \
./tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.o \
./tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.o \
./tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.o: ../tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.src tmp/TriCore\ Debug\ (TASKING)/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.o: ../tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.src tmp/TriCore\ Debug\ (TASKING)/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.o: ../tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.src tmp/TriCore\ Debug\ (TASKING)/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29-

clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29-:
	-$(RM) ./tmp/TriCore\ Debug\ (TASKING)/Cpu0_Main.o ./tmp/TriCore\ Debug\ (TASKING)/Cpu1_Main.o ./tmp/TriCore\ Debug\ (TASKING)/Cpu2_Main.o

.PHONY: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29-

