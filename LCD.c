//#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "LCD.h"
void LCD_send_command(unsigned char cmd)
{
	LCD_DATA_PORT = cmd;
	clearbit(LCD_control_PORT,RS);
	clearbit(LCD_control_PORT,RW);
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_ms(3);
}
void LCD_send_data(unsigned char data)
{
	LCD_DATA_PORT = data ;
	setbit(LCD_control_PORT,RS);
	clearbit(LCD_control_PORT,RW);
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_ms(1);
}
void LCD_INIT(void)
{
	LCD_DATA_DIR =0xff;
	setbit(LCD_control_DIR,EN);
	setbit(LCD_control_DIR,RS);
	setbit(LCD_control_DIR,RW);
	_delay_ms(20);
	LCD_send_command(0x38);// LCD in 8 bit mode 
	LCD_send_command(0x0C);// LCD DISPLY ON CURSER OFF 
	LCD_send_command(0x06);// LCD AUTO INCRMENT 
	LCD_send_command(0X01);// LCD CLEAR SCREAN 
	LCD_send_command(0X80);// HOME POSITION 
	
}
void LCD_send_string( char* str)
{
	int count =0;
	while(str[count]!=0)
	{
		LCD_send_data(str[count]);
		count++;
	}
}








void LCD_send_data_4bit(unsigned char data)
{
	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f) |(data & 0xf0);//send high nibble
	setbit(LCD_control_PORT,RS);
	clearbit(LCD_control_PORT,RW);
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_us(200);
	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f) |(data<<4);//send low nibble 
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_ms(1);
	
}
void LCD_send_command_4bit(unsigned char cmd)
{
	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f) |(cmd & 0xf0);//send high nibble
	clearbit(LCD_control_PORT,RS);
	clearbit(LCD_control_PORT,RW);
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_us(200);
	LCD_DATA_PORT = (LCD_DATA_PORT &0x0f) |(cmd<<4);//send low nibble
	setbit(LCD_control_PORT,EN);
	_delay_us(1);
	clearbit(LCD_control_PORT,EN);
	_delay_ms(1);
}

void LCD_INIT_4bit(void)
{
	LCD_DATA_DIR|= 0xf0;
	setbit(LCD_control_DIR,EN);
	setbit(LCD_control_DIR,RS);
	setbit(LCD_control_DIR,RW);
	LCD_send_command_4bit(0x02);// return home 
	LCD_send_command_4bit(0x28);// 2 line  and 4 bit mode
	LCD_send_command_4bit(0x0c);// display on 
	LCD_send_command_4bit(0x06);// auto increment 
	LCD_send_command_4bit(0x01);// clear screen 
	_delay_ms(20);
	
	
}
void LCD_send_string_4bit( char* str)
{
	int count =0;
	while(str[count]!=0)
	{
		LCD_send_data_4bit(str[count]);
		count++;
	}
}
