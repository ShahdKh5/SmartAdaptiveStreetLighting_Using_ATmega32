################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SLAVE/03-APP/APP_program.c \
../SLAVE/03-APP/main.c 

OBJS += \
./SLAVE/03-APP/APP_program.o \
./SLAVE/03-APP/main.o 

C_DEPS += \
./SLAVE/03-APP/APP_program.d \
./SLAVE/03-APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
SLAVE/03-APP/%.o: ../SLAVE/03-APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


