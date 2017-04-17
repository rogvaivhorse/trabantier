/*
 * timer_counter.c
 *
 * Created: 30/10/2014 10:34:19
 *  Author: Suburban
 */ 

#include <asf.h>
#include "timer_counter.h"

static uint32_t RC_Value;

void PWM_init(void) {
	
	sysclk_enable_peripheral_clock(TC0);
	sysclk_enable_peripheral_clock(TC1);
	
	//TC 0 Channel 0
	ioport_set_pin_mode(PIN_PWM_00_A, PIN_PWM_00_A_M);
	ioport_disable_pin(PIN_PWM_00_A);
	
	ioport_set_pin_mode(PIN_PWM_00_B, PIN_PWM_00_B_M);
	ioport_disable_pin(PIN_PWM_00_B);
	
	//TC 0 Channel 1
	ioport_set_pin_mode(PIN_PWM_01_A, PIN_PWM_01_A_M);
	ioport_disable_pin(PIN_PWM_01_A);
	
	ioport_set_pin_mode(PIN_PWM_01_B, PIN_PWM_01_B_M);
	ioport_disable_pin(PIN_PWM_01_B);
	
	//TC 0 Channel 2
	ioport_set_pin_mode(PIN_PWM_02_A, PIN_PWM_02_A_M);
	ioport_disable_pin(PIN_PWM_02_A);
	
	ioport_set_pin_mode(PIN_PWM_02_B, PIN_PWM_02_B_M);
	ioport_disable_pin(PIN_PWM_02_B);
	
	//TC 1 Channel 0
	ioport_set_pin_mode(PIN_PWM_10_A, PIN_PWM_10_A_M);
	ioport_disable_pin(PIN_PWM_10_A);
	
	ioport_set_pin_mode(PIN_PWM_10_B, PIN_PWM_10_B_M);
	ioport_disable_pin(PIN_PWM_10_B);
	
	/* UNUSED
	//TC 1 Channel 1
	ioport_set_pin_mode(PIN_PWM_11_A, PIN_PWM_11_A_M);
	ioport_disable_pin(PIN_PWM_11_A);
		
	ioport_set_pin_mode(PIN_PWM_11_B, PIN_PWM_11_B_M);
	ioport_disable_pin(PIN_PWM_11_B);
	
	//TC 1 Channel 2
	ioport_set_pin_mode(PIN_PWM_12_A, PIN_PWM_12_A_M);
	ioport_disable_pin(PIN_PWM_12_A);
		
	ioport_set_pin_mode(PIN_PWM_12_B, PIN_PWM_12_B_M);
	ioport_disable_pin(PIN_PWM_12_B);
	*/
	
	tc_pwm_init(TC0, TC_CHANNEL_0);
	tc_pwm_init(TC0, TC_CHANNEL_1);
	tc_pwm_init(TC0, TC_CHANNEL_2);
	tc_pwm_init(TC1, TC_CHANNEL_0);
	//tc_pwm_init(TC1, TC_CHANNEL_1);
	//tc_pwm_init(TC1, TC_CHANNEL_2);
	
	PWM_start(TC0, TC_CHANNEL_0);
	PWM_start(TC0, TC_CHANNEL_1);
	PWM_start(TC0, TC_CHANNEL_2);
	PWM_start(TC1, TC_CHANNEL_0);
	//PWM_start(TC1, TC_CHANNEL_1);
	//PWM_start(TC1, TC_CHANNEL_2);
	
	RC_Value = PWM_get_RC (TC0, TC_CHANNEL_0);
}

void tc_pwm_init(Tc *p_tc, uint32_t ul_channel) {
	uint32_t ra, rc;

	// Init TC to waveform mode.
	tc_init(p_tc, ul_channel,
				TC_PWM_TIMER_SELECTION			 // Waveform Clock Selection
						| TC_CMR_WAVE			 // Waveform mode is enabled
						| TC_CMR_WAVSEL_UP_AUTO	 // UP mode with automatic trigger on RC Compare
						| TC_CMR_ACPA_SET		 // RA Compare Effect: set
						| TC_CMR_ACPC_CLEAR		 // RC Compare Effect: clear
						| TC_CMR_BCPB_SET		 // RB Compare Effect: set
						| TC_CMR_BCPC_CLEAR		 // RC Compare Effect: clear
						| TC_CMR_EEVT_XC0_OUTPUT //if this isn't set, TIOB is by default an input
	);
	
	// Configure waveform frequency and duty cycle.
	rc = (sysclk_get_peripheral_bus_hz(p_tc) /		//48Mhz
					TC_PWM_DIVISOR /
					TC_PWM_FREQUENCY);
			
	tc_write_rc(p_tc, ul_channel, rc);
	
	ra = (100 - TC_PWM_DUTY_CYCLE) * rc / 100;
	
	tc_write_ra(p_tc, ul_channel, ra);
	tc_write_rb(p_tc, ul_channel, ra);
}

void PWM_start (Tc *p_tc, uint32_t ul_channel) {
	tc_start(p_tc, ul_channel);
}

void PWM_stop (Tc *p_tc, uint32_t ul_channel) {
	tc_stop(p_tc, ul_channel);
}

void PWM_set_RA (Tc *p_tc, uint32_t ul_channel, uint32_t ra) {
	tc_write_ra(p_tc, ul_channel, ra);
}

void PWM_set_RB (Tc *p_tc, uint32_t ul_channel, uint32_t rb) {
	tc_write_rb(p_tc, ul_channel, rb);
}

void PWM_set_RC (Tc *p_tc, uint32_t ul_channel, uint32_t rc) {
	tc_write_rc(p_tc, ul_channel, rc);
}

uint32_t PWM_get_RA (Tc *p_tc, uint32_t ul_channel) {
	return tc_read_ra(p_tc, ul_channel);
}

uint32_t PWM_get_RB (Tc *p_tc, uint32_t ul_channel) {
	return tc_read_rb(p_tc, ul_channel);
}

uint32_t PWM_get_RC (Tc *p_tc, uint32_t ul_channel) {
	return tc_read_rc(p_tc, ul_channel);	
}

uint32_t PWM_get_RC_Value (void) {
	return RC_Value;
}

void PWM_print_state (Tc *p_tc, uint32_t ul_channel) {
	char string_number[12];
	
	itoa (PWM_get_RA(p_tc, ul_channel), string_number);
	printf ("RA: ");
	printf (string_number);
	printf ("\r\n");
	
	itoa (PWM_get_RB(p_tc, ul_channel), string_number);
	printf ("RB: ");
	printf (string_number);
	printf ("\r\n");
	
	itoa (PWM_get_RC(p_tc, ul_channel), string_number);
	printf ("RC: ");
	printf (string_number);
	printf ("\r\n");
	printf ("\r\n");
}

void PWM_print_states (void) {
	puts ("TC0, Channel 0 setup:");
	PWM_print_state (TC0, TC_CHANNEL_0);
	puts ("TC0, Channel 1 setup:");
	PWM_print_state (TC0, TC_CHANNEL_1);
	puts ("TC0, Channel 2 setup:");
	PWM_print_state (TC0, TC_CHANNEL_2);
	puts ("TC1, Channel 0 setup:");
	PWM_print_state (TC1, TC_CHANNEL_0);
	puts ("TC1, Channel 1 setup:");
	PWM_print_state (TC1, TC_CHANNEL_1);
	puts ("TC1, Channel 2 setup:");
	PWM_print_state (TC1, TC_CHANNEL_2);
}

	
// Use as:
//	TC_periodic_IRQ_init (TC1, TC_CHANNEL_1, TC11_IRQn, 2);
//	TC_periodic_IRQ_init (TC1, TC_CHANNEL_2, TC12_IRQn, 2);
void TC_periodic_IRQ_init (Tc *p_tc, uint32_t ul_channel, IRQn_Type IRQn, uint32_t priority) {
	uint32_t ra, rc;

	// Init TC to waveform mode.
	tc_init (p_tc, ul_channel,
				TC_CMR_TCCLKS_TIMER_CLOCK5		 // Waveform Clock Selection
						| TC_CMR_WAVE			 // Waveform mode is enabled
						| TC_CMR_WAVSEL_UP_AUTO	 // UP mode with automatic trigger on RC Compare
	);
	
	// Enable interrupt
	tc_enable_interrupt (p_tc, ul_channel, TC_IER_CPCS); //TC_IER_ CPAS, CPBS, CPCS
	
	// Enable NVIC 
	irq_initialize_vectors();
	irq_register_handler(IRQn, priority);

	ra = 0x0000FFFF;
	rc = 0x0000FFFF;
	tc_write_ra (p_tc, ul_channel, ra);
	tc_write_rc (p_tc, ul_channel, rc);

	//start counting
	tc_start (p_tc, ul_channel);
}

void TC11_Handler (void) {
	puts("-8-\r");
	//LED_Toggle(LED_0_PIN);
}

void TC12_Handler (void) {
	puts("-9-\r");
	//LED_Toggle(LED_0_PIN);
}