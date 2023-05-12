#include "STD_TYPES.h"


#ifndef SERVO_TIMER2_H_
#define SERVO_TIMER2_H_

#define right_dir 48
#define middle_dir 180
#define left_dir 254


void init_servo(void);

void rotate_servo_left(void);

void rotate_servo_right(void);

void rotate_servo_mid(void);


#endif /* SERVO_TIMER2_H_ */
