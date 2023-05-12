#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>


#ifndef AMIT_GRAD_PROJ_H_
#define AMIT_GRAD_PROJ_H_

#define Front_motor_A 0
#define Front_motor_B 1
#define Back_motor_A 2
#define Back_motor_B 3

void motors_init();
void rotate_servo_right(void);
void rotate_servo_left(void);
void turn_left(void);
void turn_right(void);
void move_forward(void);
void move_backward(void);
void stop_motors(void);
u8 read_ultrasonic(void);



#endif /* AMIT_GRAD_PROJ_H_ */
