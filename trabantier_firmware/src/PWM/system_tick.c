/*
 * system_tick.c
 *
 * Created: 13/07/2016 18:42:05
 *  Author: Suburban
 */ 

#include <asf.h>
#include "system_tick.h"

//#define TICK_FREQ 5				//5Hz
//#define TICK_FREQ 10				//10Hz
//#define TICK_FREQ 500				//500Hz
//#define TICK_FREQ 1000			//1KHz
//#define TICK_FREQ 1200			//1.2KHz <<
//#define TICK_FREQ 2400			//2.4KHz <<
//#define TICK_FREQ 5000			//5KHz
#define TICK_FREQ 6000			//6KHz <<
//#define TICK_FREQ 10000			//10KHz
//#define TICK_FREQ 12000			//12KHz <<
//#define TICK_FREQ 60000			//60KHz <<
//#define TICK_FREQ 100000			//100KHz
//#define TICK_FREQ 120000			//120KHz <<
//#define TICK_FREQ 1000000			//1MHz
//#define TICK_FREQ 5000000			//5MHz
//#define TICK_FREQ 10000000		//10MHz
//#define TICK_FREQ 47972352		//48MHz (max)

volatile uint32_t sys_ticks = 0;

void system_tick_start (volatile uint32_t **p_sys_ticks) {
	uint32_t ticks = 0;
	
	//@48MHz & ticks = 0x00FFFFFF ==> 3.3Hz
	//sysclk_get_cpu_hz = 47972352 = 0x02DC0000
	ticks = sysclk_get_cpu_hz() / TICK_FREQ;
	*p_sys_ticks = &sys_ticks;
	
	//SysTick 24-bit count-down timer
	if (SysTick_Config(ticks)) {
		puts("SysTick_Config FAILED\r");
		while (1);  // Capture error
	}
	
	#ifndef DEBUG
		printf("-I- system_tick started --> @");
		printf_utoa(TICK_FREQ);
		puts(" Hz\r");
	#endif
}

void SysTick_Handler(void) {
	sys_ticks++;
}