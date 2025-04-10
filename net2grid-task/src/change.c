#include "change.h"

// Function definitions
void change_uint8(void *data, void *new_value) {
    *(uint8_t *)data = *(uint8_t *)new_value;
}

void change_int8(void *data, void *new_value) {
    *(int8_t *)data = *(int8_t *)new_value;
}

void change_uint16(void *data, void *new_value) {
    *(uint16_t *)data = *(uint16_t *)new_value;
}

void change_int16(void *data, void *new_value) {
    *(int16_t *)data = *(int16_t *)new_value;
}

void change_uint32(void *data, void *new_value) {
    *(uint32_t *)data = *(uint32_t *)new_value;
}

void change_int32(void *data, void *new_value) {
    *(int32_t *)data = *(int32_t *)new_value;
}

void change_uint64(void *data, void *new_value) {
    *(uint64_t *)data = *(uint64_t *)new_value;
}

void change_int64(void *data, void *new_value) {
    *(int64_t *)data = *(int64_t *)new_value;
}

void change_float(void *data, void *new_value) {
    *(float *)data = *(float *)new_value;
}

void change_double(void *data, void *new_value) {
    *(double *)data = *(double *)new_value;
}

void change_char(void *data, void *new_value) {
    *(char *)data = *(char *)new_value;
}

// Define the array of function pointers
change_data_func_t change_functions[] = {
    change_uint8,
    change_int8,
    change_uint16,
    change_int16,
    change_uint32,
    change_int32,
    change_uint64,
    change_int64,
    change_float,
    change_double,
    change_char,
};
