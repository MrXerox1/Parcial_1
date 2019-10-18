################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Datos.c \
../src/Parcial.c \
../src/funciones.c \
../src/informes.c \
../src/libreria_modelo\ _parcial.c 

OBJS += \
./src/Datos.o \
./src/Parcial.o \
./src/funciones.o \
./src/informes.o \
./src/libreria_modelo\ _parcial.o 

C_DEPS += \
./src/Datos.d \
./src/Parcial.d \
./src/funciones.d \
./src/informes.d \
./src/libreria_modelo\ _parcial.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libreria_modelo\ _parcial.o: ../src/libreria_modelo\ _parcial.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/libreria_modelo _parcial.d" -MT"src/libreria_modelo\ _parcial.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


