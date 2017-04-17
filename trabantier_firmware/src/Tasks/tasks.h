/*
 * tasks.h
 *
 * Created: 15/07/2016 18:55:06
 *  Author: Suburban
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "conf_dc_motors.h"
#include "OPTICAL_Encoders/optical_encoders.h"
#include "Utils/utils.h"

typedef struct {
	int32_t		oldposition, newposition;
	uint32_t	oldtime, newtime;
	//float		speed;
	int32_t		speed;
	remote_function_uint_t function;
} speed_measure_type;

void task_measure_speed (uint32_t);
void task_measure_speed_init (speed_measure_type **, opt_enc_type **, volatile uint32_t **);

void task_do_pid (void);


#endif /* TASKS_H_ */