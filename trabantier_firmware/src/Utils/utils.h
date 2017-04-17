/*
 * utils.h
 *
 * Created: 15/06/2016 02:15:12
 *  Author: Suburban
 */ 


#ifndef UTILS_H_
#define UTILS_H_

typedef void (*remote_function_t)(void);
typedef void (*remote_function_int_t)(int32_t);
typedef void (*remote_function_uint_t)(uint32_t);
typedef void (*remote_function_uint_uint_t)(uint32_t, uint32_t);
typedef void (*remote_function_float_t)(float);

int32_t len (char *);

int32_t itoa(int32_t, char *);
int32_t utoa(uint32_t, char *);
int32_t ftoa(float, char *, int32_t);

void printf_itoa (int32_t);
void printf_utoa (uint32_t);
void printf_ftoa (float, int32_t);

#endif /* UTILS_H_ */