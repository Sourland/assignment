#include "x_to_y_int.h"

void initialize_ybyte_word(YByteInt *word) {
    memset(word->bytes, 0, WORDBYTES);
}

YByteInt convert_smaller_word(int64_t value, uint8_t word_length) {
    YByteInt result;
    initialize_ybyte_word(&result);

    uint64_t positive_value = (value < 0) ? -value : value;

    for (uint8_t i = 0; i < WORDBYTES; i++) {
        result.bytes[WORDBYTES - i - 1] = (positive_value >> (8 * i)) & 0xFF;
    }

    if (value < 0) {
        for (uint8_t i = 0; i < WORDBYTES; i++) {
            result.bytes[i] = ~result.bytes[i];
        }

        for (int i = WORDBYTES - 1; i >= 0; i--) {
            if (result.bytes[i] < 0xFF) {
                result.bytes[i]++;
                break;
            }
            result.bytes[i] = 0x00;
        }
    }

    return result;
}

YByteInt* convert_larger_word(int64_t value, uint8_t* num_words) {
    uint64_t abs_value;
    bool is_negative = (value < 0);

    // Handle INT64_MIN safely
    if (value == INT64_MIN) {
        abs_value = (uint64_t)INT64_MAX + 1;
    } else {
        abs_value = is_negative ? -value : value;
    }

    // Count significant bytes
    size_t num_bytes_needed = 0;
    uint64_t temp = abs_value;
    do {
        temp >>= 8;
        num_bytes_needed++;
    } while (temp > 0);

    // Calculate required YByteInt words
    size_t yword_count = (num_bytes_needed + WORDBYTES - 1) / WORDBYTES;
    if (yword_count == 0) yword_count = 1;
    *num_words = yword_count;

    YByteInt* result = malloc(yword_count * sizeof(YByteInt));
    if (!result) {
        exit(EXIT_FAILURE);
    }

    // Fill words from LSB to MSB, then reverse to match MSB-first requirement
    for (int i = yword_count - 1; i >= 0; i--) {
        initialize_ybyte_word(&result[i]);
        for (int j = 0; j < WORDBYTES; j++) {
            if (abs_value == 0) break;
            result[i].bytes[WORDBYTES - 1 - j] = abs_value & 0xFF;
            abs_value >>= 8;
        }

        // Two's complement if value is negative
        if (is_negative) {
            for (int j = 0; j < WORDBYTES; j++) {
                result[i].bytes[j] = ~result[i].bytes[j];
            }

            // Add 1 to LSB of this word chain
            for (int j = WORDBYTES - 1; j >= 0; j--) {
                if (++result[i].bytes[j] != 0) break;
            }
        }
    }

    return result;
}
