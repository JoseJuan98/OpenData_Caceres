################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Gestores/Barrios.cpp \
../src/Gestores/Calles.cpp \
../src/Gestores/Distritos.cpp 

OBJS += \
./src/Gestores/Barrios.o \
./src/Gestores/Calles.o \
./src/Gestores/Distritos.o 

CPP_DEPS += \
./src/Gestores/Barrios.d \
./src/Gestores/Calles.d \
./src/Gestores/Distritos.d 


# Each subdirectory must supply rules for building sources it contributes
src/Gestores/%.o: ../src/Gestores/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


