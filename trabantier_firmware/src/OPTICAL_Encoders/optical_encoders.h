/*
 * optical_encoders.h
 *
 * Created: 16/10/2014 15:57:48
 *  Author: Suburban
 */

#ifndef OPTICAL_ENCODERS_H_
#define OPTICAL_ENCODERS_H_

#include "Utils/utils.h"

//volatile int32_t *p_enc_0_steps = NULL;
//volatile int32_t *p_enc_1_steps = NULL;
//volatile int32_t *p_enc_2_steps = NULL;
//volatile int32_t *p_enc_3_steps = NULL;
//volatile int32_t *p_enc_4_steps = NULL;
//volatile int32_t *p_enc_5_steps = NULL;
//volatile int32_t *p_enc_6_steps = NULL;
//volatile int32_t *p_enc_7_steps = NULL;

//opt_enc_enable_IRQ (6);	//x1	IO_DIR_0	//DC_Wheel1		//id 0
//opt_enc_enable_IRQ (1);	//x2	IO_DIR_1	//DC_Wheel2		//id 1 //callback inversed
//opt_enc_enable_IRQ (7);	//y1	IO_DIR_2	//DC_Carriage1	//id 2
//opt_enc_enable_IRQ (4);	//y2	IO_DIR_3	//DC_Carriage2	//id 3 //callback inversed
//opt_enc_enable_IRQ (5);	//y3	IO_DIR_4	//DC_Carriage3	//id 4
//opt_enc_enable_IRQ (2);	//y4	IO_DIR_5	//DC_Carriage4	//id 5 //callback inversed
//opt_enc_enable_IRQ (0);	//z1	IO_DIR_6	//DC_Head1		//id 6
//opt_enc_enable_IRQ (3);	//z2	IO_DIR_7	//DC_Head2		//id 7 //callback inversed

typedef struct {
	uint32_t    IO_enc_A;
	uint32_t    IO_enc_B;
	volatile int32_t *p_enc_steps;
	gpio_pin_callback_t callback;
} opt_enc_type;

void opt_enc_irq_callback_0 (void);
void opt_enc_irq_callback_1 (void);
void opt_enc_irq_callback_2 (void);
void opt_enc_irq_callback_3 (void);
void opt_enc_irq_callback_4 (void);
void opt_enc_irq_callback_5 (void);
void opt_enc_irq_callback_6 (void);
void opt_enc_irq_callback_7 (void);

void opt_enc_setup_IRQ_eic (uint32_t IRQ_ID);
void opt_enc_setup_IRQ_callback (uint32_t IRQ_ID);

void opt_enc_setup_IO_B_gpio (uint32_t IO_ChB_ID);
//void opt_enc_setup_step_variables (	volatile int32_t **, volatile int32_t **, volatile int32_t **, volatile int32_t **, 
//									volatile int32_t **, volatile int32_t **, volatile int32_t **, volatile int32_t **);

void opt_enc_enable_IRQ (uint32_t IRQ_ID);
void opt_enc_disable_IRQ (uint32_t IRQ_ID);
void opt_enc_enable_IRQs (void);
void opt_enc_disable_IRQs (void);

bool opt_enc_get_pin_level (uint32_t IO_ChB_ID);

void opt_enc_init(opt_enc_type **);

#endif /* OPTICAL_ENCODERS_H_ */