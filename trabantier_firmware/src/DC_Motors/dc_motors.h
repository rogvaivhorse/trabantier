/*
 * dc_motors.h
 *
 * Created: 16/10/2014 15:38:08
 *  Author: Suburban
 */ 

#ifndef DC_MOTORS_H_
#define DC_MOTORS_H_

#include "conf_dc_motors.h"
#include "PWM/timer_counter.h"

enum tc_compare_register {
	RA, 
	RB
};

typedef struct {
	uint32_t    dir;
	uint32_t    pwm;
	enum tc_compare_register reg;
	Tc		*p_tc;
	uint32_t channel;
	remote_function_uint_t stop;
	remote_function_uint_t left;
	remote_function_uint_t right;
	remote_function_uint_uint_t set_speed;
} dc_motor_type;

void dc_motors_control_init (dc_motor_type **);
void dc_motor_control_init_by_ID (uint32_t);

//void dc_motor_start (uint32_t);
void dc_motor_stop (uint32_t);
void dc_motor_left (uint32_t);
void dc_motor_right (uint32_t);

void dc_motor_set_speed (uint32_t, uint32_t);
void dc_motor_stop_all (void);

#endif /* DC_MOTORS_H_ */