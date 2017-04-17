/*
 * timer_counter.h
 *
 * Created: 30/10/2014 10:34:40
 *  Author: Suburban
 */ 

#ifndef TIMER_COUNTER_H_
#define TIMER_COUNTER_H_

#include "conf_tc.h"
#include "Utils/utils.h"

void PWM_init(void);
void tc_pwm_init(Tc *, uint32_t);
void PWM_start (Tc *, uint32_t);
void PWM_stop (Tc *, uint32_t);

void PWM_set_RA (Tc *, uint32_t, uint32_t);
void PWM_set_RB (Tc *, uint32_t, uint32_t);
void PWM_set_RC (Tc *, uint32_t, uint32_t);

uint32_t PWM_get_RA (Tc *, uint32_t);
uint32_t PWM_get_RB (Tc *, uint32_t);
uint32_t PWM_get_RC (Tc *, uint32_t);
uint32_t PWM_get_RC_Value (void);

void PWM_print_state (Tc *, uint32_t);
void PWM_print_states (void);

void TC_periodic_IRQ_init (Tc *, uint32_t, IRQn_Type, uint32_t);

#endif /* TIMER_COUNTER_H_ */