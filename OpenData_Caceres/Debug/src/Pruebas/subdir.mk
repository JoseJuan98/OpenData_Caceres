################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Pruebas/PruebasClasesContenedores.cpp \
../src/Pruebas/PruebasGestorBarrios.cpp \
../src/Pruebas/PruebasGestorCalles.cpp \
../src/Pruebas/PruebasGestorDistritos.cpp 

OBJS += \
./src/Pruebas/PruebasClasesContenedores.o \
./src/Pruebas/PruebasGestorBarrios.o \
./src/Pruebas/PruebasGestorCalles.o \
./src/Pruebas/PruebasGestorDistritos.o 

CPP_DEPS += \
./src/Pruebas/PruebasClasesContenedores.d \
./src/Pruebas/PruebasGestorBarrios.d \
./src/Pruebas/PruebasGestorCalles.d \
./src/Pruebas/PruebasGestorDistritos.d 


# Each subdirectory must supply rules for building sources it contributes
src/Pruebas/%.o: ../src/Pruebas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


