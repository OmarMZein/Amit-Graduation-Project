#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Amit_Grad_Proj.h"
#include "Servo_timer2.h"
#include "Ultrasonic.h"

#include <avr/io.h>

u16 distance_left;

int main (void)
{
	ultrasonic_init();
	init_servo();
	motors_init();

	while(1)
	{
		distance_left = measure_distance();			//calculate distance between obstacle

		if (distance_left < 50)
		{
			stop_motors();
		}

		if (distance_left < 30)
		{
			//stop_motors();
			rotate_servo_right();
		}
		else
		{
			move_forward();
		}
	}
}
