#ifndef PRINT_H
#define PRINT_H

#include "stdio.h"
#include <inttypes.h>

#define NUM_PRINT_FUNCTIONS 11


/**
 * @brief Prints the value of a datatype type.
 *
 * This function takes a pointer to a void * data variable of custom data tupe and prints its value to the standard output.
 *
 * @param data A pointer to the value to be printed.
 * @return void This function does not return a value.
 */
void print_uint8(void *data);
void print_int8(void *data);
void print_uint16(void *data);
void print_int16(void *data);
void print_uint32(void *data);
void print_int32(void *data);
void print_uint64(void *data);
void print_int64(void *data);
void print_float(void *data);
void print_double(void *data);
void print_char(void *data);

typedef void (*print_data_func_t)(void *data);

extern print_data_func_t print_functions[];



#endif // PRINT_H
