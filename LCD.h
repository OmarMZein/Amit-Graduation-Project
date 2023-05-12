/*
 * LCD.h
 *
 * Created: 12/23/2022 8:19:38 PM
 *  Author: AMIT
 */ 


#ifndef LCD_H_
#define LCD_H_
#define RS 1
#define RW 2
#define EN 3
#define LCD_DATA_DIR DDRA
#define LCD_control_DIR DDRB 
#define LCD_DATA_PORT PORTA
#define LCD_control_PORT PORTB


void LCD_INIT(void);
void LCD_send_data(unsigned char data);
void LCD_send_command(unsigned char cmd);
void LCD_send_string( char* str);
void LCD_INIT_4bit(void);
void LCD_send_data_4bit(unsigned char data);
void LCD_send_command_4bit(unsigned char cmd);
void LCD_send_string_4bit( char* str);




#endif /* LCD_H_ */
