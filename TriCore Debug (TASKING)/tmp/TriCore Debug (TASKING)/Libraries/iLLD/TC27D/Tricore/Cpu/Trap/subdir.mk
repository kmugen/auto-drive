################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.o 

SRC_SRCS += \
../tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.src 

OBJS += \
./tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.o: ../tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.src tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Cpu-2f-Trap

clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Cpu-2f-Trap:
	-$(RM) ./tmp/TriCore\ Debug\ (TASKING)/Libraries/iLLD/TC27D/Tricore/Cpu/Trap/IfxCpu_Trap.o

.PHONY: clean-tmp-2f-TriCore-20-Debug-20--28-TASKING-29--2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Cpu-2f-Trap

