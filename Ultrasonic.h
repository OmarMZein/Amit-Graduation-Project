#include "STD_TYPES.h"

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void ultrasonic_init(void);

u16 measure_distance(void);

void print_dist_LCD(u16 distance);

#endif /* ULTRASONIC_H_ */
