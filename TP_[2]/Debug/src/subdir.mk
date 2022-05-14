################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayFlyCode.c \
../src/ArrayPassenger.c \
../src/Input.c \
../src/Menu.c \
../src/TP_[2].c 

C_DEPS += \
./src/ArrayFlyCode.d \
./src/ArrayPassenger.d \
./src/Input.d \
./src/Menu.d \
./src/TP_[2].d 

OBJS += \
./src/ArrayFlyCode.o \
./src/ArrayPassenger.o \
./src/Input.o \
./src/Menu.o \
./src/TP_[2].o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayFlyCode.d ./src/ArrayFlyCode.o ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/Input.d ./src/Input.o ./src/Menu.d ./src/Menu.o ./src/TP_[2].d ./src/TP_[2].o

.PHONY: clean-src

