################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.cpp 

C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.c 

COMPILED_SRCS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.src 

CPP_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.src: ../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.c .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/.metadata\/.plugins\/org.eclipse.cdt.managedbuilder.core\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o: ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.src .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.src: ../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.cpp .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_hub/auto-drive/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/.metadata\/.plugins\/org.eclipse.cdt.managedbuilder.core\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core:
	-$(RM) ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.src

.PHONY: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

