################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
../tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
../tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
../tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c 

COMPILED_SRCS += \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src 

C_DEPS += \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d 

OBJS += \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o \
./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/Libraries/Service/CpuGeneric/StdIf/%.src: ../tmp/Libraries/Service/CpuGeneric/StdIf/%.c tmp/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/tmp\/Libraries\/Service\/CpuGeneric\/StdIf\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o: ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src tmp/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o: ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src tmp/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o: ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src tmp/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o: ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src tmp/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

clean-tmp-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf:
	-$(RM) ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o ./tmp/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src

.PHONY: clean-tmp-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

