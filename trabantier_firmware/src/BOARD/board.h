/*
 * board.h
 *
 * Created: 16/10/2014 16:08:18
 *  Author: Suburban
 */ 

#ifndef BOARD_H_
#define BOARD_H_

#include "Utils/utils.h"

void configure_console (void);
void sw0_callback (void);
void board_UI_init (void);
void board_print_gpio_mux (uint32_t);
void board_print_gpio_muxes (void);
void board_print_clocks (void);

#endif /* BOARD_H_ */