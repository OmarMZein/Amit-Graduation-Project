################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Amit_Grad_Proj.c \
../LCD.c \
../Servo_timer2.c \
../Ultrasonic.c \
../main.c 

OBJS += \
./Amit_Grad_Proj.o \
./LCD.o \
./Servo_timer2.o \
./Ultrasonic.o \
./main.o 

C_DEPS += \
./Amit_Grad_Proj.d \
./LCD.d \
./Servo_timer2.d \
./Ultrasonic.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


