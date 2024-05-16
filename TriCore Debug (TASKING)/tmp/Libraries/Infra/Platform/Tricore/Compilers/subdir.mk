################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c \
../tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c \
../tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c \
../tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c \
../tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c 

COMPILED_SRCS += \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src 

C_DEPS += \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d 

OBJS += \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o \
./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/Libraries/Infra/Platform/Tricore/Compilers/%.src: ../tmp/Libraries/Infra/Platform/Tricore/Compilers/%.c tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/tmp\/Libraries\/Infra\/Platform\/Tricore\/Compilers\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o: ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o: ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o: ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o: ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o: ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src tmp/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

clean-tmp-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers:
	-$(RM) ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o ./tmp/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src

.PHONY: clean-tmp-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

