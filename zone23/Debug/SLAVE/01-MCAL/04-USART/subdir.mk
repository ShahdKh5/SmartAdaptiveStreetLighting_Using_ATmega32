################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SLAVE/01-MCAL/04-USART/USART_program.c 

OBJS += \
./SLAVE/01-MCAL/04-USART/USART_program.o 

C_DEPS += \
./SLAVE/01-MCAL/04-USART/USART_program.d 


# Each subdirectory must supply rules for building sources it contributes
SLAVE/01-MCAL/04-USART/%.o: ../SLAVE/01-MCAL/04-USART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


