/*
 * oled.h
 *
 * Created: 16/10/2014 07:40:44
 *  Author: Suburban
 */ 

#ifndef OLED_H_
#define OLED_H_

#include "Utils/utils.h"

void oled_print_int(uint8_t, uint8_t, int32_t);
void oled_print_string(uint8_t, uint8_t, const char *);

void oled_init (void);

void BTN1_callback (void);
void BTN2_callback (void);
void BTN3_callback (void);

void oled_UI_init (void);

#endif /* OLED_H_ */