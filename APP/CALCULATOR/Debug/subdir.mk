################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_program.c \
../KPD_program.c \
../PORT_prog.c \
../calculatormain.c 

OBJS += \
./CLCD_program.o \
./DIO_program.o \
./KPD_program.o \
./PORT_prog.o \
./calculatormain.o 

C_DEPS += \
./CLCD_program.d \
./DIO_program.d \
./KPD_program.d \
./PORT_prog.d \
./calculatormain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


