#include "Servo_timer2.h"
#include "Ultrasonic.h"
#include "Amit_Grad_Proj.h"

#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>		/* Include Delay header file */



void init_servo(void)
{
	DDRD |= (1<<PD7);	/* Make OC1A pin as output */

	/* Set Fast PWM */
	TCCR2 |= (1<<WGM20)|(1<<WGM21);

	/*Non-inverting mode*/
	TCCR2 |= (1<<COM21);

	/*Prescaler /128 */
	TCCR2 |= (1<<CS22) | (1<<CS20);
}

void rotate_servo_right(void)
{
	OCR2 = right_dir;
	_delay_ms(1500);

	if (measure_distance() < 30)
	{
		rotate_servo_left();
	}
	else
	{
		rotate_servo_mid();
		turn_right();
	}
}

void rotate_servo_left(void)
{
	OCR2 = left_dir;
	_delay_ms(1500);

	if (measure_distance() < 30)
	{
		move_backward();
	}
	else
	{
		turn_left();
	}
	rotate_servo_mid();
}

void rotate_servo_mid(void)
{
	OCR2 = middle_dir;
	_delay_ms(1500);
}
