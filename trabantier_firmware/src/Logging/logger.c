/*
 * logger.c
 *
 * Created: 15/06/2016 02:12:31
 *  Author: Suburban
 */ 

#include <asf.h>
#include "logger.h"

void logger_start (void) {
	puts("-I- Logger Started\r\n");
}

void logger_log (int32_t int_number) {
	char string_number[12];
	
	itoa (int_number, string_number);
	printf(string_number);
	//puts (string_number);
}

void logger_end_entry (void) {
	printf("\r");
	//puts ("\r");
}

void logger_log_n2 (int32_t n1, int32_t n2) {
	
	//N1 && N2
	logger_log (n1); printf(",");
	logger_log (n2); printf(",");
	logger_log (0);
	logger_end_entry ();
}

void logger_log_xyy (	int32_t n1, int32_t n2, 
						int32_t n3, int32_t n4, 
						int32_t n5, int32_t n6) {
	
	//X1 && X2
	logger_log (n1); printf(",");
	logger_log (n2); printf(",");
	logger_log (0); printf(",");
	
	//Y1 && Y2 (bottom)
	logger_log (n3); printf(",");
	logger_log (n4); printf(",");
	logger_log (0); printf(",");
	
	//Y3 && Y4 (top)
	logger_log (n5); printf(",");
	logger_log (n6); printf(",");
	logger_log (0);
	logger_end_entry ();
	
}

void logger_log_xyyz (	int32_t n1, int32_t n2,
						int32_t n3, int32_t n4,
						int32_t n5, int32_t n6,
						int32_t n7, int32_t n8) {
	
	//X1 && X2
	logger_log (n1); printf(",");
	logger_log (n2); printf(",");
	logger_log (0); printf(",");
	
	//Y1 && Y2 (bottom) && Z1
	logger_log (n3); printf(",");
	logger_log (n4); printf(",");
	logger_log (n7); printf(",");
	
	//Y3 && Y4 (top) && Z2
	logger_log (n5); printf(",");
	logger_log (n6); printf(",");
	logger_log (n8);
	logger_end_entry ();
	
}

