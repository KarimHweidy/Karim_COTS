################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../PORT_prog.c \
../STEPPER_cfg.c \
../STEPPER_prog.c \
../main.c 

OBJS += \
./DIO_program.o \
./PORT_prog.o \
./STEPPER_cfg.o \
./STEPPER_prog.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./PORT_prog.d \
./STEPPER_cfg.d \
./STEPPER_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


