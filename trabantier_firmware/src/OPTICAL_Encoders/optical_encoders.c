/*
 * optical_encoders.c
 *
 * Created: 16/10/2014 15:57:33
 *  Author: Suburban
 */ 

#include <asf.h>
#include "optical_encoders.h"

volatile int32_t enc_0_steps = 0;
volatile int32_t enc_1_steps = 0;
volatile int32_t enc_2_steps = 0;
volatile int32_t enc_3_steps = 0;
volatile int32_t enc_4_steps = 0;
volatile int32_t enc_5_steps = 0;
volatile int32_t enc_6_steps = 0;
volatile int32_t enc_7_steps = 0;

static opt_enc_type opt_enc[OPT_Enc_Count];

void opt_enc_irq_callback_0 (void) {
	//printf("Called opt_enc_callback_0.\r\n");
	if (!ioport_get_pin_level (IO_ENC_0))
		enc_0_steps ++;
	else
		enc_0_steps --;
}
void opt_enc_irq_callback_1 (void) {
	//printf("Called opt_enc_callback_1.\r\n");
	if (!ioport_get_pin_level (IO_ENC_1))
		enc_1_steps ++;
	else
		enc_1_steps --;
}
void opt_enc_irq_callback_2 (void) {
	//printf("Called opt_enc_callback_2.\r\n");
	if (!ioport_get_pin_level (IO_ENC_2))
		enc_2_steps --; //++;
	else
		enc_2_steps ++; //--;
}
void opt_enc_irq_callback_3 (void) {
	//printf("Called opt_enc_callback_3.\r\n");
	if (!ioport_get_pin_level (IO_ENC_3))
		enc_3_steps --; //++;
	else
		enc_3_steps ++; //--;
}
void opt_enc_irq_callback_4 (void) {
	//printf("Called opt_enc_callback_4.\r\n");
	if (!ioport_get_pin_level (IO_ENC_4))
		enc_4_steps --; //++;
	else
		enc_4_steps ++; //--;
}
void opt_enc_irq_callback_5 (void) {
	//printf("Called opt_enc_callback_5.\r\n");
	if (!ioport_get_pin_level (IO_ENC_5))
		enc_5_steps --; //++;
	else
		enc_5_steps ++; //--;
}
void opt_enc_irq_callback_6 (void) {
	//printf("Called opt_enc_callback_6.\r\n");
	if (!ioport_get_pin_level (IO_ENC_6))
		enc_6_steps ++;
	else
		enc_6_steps --;
}
void opt_enc_irq_callback_7 (void) {
	//printf("Called opt_enc_callback_7.\r\n");
	if (!ioport_get_pin_level (IO_ENC_7))
		enc_7_steps ++;
	else
		enc_7_steps --;
}

void opt_enc_setup_IRQ_eic (uint32_t IRQ_ID) {
	ioport_set_pin_dir(opt_enc[IRQ_ID].IO_enc_A, IOPORT_DIR_INPUT);
	ioport_set_pin_level(opt_enc[IRQ_ID].IO_enc_A, IOPORT_PIN_LEVEL_LOW);
	ioport_set_pin_mode(opt_enc[IRQ_ID].IO_enc_A, IOPORT_MODE_PULLDOWN | IOPORT_MODE_GLITCH_FILTER);
	ioport_set_pin_sense_mode(opt_enc[IRQ_ID].IO_enc_A, IOPORT_SENSE_RISING);
	
	
	#ifndef DEBUG
		printf("Setup IRQ pin_");
		printf_itoa (IRQ_ID);
		printf("\r\n");
	#endif
}

void opt_enc_setup_IRQ_callback (uint32_t IRQ_ID) {
	
	if (!gpio_set_pin_callback(opt_enc[IRQ_ID].IO_enc_A, opt_enc[IRQ_ID].callback, 1)) {
		printf("Setup IRQ callback_");
		printf_itoa (IRQ_ID);
		printf(" failure!\r\n");
		while (1);
	}
	
	#ifndef DEBUG
		printf("Setup IRQ callback_");
		printf_itoa (IRQ_ID);
		printf(" successful!\r\n");
	#endif
}

void opt_enc_setup_IO_B_gpio (uint32_t IO_ChB_ID) {
	ioport_set_pin_dir(opt_enc[IO_ChB_ID].IO_enc_B, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(opt_enc[IO_ChB_ID].IO_enc_B, IOPORT_MODE_PULLDOWN | IOPORT_MODE_GLITCH_FILTER);
	//ioport_set_pin_level(opt_enc[IO_ChB_ID].IO_enc_B, IOPORT_PIN_LEVEL_LOW);
	
	#ifndef DEBUG
		printf("Setup IO channel B line_");
		printf_itoa (IO_ChB_ID);
		printf("\r\n");
	#endif
}
/* OBSOLETE
void opt_enc_setup_step_variables (	volatile int32_t **p_enc_0_steps, volatile int32_t **p_enc_1_steps, volatile int32_t **p_enc_2_steps, volatile int32_t **p_enc_3_steps, 
									volatile int32_t **p_enc_4_steps, volatile int32_t **p_enc_5_steps, volatile int32_t **p_enc_6_steps, volatile int32_t **p_enc_7_steps ) {
	
	//pointers to the local Encoder variables
	*p_enc_0_steps = &enc_0_steps; *p_enc_1_steps = &enc_1_steps; *p_enc_2_steps = &enc_2_steps; *p_enc_3_steps = &enc_3_steps;
	*p_enc_4_steps = &enc_4_steps; *p_enc_5_steps = &enc_5_steps; *p_enc_6_steps = &enc_6_steps; *p_enc_7_steps = &enc_7_steps;
	
	#ifndef DEBUG
		printf("All encoder pointers linked.\r\n");
	#endif
}
*/

void opt_enc_enable_IRQ (uint32_t IRQ_ID) {
	gpio_enable_pin_interrupt(opt_enc[IRQ_ID].IO_enc_A);
	
	
	#ifndef DEBUG
		printf("Enable IRQ callback_");
		printf_itoa (IRQ_ID);
		printf("\r\n");
	#endif
}

void opt_enc_disable_IRQ (uint32_t IRQ_ID) {
	gpio_disable_pin_interrupt(opt_enc[IRQ_ID].IO_enc_A);
	
	#ifndef DEBUG
		printf("Disable IRQ callback_");
		printf_itoa (IRQ_ID);
		printf("\r\n");
	#endif
}

void opt_enc_enable_IRQs (void) {
	for (uint32_t i = 0; i < OPT_Enc_Count; i++) 
		gpio_enable_pin_interrupt(opt_enc[i].IO_enc_A);
}

void opt_enc_disable_IRQs (void) {
	for (uint32_t i = 0; i < OPT_Enc_Count; i++)
		gpio_disable_pin_interrupt(opt_enc[i].IO_enc_A);
}

bool opt_enc_get_pin_level (uint32_t IO_ChB_ID) {
	return ioport_get_pin_level (opt_enc[IO_ChB_ID].IO_enc_B);
}

void opt_enc_init(opt_enc_type **p_group_opt_enc) {
	*p_group_opt_enc = opt_enc;	
	
	opt_enc[0].IO_enc_A = EIC_0;
	opt_enc[0].IO_enc_B = IO_ENC_0;
	opt_enc[0].p_enc_steps = &enc_0_steps;
	opt_enc[0].callback = opt_enc_irq_callback_0;
	
	opt_enc[1].IO_enc_A = EIC_1;
	opt_enc[1].IO_enc_B = IO_ENC_1;
	opt_enc[1].p_enc_steps = &enc_1_steps;
	opt_enc[1].callback = opt_enc_irq_callback_1;
	
	opt_enc[2].IO_enc_A = EIC_2;
	opt_enc[2].IO_enc_B = IO_ENC_2;
	opt_enc[2].p_enc_steps = &enc_2_steps;
	opt_enc[2].callback = opt_enc_irq_callback_2;
	
	opt_enc[3].IO_enc_A = EIC_3;
	opt_enc[3].IO_enc_B = IO_ENC_3;
	opt_enc[3].p_enc_steps = &enc_3_steps;
	opt_enc[3].callback = opt_enc_irq_callback_3;
	
	opt_enc[4].IO_enc_A = EIC_4;
	opt_enc[4].IO_enc_B = IO_ENC_4;
	opt_enc[4].p_enc_steps = &enc_4_steps;
	opt_enc[4].callback = opt_enc_irq_callback_4;
	
	opt_enc[5].IO_enc_A = EIC_5;
	opt_enc[5].IO_enc_B = IO_ENC_5;
	opt_enc[5].p_enc_steps = &enc_5_steps;
	opt_enc[5].callback = opt_enc_irq_callback_5;
	
	opt_enc[6].IO_enc_A = EIC_6;
	opt_enc[6].IO_enc_B = IO_ENC_6;
	opt_enc[6].p_enc_steps = &enc_6_steps;
	opt_enc[6].callback = opt_enc_irq_callback_6;
	
	opt_enc[7].IO_enc_A = EIC_7;
	opt_enc[7].IO_enc_B = IO_ENC_7;
	opt_enc[7].p_enc_steps = &enc_7_steps;
	opt_enc[7].callback = opt_enc_irq_callback_7;
	
	for (uint32_t i = 0; i < OPT_Enc_Count; i++)
		opt_enc_setup_IRQ_eic (i);
	
	#ifndef DEBUG
		printf("All EICs initialized.\r\n");
	#endif

	for (uint32_t i = 0; i < OPT_Enc_Count; i++)
		opt_enc_setup_IO_B_gpio (i);
	
	#ifndef DEBUG		
		printf("All I/O channel B lines setup.\r\n");
	#endif

	for (uint32_t i = 0; i < OPT_Enc_Count; i++)
		opt_enc_setup_IRQ_callback (i);
	
	#ifndef DEBUG		
		printf("All test callbacks initialized.\r\n");
	#endif
	
	for (uint32_t i = 0; i < OPT_Enc_Count; i++)
		opt_enc_disable_IRQ (i);
	
	#ifndef DEBUG
		printf("All IRQs disabled.\r\n");
	#endif
}