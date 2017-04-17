/*
 *	3D Printer Motor Control
 */
 
#include <asf.h>
#include <modules.h>

#define STRING_HEADER \
	"\r\n-- 3D Printer Motor Control --\r\n" \
	"-- " BOARD_NAME " --\r\n" \
	"-- Compiled: "__DATE__" "__TIME__" --\r"

int main (void) {
	
	sysclk_init();
	board_init();
	ioport_init();
	oled_init ();
	
	configure_console();
	#ifndef DEBUG
		puts(STRING_HEADER);
	#endif

	LED_On(LED_0_PIN);
	
	volatile uint32_t *p_sys_ticks = NULL;
	
	dc_motor_type *p_group_dc_motor = NULL;
	opt_enc_type *p_group_opt_enc = NULL;
	speed_measure_type *p_group_speed_measure = NULL;
	
	//optical encoders and interrupts
	opt_enc_init (&p_group_opt_enc);
	
	//dc motor controls and pwm init
	dc_motors_control_init (&p_group_dc_motor);
	
	//system timing
	system_tick_start (&p_sys_ticks);
	
	//speed measurement task
	task_measure_speed_init (&p_group_speed_measure, &p_group_opt_enc, &p_sys_ticks);
	
	#ifndef DEBUG
		puts("-I- Inits done.\r\n");
		puts("==== CPU Clock ====\r");
		printf_utoa (sysclk_get_cpu_hz());
		puts(" Hz\r\n");
		puts("-------I'm not dead!!!-------\r\n");
	#endif
	LED_Off(LED_0_PIN);
	
	//stop all motors
	dc_motor_stop_all ();

	LED_On(LED_0_PIN);
	delay_ms (1000);
	opt_enc_enable_IRQs();
	LED_Off(LED_0_PIN);
	
	uint32_t m_state = 200;
	
	uint32_t temp_sys_ticks = 0;
	*p_sys_ticks = 0;

	while (1) {
		temp_sys_ticks = *p_sys_ticks;
		
		printf_itoa (p_group_speed_measure[Y1].speed); printf(",");
		printf_itoa (p_group_speed_measure[Y2].speed); printf(",");
		printf_itoa (0); printf(",");
		printf_itoa (p_group_speed_measure[X1].speed); printf(",");
		printf_itoa (p_group_speed_measure[X2].speed); printf(",");
		printf_itoa (0); printf("\r");

		if ( !(temp_sys_ticks % 1200)) {
			//puts (" + second/1------------\r");
			m_state = tester_test_static (m_state, 500); // m_state, pwm_val
		}
 
		if ( !(temp_sys_ticks % 600)) {
			//puts (" + second/2------\r");
		}

		if ( !(temp_sys_ticks % 400)) {
			//puts (" + second/3----\r");
		}
		
		if ( !(temp_sys_ticks % 200)) {
			//puts (" + second/6----\r");

			for (int32_t i = 0; i < SPEED_MEASURE_COUNT; i++) {
				p_group_speed_measure[i].function(i);
			}
		}
	}

	/*
	//RUN TEST and DISPLAY on OLED SCREEN
	while (1) {
		
		oled_print_string (0, 0, "X1:");
		oled_print_int (0, 6*3, *p_enc_6_steps);
		oled_print_string (0, 6*11, "X2:");
		oled_print_int (0, 6*14, *p_enc_1_steps);
		
		oled_print_string (1, 0, "Y1: ");
		oled_print_int (1, 6*3, *p_enc_7_steps);
		oled_print_string (1, 6*11, "Y2: ");
		oled_print_int (1, 6*14, *p_enc_4_steps);
		
		oled_print_string (2, 0, "Y3: ");
		oled_print_int (2, 6*3, *p_enc_5_steps);
		oled_print_string (2, 6*11, "Y4: ");
		oled_print_int (2, 6*14, *p_enc_2_steps);
		
		oled_print_string (3, 0, "Z1: ");
		oled_print_int (3, 6*3, *p_enc_0_steps);
		oled_print_string (3, 6*11, "Z2: ");
		oled_print_int (3, 6*14, *p_enc_3_steps);
		
		if (time_counter >= 100)
			time_counter = 0;
		time_counter++;

		if (!(time_counter % 10))
			tester_test_static (m_state, 450); // m_state, pwm_val

		delay_ms (10);
		ssd1306_clear();
	}	
	*/
}
