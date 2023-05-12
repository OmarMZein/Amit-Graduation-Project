#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "Ultrasonic.h"
#include "STD_TYPES.h"
#include "LCD.h"

//#define F_CPU 16000000UL

#define TRIGGER_PIN PA0
#define ECHO_PIN PD6

char string[10];

void ultrasonic_init(void)
{
	DDRD &= ~(1 << ECHO_PIN);  // set echo pin as input
	DDRA |= (1 << TRIGGER_PIN);  // set trigger pin as output
}

u16 measure_distance() {

	TCCR1B |= (1 << CS11);  // Set the prescaler to 8
	TCNT1 = 0;              // Initialize the timer to 0

	// Set trigger pin low for 2 microseconds
	PORTA &= ~(1 << TRIGGER_PIN);
	_delay_us(2);

	// Set trigger pin high for 10 microseconds
	PORTA |= (1 << TRIGGER_PIN);
	_delay_us(10);
	PORTA &= ~(1 << TRIGGER_PIN);

	// Wait for echo pin to go high
	while (!(PIND & (1 << ECHO_PIN)))
		;

	// Start timer
	TCNT1 = 0;

	// Wait for echo pin to go low
	while (PIND & (1 << ECHO_PIN))
		;

	// Stop timer
	u16 pulse_duration = TCNT1;

	// Calculate distance
	u16 distance = (pulse_duration * 0.0343) / 2;

	return distance;
}

void print_dist_LCD(u16 distance)
{
	LCD_INIT_4bit();
	dtostrf(distance, 2, 2, string);/* distance to string */
	strcat(string, " cm   ");	/* Concat unit i.e.cm */
	LCD_send_string_4bit("Dist = ");
	LCD_send_string_4bit(string);
	_delay_ms(300);
}
