/*
 * utils.c
 *
 * Created: 15/06/2016 02:15:22
 *  Author: Suburban
 */ 

#include <asf.h>
#include "utils.h"

int32_t len (char s[]) {
	int32_t i = 0;
	
	while (s[++i] != '\0');

	return i;
}

int32_t itoa(int32_t n, char s[]) {
	int i, j, sign;
	char c;
	
	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
		
	if (sign < 0)
	s[i++] = '-';
	s[i] = '\0';
	
	j = i - 1;
	for (i = 0; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		}

	return i;
}

int32_t utoa(uint32_t n, char s[]) {
	int i, j;
	char c;
		
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */

	s[i] = '\0';
			
	j = i - 1;
	for (i = 0; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		}

	return i;
}

int32_t ftoa(float n, char s[], int32_t afterpoint) {
	int32_t i, j;

	int32_t ipart = (int32_t)n;			//Extract integer part	

	itoa(ipart, s);
	i = len (s);

	(n < 0) ? (n = -n):(n = n);
	(ipart < 0) ? (ipart = -ipart):(ipart = ipart);

	float fpart = n - (float)ipart;		//Extract floating part

	if (afterpoint != 0) {
		s[i] = '.';
		
		afterpoint += i;
		for (j = i; j < afterpoint; j++) {
			fpart *= 10;
			if ((int32_t)fpart == 0 && j < afterpoint) {
				s[j+1] = '0';
				i++;
			}
		}

		itoa(fpart, s + i + 1);
	}
	
	return i;
}

void printf_itoa (int32_t int_number) {
	char string_number[12];

	itoa (int_number, string_number);
	printf(string_number);
}

void printf_utoa (uint32_t uint_number) {
	char string_number[12];

	utoa (uint_number, string_number);
	printf(string_number);
}

void printf_ftoa (float float_number, int32_t precision) {
	char string_number[20];

	ftoa (float_number, string_number, precision);
	printf(string_number);
}
