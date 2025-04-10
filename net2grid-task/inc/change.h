#ifndef CHANGE_H
#define CHANGE_H
#include "stdint.h"

void change_uint8(void *data, void *new_value);
void change_int8(void *data, void *new_value);
void change_uint16(void *data, void *new_value);
void change_int16(void *data, void *new_value);
void change_uint32(void *data, void *new_value);
void change_int32(void *data, void *new_value);
void change_uint64(void *data, void *new_value);
void change_int64(void *data, void *new_value);
void change_float(void *data, void *new_value);
void change_double(void *data, void *new_value);
void change_char(void *data, void *new_value);

typedef void (*change_data_func_t)(void *data, void *new_value);

extern change_data_func_t change_functions[];

#endif
