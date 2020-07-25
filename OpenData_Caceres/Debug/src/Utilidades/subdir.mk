################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Utilidades/coords.cpp \
../src/Utilidades/timer.cpp 

OBJS += \
./src/Utilidades/coords.o \
./src/Utilidades/timer.o 

CPP_DEPS += \
./src/Utilidades/coords.d \
./src/Utilidades/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Utilidades/%.o: ../src/Utilidades/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


