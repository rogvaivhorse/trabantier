/*
 * board.c
 *
 * Created: 16/10/2014 16:08:06
 *  Author: Suburban
 */ 

#include <asf.h>
#include "board.h"

void configure_console(void) {
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits = CONF_UART_STOP_BITS,
	};
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

void sw0_callback (void) {
	
}

void board_UI_init (void) {
	ioport_set_pin_dir(SW0_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(SW0_PIN, IOPORT_MODE_PULLUP | IOPORT_MODE_GLITCH_FILTER);
	ioport_set_pin_sense_mode(SW0_PIN, IOPORT_SENSE_FALLING);
	
	if (!gpio_set_pin_callback(SW0_PIN, sw0_callback, 1)) {
		printf("Set pin callback failure!\r\n"); while (1) {}
	}
	
	gpio_enable_pin_interrupt(SW0_PIN);
	
	puts("-I- board_UI_init\r");
}

void board_print_gpio_mux (uint32_t base_no) {
	uint32_t i;
	uint32_t indx;
	volatile GpioPort *base;
	const char letters[8][9] = {"A\0"," B\0","  C\0","   D\0","    E\0","     F\0","      G\0","       H\0"};
	
	base = arch_ioport_port_to_base(base_no);
		
	printf ("BASE");
	printf_utoa (base_no);
	printf(": \r\n");
	printf ("GPIO_PMR0: ");
	printf_utoa (base->GPIO_PMR0);
	printf ("\r\n");
	printf ("GPIO_PMR1: ");
	printf_utoa (base->GPIO_PMR1);
	printf ("\r\n");
	printf ("GPIO_PMR2: ");
	printf_utoa (base->GPIO_PMR2);
	printf ("\r\n");
		
	for (i = 0; i < 32; i++) {
		if ((base->GPIO_PMR2>>i) & 1)
			indx = 1;
		else
			indx = 0;
		indx <<= 1;
		if ((base->GPIO_PMR1>>i) & 1)
			indx += 1;
		indx <<= 1;
		if ((base->GPIO_PMR0>>i) & 1)
			indx += 1;
			
		printf ("GPIO_PIN[");
		printf_utoa (i);
		printf ("] set: ");
		printf (letters[indx]);
		printf ("\r\n");
	}
	printf ("\r\n");
}

void board_print_gpio_muxes (void) {
	board_print_gpio_mux (0);
	board_print_gpio_mux (1);
	board_print_gpio_mux (2);
}

void board_print_clocks (void) {
	//main system clock print
	printf ("Main System Clock: ");
	printf_utoa (sysclk_get_main_hz());
	printf (" hz\r\n");

	//TC0 system clock print
	printf ("TC0 Clock:          ");
	printf_utoa (sysclk_get_peripheral_bus_hz(TC0) / 8);
	printf (" hz\r\n");
}
