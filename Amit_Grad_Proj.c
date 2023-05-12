#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Amit_Grad_Proj.h"
#include "Ultrasonic.h"

#include <avr/io.h>
#include <util/delay.h>

void motors_init(void)
{
	//Back motor
	DDRB |= (1<<Back_motor_A);
	DDRB |= (1<<Back_motor_B);

	//Front motor
	DDRB |= (1<<Front_motor_A);
	DDRB |= (1<<Front_motor_B);
}

void turn_right(void)
{
	//Rotate left motor forward
	PORTB &= ~(1<<Back_motor_A);
	PORTB |= (1<<Back_motor_B);

	//Stop right motor
	PORTB |= (1<<Front_motor_A);
	PORTB &= ~(1<<Front_motor_B);

	_delay_ms(1000);
}

void turn_left(void)
{
	//Stop Left motor
	PORTB &= ~(1<<Back_motor_A);
	PORTB |= (1<<Back_motor_B);

	//Rotate right motor forward
	PORTB &= ~(1<<Front_motor_A);
	PORTB |= (1<<Front_motor_B);

	_delay_ms(1000);
}

void move_backward(void)
{
	//Rotate left motor forward
	PORTB |= (1<<Back_motor_A);
	PORTB &= ~(1<<Back_motor_B);

	//Rotate right motor forward
	PORTB &= ~(1<<Front_motor_A);
	PORTB &= ~(1<<Front_motor_B);

	_delay_ms(3000);
}

void move_forward(void)
{
	//Rotate left motor backward
	PORTB &= ~(1<<Back_motor_A);
	PORTB |= (1<<Back_motor_B);

	//Rotate right motor backward
	PORTB &= ~(1<<Front_motor_A);
	PORTB &= ~(1<<Front_motor_B);

	_delay_ms(1000);
}

void stop_motors(void)
{
	//Stop left motor
	PORTB &= ~(1<<Back_motor_A);
	PORTB &= ~(1<<Back_motor_B);

	//Stop right motor
	PORTB &= ~(1<<Front_motor_A);
	PORTB &= ~(1<<Front_motor_B);

	_delay_ms(1000);
}
