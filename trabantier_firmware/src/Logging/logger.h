/*
 * logger.h
 *
 * Created: 15/06/2016 02:12:43
 *  Author: Suburban
 */ 

#ifndef LOGGER_H_
#define LOGGER_H_

#include "Utils/utils.h"

void logger_start (void);
void logger_log (int32_t);
void logger_end_entry (void);

void logger_log_n2 (int32_t, int32_t);
void logger_log_xyy (int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
void logger_log_xyyz (int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);

#endif /* LOGGER_H_ */