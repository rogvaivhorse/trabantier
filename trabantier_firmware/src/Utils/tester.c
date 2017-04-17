/*
 * tester.c
 *
 * Created: 15/06/2016 02:41:41
 *  Author: Suburban
 */ 

#include <asf.h>
#include <modules.h>
#include "tester.h"


uint32_t tester_test_static (uint32_t m_state, uint32_t pwm_val) {
	
	switch (m_state) {
		case 0:
			//Start X1, X2 left
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
		
			opt_enc_disable_IRQ (0);
			opt_enc_disable_IRQ (3);// off Z
		
			opt_enc_enable_IRQ (6);
			opt_enc_enable_IRQ (1);
		
			dc_motor_left (0);
			dc_motor_left (1);
		
			dc_motor_set_speed (0, pwm_val);
			dc_motor_set_speed (1, pwm_val);
		
			m_state = 1;
			return m_state;
		break;
		case 1:
			//Start X1, X2 right
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
		
			opt_enc_disable_IRQ (6);
			opt_enc_disable_IRQ (1);// off X
		
			opt_enc_enable_IRQ (6);
			opt_enc_enable_IRQ (1);
		
			dc_motor_right (0);
			dc_motor_right (1);
		
			dc_motor_set_speed (0, pwm_val);
			dc_motor_set_speed (1, pwm_val);
		
			m_state = 2;
			return m_state;
		break;
		case 2:
			//Start Y1, Y2, Y3, Y4 left
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
		
			opt_enc_disable_IRQ (6);
			opt_enc_disable_IRQ (1);// off X
		
			opt_enc_enable_IRQ (7);
			opt_enc_enable_IRQ (4);
			opt_enc_enable_IRQ (5);
			opt_enc_enable_IRQ (2);
		
			dc_motor_left (2);
			dc_motor_left (3);
			dc_motor_left (4);
			dc_motor_left (5);
		
			dc_motor_set_speed (2, pwm_val);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 3;
			return m_state;
		break;
		case 3:
			//Start Y1, Y2, Y3, Y4 right
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			opt_enc_disable_IRQ (7);
			opt_enc_disable_IRQ (4);
			opt_enc_disable_IRQ (5);
			opt_enc_disable_IRQ (2);// off Y

			opt_enc_enable_IRQ (7);
			opt_enc_enable_IRQ (4);
			opt_enc_enable_IRQ (5);
			opt_enc_enable_IRQ (2);
		
			dc_motor_right (2);
			dc_motor_right (3);
			dc_motor_right (4);
			dc_motor_right (5);
		
			dc_motor_set_speed (2, pwm_val);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 4;
			return m_state;
		break;
		case 4:
			//Start Z1, Z2 left
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			opt_enc_disable_IRQ (7);
			opt_enc_disable_IRQ (4);
			opt_enc_disable_IRQ (5);
			opt_enc_disable_IRQ (2);// off Y
		
			opt_enc_enable_IRQ (0);
			opt_enc_enable_IRQ (3);
		
			dc_motor_left (6);
			dc_motor_left (7);
		
			dc_motor_set_speed (6, pwm_val);
			dc_motor_set_speed (7, pwm_val);
		
			m_state = 5;
			return m_state;
		break;
		case 5:
			//Start Z1, Z2 right
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
		
			opt_enc_disable_IRQ (0);
			opt_enc_disable_IRQ (3);// off Z

			opt_enc_enable_IRQ (0);
			opt_enc_enable_IRQ (3);
		
			dc_motor_right (6);
			dc_motor_right (7);
		
			dc_motor_set_speed (6, pwm_val);
			dc_motor_set_speed (7, pwm_val);

			m_state = 0;
			return m_state;
		break;
		case 6:
			//Start Y1, Y2, Y3, Y4 left -- Only Y test
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			//opt_enc_disable_IRQ (7);
			//opt_enc_disable_IRQ (4);
			//opt_enc_disable_IRQ (5);
			//opt_enc_disable_IRQ (2);	//off Y
			//opt_enc_enable_IRQ (7);
			//opt_enc_enable_IRQ (4);
			//opt_enc_enable_IRQ (5);
			//opt_enc_enable_IRQ (2);
		
			dc_motor_left (2);
			dc_motor_left (3);
			dc_motor_left (4);
			dc_motor_left (5);
		
			dc_motor_set_speed (2, pwm_val);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 7;
			return m_state;
		break;
		case 7:
			//Start Y1, Y2, Y3, Y4 right -- Only Y test
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			//opt_enc_disable_IRQ (7);
			//opt_enc_disable_IRQ (4);
			//opt_enc_disable_IRQ (5);
			//opt_enc_disable_IRQ (2);	//off Y
			//opt_enc_enable_IRQ (7);
			//opt_enc_enable_IRQ (4);
			//opt_enc_enable_IRQ (5);
			//opt_enc_enable_IRQ (2);
		
			dc_motor_right (2);
			dc_motor_right (3);
			dc_motor_right (4);
			dc_motor_right (5);
		
			dc_motor_set_speed (2, pwm_val);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 6;
			return m_state;
		break;
		case 8:
			//Start Z1, Z2 left -- Only Z test
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
		
			//opt_enc_disable_IRQ (0);
			//opt_enc_disable_IRQ (3);	//off Z
			//opt_enc_enable_IRQ (0);
			//opt_enc_enable_IRQ (3);
		
			dc_motor_left (6);
			dc_motor_left (7);
		
			dc_motor_set_speed (6, pwm_val);
			dc_motor_set_speed (7, pwm_val);
		
			m_state = 9;
			return m_state;
		break;
		case 9:
			//Start Z1, Z2 right -- Only Z test
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
		
			//opt_enc_disable_IRQ (0);
			//opt_enc_disable_IRQ (3);	//off Z
			//opt_enc_enable_IRQ (0);
			//opt_enc_enable_IRQ (3);
		
			dc_motor_right (6);
			dc_motor_right (7);
		
			dc_motor_set_speed (6, pwm_val);
			dc_motor_set_speed (7, pwm_val);

			m_state = 8;
			return m_state;
		break;
		case 10:
			//Start X1, X2 left -- Only X test
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
		
			//opt_enc_disable_IRQ (6);
			//opt_enc_disable_IRQ (1);	//off X
			//opt_enc_enable_IRQ (6);
			//opt_enc_enable_IRQ (1);
		
			dc_motor_left (0);
			dc_motor_left (1);
		
			dc_motor_set_speed (0, pwm_val - 200);
			dc_motor_set_speed (1, pwm_val);
		
			m_state = 11;
			return m_state;
		break;
		case 11:
			//Start X1, X2 right -- Only X test
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
		
			//opt_enc_disable_IRQ (6);
			//opt_enc_disable_IRQ (1);	//off X
			//opt_enc_enable_IRQ (6);
			//opt_enc_enable_IRQ (1);
		
			dc_motor_right (0);
			dc_motor_right (1);
		
			dc_motor_set_speed (0, pwm_val - 200);
			dc_motor_set_speed (1, pwm_val);
		
			m_state = 10;
			return m_state;
		break;
		case 12:
			//Start Y1, Y2 left -- Only bottom Y test
			dc_motor_set_speed (2, 0);	//stop Y1
			dc_motor_set_speed (3, 0);	//stop Y2
		
			//opt_enc_disable_IRQ (7);
			//opt_enc_disable_IRQ (4);	//encoder interrupt off for Y1, Y2
			//opt_enc_enable_IRQ (7);
			//opt_enc_enable_IRQ (4);	//encoder interrupt on for Y1, Y2
		
			dc_motor_left (2);
			dc_motor_left (3);
		
			dc_motor_set_speed (2, pwm_val - 100);
			dc_motor_set_speed (3, pwm_val);
		
			m_state = 13;
			return m_state;
		break;
		case 13:
			//Start Y1, Y2 right -- Only bottom Y test
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
		
			//opt_enc_disable_IRQ (7);
			//opt_enc_disable_IRQ (4);	//off Y
			//opt_enc_enable_IRQ (7);
			//opt_enc_enable_IRQ (4);
		
			dc_motor_right (2);
			dc_motor_right (3);
		
			dc_motor_set_speed (2, pwm_val - 100);
			dc_motor_set_speed (3, pwm_val);
		
			m_state = 12;
			return m_state;
		break;
		case 14:
			//Start Y3, Y4 left -- Only top Y test
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			//opt_enc_disable_IRQ (5);
			//opt_enc_disable_IRQ (2);	//off Y
			//opt_enc_enable_IRQ (5);
			//opt_enc_enable_IRQ (2);
		
			dc_motor_left (4);
			dc_motor_left (5);
		
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 15;
			return m_state;
		break;
		case 15:
			//Start Y3, Y4 right -- Only top Y test
			dc_motor_set_speed (4, 0);
			dc_motor_set_speed (5, 0);
		
			//opt_enc_disable_IRQ (5);
			//opt_enc_disable_IRQ (2);	//off Y
			//opt_enc_enable_IRQ (5);
			//opt_enc_enable_IRQ (2);
		
			dc_motor_right (4);
			dc_motor_right (5);
		
			dc_motor_set_speed (4, pwm_val);
			dc_motor_set_speed (5, pwm_val);
		
			m_state = 14;
			return m_state;
		break;
		case 16:
			//Start X1, X2, Y1, Y2, Z1, Z2 left
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
			
			dc_motor_left (0); //X1
			dc_motor_left (1); //X2
			dc_motor_left (2); //Y1
			dc_motor_left (3); //Y2
			dc_motor_left (6); //Z1
			dc_motor_left (7); //Z2
		
			dc_motor_set_speed (0, pwm_val - 100);
			dc_motor_set_speed (1, pwm_val);
			dc_motor_set_speed (2, pwm_val - 100);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (6, pwm_val);
			dc_motor_set_speed (7, pwm_val);
		
			m_state = 17;
			return m_state;
		break;
		case 17:
			//Start X1, X2, Y1, Y2, Z1, Z2 right
			dc_motor_set_speed (0, 0);
			dc_motor_set_speed (1, 0);
			dc_motor_set_speed (2, 0);
			dc_motor_set_speed (3, 0);
			dc_motor_set_speed (6, 0);
			dc_motor_set_speed (7, 0);
		
			dc_motor_right (0); //X1
			dc_motor_right (1); //X2
			dc_motor_right (2); //Y1
			dc_motor_right (3); //Y2
			dc_motor_right (6); //Z1
			dc_motor_right (7); //Z2
		
			dc_motor_set_speed (0, pwm_val);
			dc_motor_set_speed (1, pwm_val);
			dc_motor_set_speed (2, pwm_val - 100);
			dc_motor_set_speed (3, pwm_val);
			dc_motor_set_speed (6, pwm_val - 100);
			dc_motor_set_speed (7, pwm_val);
		
			m_state = 16;
			return m_state;
		break;
		case 18:
			//Start Y1, Y2 right -- Only bottom Y test
			dc_motor_set_speed (7, 0);
			dc_motor_set_speed (4, 0);
		
			dc_motor_left (7);
			dc_motor_left (4);
		
			dc_motor_set_speed (7, pwm_val - 100);
			dc_motor_set_speed (4, pwm_val);
			m_state = 19;
			return m_state;
		break;
		case 19:
			//Start Y1, Y2 right -- Only bottom Y test
			dc_motor_set_speed (7, 0);
			dc_motor_set_speed (4, 0);

			dc_motor_right (7);
			dc_motor_right (4);
			
			dc_motor_set_speed (7, pwm_val - 100);
			dc_motor_set_speed (4, pwm_val);
			m_state = 18;
			return m_state;
		break;
		case 20:
			dc_motor_stop (X1);
			dc_motor_stop (X2);
			
			dc_motor_left (X1);
			dc_motor_left (X2);
			
			dc_motor_set_speed (X1, pwm_val);
			dc_motor_set_speed (X2, pwm_val);
			m_state = 21;
			return m_state;
		break;
		case 21:
			dc_motor_stop (X1);
			dc_motor_stop (X2);
			
			dc_motor_right (X1);
			dc_motor_right (X2);
			
			dc_motor_set_speed (X1, pwm_val);
			dc_motor_set_speed (X2, pwm_val);
			m_state = 20;
			return m_state;
		break;
		default: break;
	}
	return 100;
}