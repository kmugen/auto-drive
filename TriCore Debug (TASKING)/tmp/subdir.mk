################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tmp/Cpu0_Main.c \
../tmp/Cpu1_Main.c \
../tmp/Cpu2_Main.c 

COMPILED_SRCS += \
./tmp/Cpu0_Main.src \
./tmp/Cpu1_Main.src \
./tmp/Cpu2_Main.src 

C_DEPS += \
./tmp/Cpu0_Main.d \
./tmp/Cpu1_Main.d \
./tmp/Cpu2_Main.d 

OBJS += \
./tmp/Cpu0_Main.o \
./tmp/Cpu1_Main.o \
./tmp/Cpu2_Main.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/%.src: ../tmp/%.c tmp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/tmp\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

tmp/Cpu0_Main.o: ./tmp/Cpu0_Main.src tmp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Cpu1_Main.o: ./tmp/Cpu1_Main.src tmp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Cpu2_Main.o: ./tmp/Cpu2_Main.src tmp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp

clean-tmp:
	-$(RM) ./tmp/Cpu0_Main.d ./tmp/Cpu0_Main.o ./tmp/Cpu0_Main.src ./tmp/Cpu1_Main.d ./tmp/Cpu1_Main.o ./tmp/Cpu1_Main.src ./tmp/Cpu2_Main.d ./tmp/Cpu2_Main.o ./tmp/Cpu2_Main.src

.PHONY: clean-tmp

