#include "print.h"

void print_uint8(void *data) { printf("%" PRIu8 "\n", *(uint8_t *)data); }
void print_int8(void *data) { printf("%" PRIi8 "\n", *(int8_t *)data); }
void print_uint16(void *data) { printf("%" PRIu16 "\n", *(uint16_t *)data); }
void print_int16(void *data) { printf("%" PRIi16 "\n", *(int16_t *)data); }
void print_uint32(void *data) { printf("%" PRIu32 "\n", *(uint32_t *)data); }
void print_int32(void *data) { printf("%" PRIi32 "\n", *(int32_t *)data); }
void print_uint64(void *data) { printf("%" PRIu64 "\n", *(uint64_t *)data); }
void print_int64(void *data) { printf("%" PRIi64 "\n", *(int64_t *)data); }
void print_float(void *data) { printf("%f\n", *(float *)data); }
void print_double(void *data) { printf("%f\n", *(double *)data); }
void print_char(void *data) { printf("%c\n", *(char *)data); }

print_data_func_t print_functions[] = {
    print_uint8,
    print_int8,
    print_uint16,
    print_int16,
    print_uint32,
    print_int32,
    print_uint64,
    print_int64,
    print_float,
    print_double,
    print_char,
};
