#ifndef X_TO_Y_INT_H
#define X_TO_Y_INT_H
#include "stdbool.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#define WORDBYTES 4

/**
 * @brief Represents a custom integer type that stores a multi-byte value.
 *
 * This structure holds a number represented by `WORDBYTES` bytes.
 * It is used to store the value after converting from a native integer type.
 */
typedef struct {
    uint8_t bytes[WORDBYTES];
} YByteInt;

/**
 * @brief Initializes a YByteInt structure to zero.
 *
 * This function sets all the bytes of the `YByteInt` to zero to prepare it for further use.
 * It should be called before using a `YByteInt` to ensure it starts with a clean slate.
 *
 * @param word A pointer to the YByteInt structure to be initialized.
 */
void initialize_ybyte_word(YByteInt * word);

/**
 * @brief Converts a smaller than WORDBYTES word into a YByteInt.
 *
 * This function takes a signed 64-bit integer (`int64_t`), processes it and stores the result in a `YByteInt`.
 * The conversion works for both positive and negative numbers, using two's complement for negative values.
 * If the input value fits within a single `WORDBYTES` space, it is stored directly.
 *
 * @param value The 64-bit integer to be converted into a YByteInt.
 * @param word_length The size in bytes of the input value (usually 1, 2, or 4 bytes).
 * @return A `YByteInt` structure containing the converted value.
 */
YByteInt convert_smaller_word(int64_t value, uint8_t word_length);


/**
 * @brief Converts a larger than WORDBYTES word (e.g., 64-bit int) into multiple YByteInt structures.
 *
 * This function takes a signed 64-bit integer (`int64_t`), processes it and splits the result across multiple `YByteInt` structures.
 * It handles both positive and negative integers. For negative integers, two's complement conversion is applied across multiple words.
 * The function dynamically allocates an array of `YByteInt` structures based on how many `WORDBYTES` are needed.
 *
 * @param value The 64-bit integer to be converted into multiple YByteInt structures.
 * @param num_words A pointer to a variable where the number of YByteInt structures used will be stored.
 * @return A pointer to an array of `YByteInt` structures containing the converted value, or `NULL` in case of allocation failure.
 */
YByteInt* convert_larger_word(int64_t value, uint8_t* num_words);

#endif
