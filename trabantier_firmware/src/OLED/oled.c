/*
 * oled.c
 *
 * Created: 16/10/2014 15:17:26
 *  Author: Suburban
 */ 

#include <asf.h>
#include "oled.h"

void oled_print_int(uint8_t x, uint8_t y, int32_t int_number) {
	char string_number[12];
		
	itoa (int_number, string_number);
	ssd1306_set_page_address(x);
	ssd1306_set_column_address(y);
	ssd1306_write_text(string_number);
}

void oled_print_string(uint8_t x, uint8_t y, const char *print_string) {
	ssd1306_set_page_address(x);
	ssd1306_set_column_address(y);
	ssd1306_write_text(print_string);
}

void oled_init (void) {
	ioport_set_pin_dir(SSD1306_DC_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(SSD1306_RES_PIN, IOPORT_DIR_OUTPUT);
	
	ssd1306_init();
	
	ssd1306_clear();
	ssd1306_set_page_address(0);
	ssd1306_set_column_address(0);
	
	#ifndef DEBUG
		puts("-I- oled_init\r");
	#endif
}

void BTN1_callback (void) {
	LED_On(OLED_LED1_PIN);
	LED_Off(OLED_LED2_PIN);
	LED_Off(OLED_LED3_PIN);
	
	//dc_motors_left();
}

void BTN2_callback (void) {
	LED_Off(OLED_LED1_PIN);
	LED_On(OLED_LED2_PIN);
	LED_Off(OLED_LED3_PIN);
	
	//dc_motors_stop();
}

void BTN3_callback (void) {
	LED_Off(OLED_LED1_PIN);
	LED_Off(OLED_LED2_PIN);
	LED_On(OLED_LED3_PIN);
	
	//dc_motors_right();
}

void oled_UI_init (void) {
	ioport_set_pin_dir(OLED_LED1_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(OLED_LED2_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(OLED_LED3_PIN, IOPORT_DIR_OUTPUT);
	
	LED_Off(OLED_LED1_PIN);
	LED_Off(OLED_LED2_PIN);
	LED_Off(OLED_LED3_PIN);
	
	ioport_set_pin_dir(OLED_BTN1_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(OLED_BTN2_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(OLED_BTN3_PIN, IOPORT_DIR_INPUT);

	ioport_set_pin_mode(OLED_BTN1_PIN, IOPORT_MODE_PULLUP | IOPORT_MODE_GLITCH_FILTER);
	ioport_set_pin_mode(OLED_BTN2_PIN, IOPORT_MODE_PULLUP | IOPORT_MODE_GLITCH_FILTER);
	ioport_set_pin_mode(OLED_BTN3_PIN, IOPORT_MODE_PULLUP | IOPORT_MODE_GLITCH_FILTER);
	
	ioport_set_pin_sense_mode(OLED_BTN1_PIN, IOPORT_SENSE_FALLING);
	ioport_set_pin_sense_mode(OLED_BTN2_PIN, IOPORT_SENSE_FALLING);
	ioport_set_pin_sense_mode(OLED_BTN3_PIN, IOPORT_SENSE_FALLING);
	
	if (!gpio_set_pin_callback(OLED_BTN1_PIN, BTN1_callback, 1)) {
		printf("Set pin BTN1_callback failure!\r\n"); while (1) {}
	}
	if (!gpio_set_pin_callback(OLED_BTN2_PIN, BTN2_callback, 1)) {
		printf("Set pin BTN2_callback failure!\r\n"); while (1) {}
	}
	if (!gpio_set_pin_callback(OLED_BTN3_PIN, BTN3_callback, 1)) {
		printf("Set pin BTN3_callback failure!\r\n"); while (1) {}
	}
	
	gpio_enable_pin_interrupt(OLED_BTN1_PIN);
	gpio_enable_pin_interrupt(OLED_BTN2_PIN);
	gpio_enable_pin_interrupt(OLED_BTN3_PIN);
	
	
	#ifndef DEBUG
		puts("-I- oled_UI_init\r");
	#endif
}


