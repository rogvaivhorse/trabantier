/*
 * tasks.c
 *
 * Created: 15/07/2016 18:54:49
 *  Author: Suburban
 */ 

#include <asf.h>
#include "tasks.h"
#define P group_speed_measure[speed_measure_ID]

volatile uint32_t *p_sys_ticks;
opt_enc_type *p_group_opt_enc;
static speed_measure_type group_speed_measure [SPEED_MEASURE_COUNT];

void task_measure_speed (uint32_t speed_measure_ID) {
	
	P.newposition = abs(*p_group_opt_enc[speed_measure_ID].p_enc_steps);
	P.newtime = *p_sys_ticks;
	
	//speed = delta distance / delta time
	//P.speed = ((float)(P.newposition - P.oldposition) / ((float)(P.newtime - P.oldtime)));
	//P.speed = ((float)(P.newposition - P.oldposition) * 1000 / ((float)(P.newtime - P.oldtime)));
	P.speed = (P.newposition - P.oldposition) * 1000 / ((int32_t)(P.newtime - P.oldtime));
	/*
	printf ("\r"); printf_utoa (*p_sys_ticks);
	printf ("\t"); printf_ftoa (P.speed, 5);
	printf ("\t"); printf_itoa (P.newposition - P.oldposition);
	printf ("\t"); printf_utoa (P.newtime - P.oldtime);
	printf ("\n");
	*/
	P.oldposition = P.newposition;
	P.oldtime = P.newtime;
}

void task_measure_speed_init (	speed_measure_type **p_group_speed_measure, 
								opt_enc_type **p_temp_group_opt_enc, 
								volatile uint32_t **p_temp_sys_ticks) {
	*p_group_speed_measure = group_speed_measure;
	p_group_opt_enc = *p_temp_group_opt_enc;
	p_sys_ticks = *p_temp_sys_ticks;
	
	for (int32_t i = 0; i < SPEED_MEASURE_COUNT; i++) {
		group_speed_measure[i].oldposition = 0;
		group_speed_measure[i].oldtime = 0;
		group_speed_measure[i].speed = 0;
		
		group_speed_measure[i].function = task_measure_speed;
	}
}

void task_do_pid (void) {
	
}
