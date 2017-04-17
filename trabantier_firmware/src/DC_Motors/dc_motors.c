/*
 * dc_motors.c
 *
 * Created: 16/10/2014 15:37:58
 *  Author: Suburban
 */ 

#include <asf.h>
#include "dc_motors.h"
#define P dc_motor[dc_motor_ID]

static dc_motor_type dc_motor[DC_MOTOR_COUNT];

void dc_motors_control_init (dc_motor_type **p_group_dc_motor) {
	PWM_init ();
	
	*p_group_dc_motor = dc_motor;	
	
	dc_motor[0].dir = IO_DIR_6;
	dc_motor[0].pwm = PWM_6;
	dc_motor[0].p_tc = TC0;
	dc_motor[0].reg = RA;
	dc_motor[0].channel = TC_CHANNEL_2;
	dc_motor[0].stop = dc_motor_stop;
	dc_motor[0].left = dc_motor_left;
	dc_motor[0].right = dc_motor_right;
	dc_motor[0].set_speed = dc_motor_set_speed;
	
	dc_motor[1].dir = IO_DIR_1;
	dc_motor[1].pwm = PWM_1;
	dc_motor[1].p_tc = TC1;
	dc_motor[1].reg = RB;
	dc_motor[1].channel = TC_CHANNEL_0;
	dc_motor[1].stop = dc_motor_stop;
	dc_motor[1].left = dc_motor_left;
	dc_motor[1].right = dc_motor_right;
	dc_motor[1].set_speed = dc_motor_set_speed;
	
	dc_motor[2].dir = IO_DIR_5;
	dc_motor[2].pwm = PWM_5;
	dc_motor[2].reg = RB;
	dc_motor[2].p_tc = TC0;
	dc_motor[2].channel = TC_CHANNEL_1;
	dc_motor[2].stop = dc_motor_stop;
	dc_motor[2].left = dc_motor_left;
	dc_motor[2].right = dc_motor_right;
	dc_motor[2].set_speed = dc_motor_set_speed;
	
	dc_motor[3].dir = IO_DIR_7;
	dc_motor[3].pwm = PWM_7;
	dc_motor[3].reg = RB;
	dc_motor[3].p_tc = TC0;
	dc_motor[3].channel = TC_CHANNEL_2;
	dc_motor[3].stop = dc_motor_stop;
	dc_motor[3].left = dc_motor_left;
	dc_motor[3].right = dc_motor_right;
	dc_motor[3].set_speed = dc_motor_set_speed;
	
	dc_motor[4].dir = IO_DIR_3;
	dc_motor[4].pwm = PWM_3;
	dc_motor[4].reg = RB;
	dc_motor[4].p_tc = TC0;
	dc_motor[4].channel = TC_CHANNEL_0;
	dc_motor[4].stop = dc_motor_stop;
	dc_motor[4].left = dc_motor_left;
	dc_motor[4].right = dc_motor_right;
	dc_motor[4].set_speed = dc_motor_set_speed;
	
	dc_motor[5].dir = IO_DIR_4;
	dc_motor[5].pwm = PWM_4;
	dc_motor[5].reg = RA;
	dc_motor[5].p_tc = TC0;
	dc_motor[5].channel = TC_CHANNEL_1;
	dc_motor[5].stop = dc_motor_stop;
	dc_motor[5].left = dc_motor_left;
	dc_motor[5].right = dc_motor_right;
	dc_motor[5].set_speed = dc_motor_set_speed;
	
	dc_motor[6].dir = IO_DIR_0;
	dc_motor[6].pwm = PWM_0;
	dc_motor[6].reg = RA;
	dc_motor[6].p_tc = TC1;
	dc_motor[6].channel = TC_CHANNEL_0;
	dc_motor[6].stop = dc_motor_stop;
	dc_motor[6].left = dc_motor_left;
	dc_motor[6].right = dc_motor_right;
	dc_motor[6].set_speed = dc_motor_set_speed;
	
	dc_motor[7].dir = IO_DIR_2;
	dc_motor[7].pwm = PWM_2;
	dc_motor[7].reg = RA;
	dc_motor[7].p_tc = TC0;
	dc_motor[7].channel = TC_CHANNEL_0;
	dc_motor[7].stop = dc_motor_stop;
	dc_motor[7].left = dc_motor_left;
	dc_motor[7].right = dc_motor_right;
	dc_motor[7].set_speed = dc_motor_set_speed;
	
	for (uint32_t i = 0; i < DC_MOTOR_COUNT; i++)
		dc_motor_control_init_by_ID (i);
	
	#ifndef DEBUG
		puts("-I- dc_motors_control_init done.\r");
	#endif
}

void dc_motor_control_init_by_ID (uint32_t dc_motor_ID) {
	ioport_set_pin_dir(P.dir, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(P.dir, IOPORT_PIN_LEVEL_LOW);
}

/*
void dc_motor_start (uint32_t dc_motor_ID) {
	//Sets pwm in Start mode
	//This starts 2 motors: one on RA line, one on RB line
	PWM_start(P.p_tc, P.channel);
}	*/

/*
void dc_motor_stop (uint32_t dc_motor_ID) {
	//Sets pwm in Stop mode
	//This stops 2 motors: one on RA line, one on RB line
	PWM_stop(P.p_tc, P.channel);
}	*/

void dc_motor_stop (uint32_t dc_motor_ID) {
	//Stops motor_id by setting it's speed to 0
	
	dc_motor_set_speed (dc_motor_ID, 0);
}

void dc_motor_left (uint32_t dc_motor_ID) {
	//Sets direction pin

	ioport_set_pin_level(P.dir, IOPORT_PIN_LEVEL_LOW);
}

void dc_motor_right (uint32_t dc_motor_ID) {
	//Sets direction pin

	ioport_set_pin_level(P.dir, IOPORT_PIN_LEVEL_HIGH);	
}

void dc_motor_set_speed (uint32_t dc_motor_ID, uint32_t pwm_thousandth_percent) {
	//Sets pwm values
	uint32_t pwm_value;
	
	if (pwm_thousandth_percent == 1000)
		pwm_value = 1;
	else
		pwm_value = (1000 - pwm_thousandth_percent) * PWM_get_RC_Value() / 1000;
	
	//if (!(dc_motor_ID % 2))
	if (P.reg == RA)
		PWM_set_RA (P.p_tc, P.channel, pwm_value);
	else
		PWM_set_RB (P.p_tc, P.channel, pwm_value);
}

void dc_motor_stop_all (void) {
	//Sets pwm values to 0
	uint32_t i = 0;
	uint32_t pwm_val = 0;

	for (i = 0; i < 4; i++) {
		dc_motor_left (i);
		dc_motor_right(i+4);
		dc_motor_set_speed (i, pwm_val);
		dc_motor_set_speed (i+4, pwm_val);
	}
}