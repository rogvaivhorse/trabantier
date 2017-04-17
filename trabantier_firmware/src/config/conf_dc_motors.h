/*
 * conf_dc_motors.h
 *
 * Created: 31/10/2014 00:05:10
 *  Author: Suburban
 */ 

#ifndef CONF_DC_MOTORS_H_
#define CONF_DC_MOTORS_H_

#include "conf_tc.h"

//DC Motor Count
#define DC_MOTOR_COUNT 8
//Speed measurement units
#define SPEED_MEASURE_COUNT 8

//PWM Pins
#define PWM_0	PIN_PWM_10_A
#define PWM_1	PIN_PWM_10_B
#define PWM_2	PIN_PWM_00_A
#define PWM_3	PIN_PWM_00_B
#define PWM_4	PIN_PWM_01_A
#define PWM_5	PIN_PWM_01_B
#define PWM_6	PIN_PWM_02_A
#define PWM_7	PIN_PWM_02_B

//IO Direction Pins
#define IO_DIR_0	EXT4_PIN_3	//DC_Wheel1
#define IO_DIR_1	EXT4_PIN_4	//DC_Wheel2
#define IO_DIR_2	EXT2_PIN_10	//DC_Carriage1
#define IO_DIR_3	EXT2_PIN_15	//DC_Carriage2
#define IO_DIR_4	EXT4_PIN_13	//DC_Carriage3
#define IO_DIR_5	EXT4_PIN_14	//DC_Carriage4
#define IO_DIR_6	EXT3_PIN_9	//DC_Head1
#define IO_DIR_7	EXT4_PIN_10	//DC_Head2

enum dc_motor_name_order {
	Z1,
	X2,
	Y4,
	Z2,
	Y2,
	Y3,
	X1,
	Y1
};

#endif /* CONF_DC_MOTORS_H_ */