################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.c 

COMPILED_SRCS += \
./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.src 

C_DEPS += \
./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.d 

OBJS += \
./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.o 


# Each subdirectory must supply rules for building sources it contributes
tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/%.src: ../tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/%.c tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/tmp\/Libraries\/iLLD\/TC27D\/Tricore\/Fce\/Crc\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.o: ./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.src tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tmp-2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Fce-2f-Crc

clean-tmp-2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Fce-2f-Crc:
	-$(RM) ./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.d ./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.o ./tmp/Libraries/iLLD/TC27D/Tricore/Fce/Crc/IfxFce_Crc.src

.PHONY: clean-tmp-2f-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Fce-2f-Crc

