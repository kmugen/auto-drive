################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/hardware/ultrasonic/ultrasonic.c 

COMPILED_SRCS += \
./includes/hardware/ultrasonic/ultrasonic.src 

C_DEPS += \
./includes/hardware/ultrasonic/ultrasonic.d 

OBJS += \
./includes/hardware/ultrasonic/ultrasonic.o 


# Each subdirectory must supply rules for building sources it contributes
includes/hardware/ultrasonic/%.src: ../includes/hardware/ultrasonic/%.c includes/hardware/ultrasonic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/includes\/hardware\/ultrasonic\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

includes/hardware/ultrasonic/ultrasonic.o: ./includes/hardware/ultrasonic/ultrasonic.src includes/hardware/ultrasonic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-includes-2f-hardware-2f-ultrasonic

clean-includes-2f-hardware-2f-ultrasonic:
	-$(RM) ./includes/hardware/ultrasonic/ultrasonic.d ./includes/hardware/ultrasonic/ultrasonic.o ./includes/hardware/ultrasonic/ultrasonic.src

.PHONY: clean-includes-2f-hardware-2f-ultrasonic

