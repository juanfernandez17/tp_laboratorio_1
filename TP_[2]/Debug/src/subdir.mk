################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayFlyCode.c \
../src/ArrayPassenger.c \
../src/TP_[2].c \
../src/utn.c 

C_DEPS += \
./src/ArrayFlyCode.d \
./src/ArrayPassenger.d \
./src/TP_[2].d \
./src/utn.d 

OBJS += \
./src/ArrayFlyCode.o \
./src/ArrayPassenger.o \
./src/TP_[2].o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayFlyCode.d ./src/ArrayFlyCode.o ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/TP_[2].d ./src/TP_[2].o ./src/utn.d ./src/utn.o

.PHONY: clean-src

