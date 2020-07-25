################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Contenedores/Barrio.cpp \
../src/Contenedores/Farola.cpp \
../src/Contenedores/Via.cpp \
../src/Contenedores/distrito.cpp 

OBJS += \
./src/Contenedores/Barrio.o \
./src/Contenedores/Farola.o \
./src/Contenedores/Via.o \
./src/Contenedores/distrito.o 

CPP_DEPS += \
./src/Contenedores/Barrio.d \
./src/Contenedores/Farola.d \
./src/Contenedores/Via.d \
./src/Contenedores/distrito.d 


# Each subdirectory must supply rules for building sources it contributes
src/Contenedores/%.o: ../src/Contenedores/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


