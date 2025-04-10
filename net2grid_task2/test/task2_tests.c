#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "x_to_y_int.h"

void print_ybyteint(YByteInt* y_int) {
    for (int i = 0; i < WORDBYTES; i++) {
        printf("%02X ", y_int->bytes[i]);
    }
    printf("\n");
}
void test_convert_smaller_word() {
    int64_t values[] = {123, -2, 0, INT64_MAX, INT64_MIN, 255}; // Test values
    for (int i = 0; i < 6; i++) {
        YByteInt result = convert_smaller_word(values[i], WORDBYTES);
        printf("Smaller word conversion for %lld: ", values[i]);
        print_ybyteint(&result);
    }
}

void test_convert_larger_word() {
    int64_t values[] = {123, -2, 0, INT64_MAX, INT64_MIN, 255}; // Test values
    for (int i = 0; i < 6; i++) {
        uint8_t num_words = 0;
        YByteInt* result = convert_larger_word(values[i], &num_words);
        printf("Larger word conversion for %lld: ", values[i]);
        for (int j = 0; j < num_words; j++) {
            print_ybyteint(&result[j]);
        }
        free(result);  // Ensure to free allocated memory after use
    }
}

void test_edge_cases() {
    printf("Testing Edge Cases:\n");

    // Test 0
    YByteInt result_zero = convert_smaller_word(0, WORDBYTES);
    printf("Smaller word conversion for 0: ");
    print_ybyteint(&result_zero);

    // Test INT64_MAX
    YByteInt result_max = convert_smaller_word(INT64_MAX, WORDBYTES);
    printf("Smaller word conversion for INT64_MAX: ");
    print_ybyteint(&result_max);

    // Test INT64_MIN
    YByteInt result_min = convert_smaller_word(INT64_MIN, WORDBYTES);
    printf("Smaller word conversion for INT64_MIN: ");
    print_ybyteint(&result_min);

    // Test for larger word conversion
    uint8_t num_words = 0;
    YByteInt* result_large = convert_larger_word(INT64_MAX, &num_words);
    printf("Larger word conversion for INT64_MAX:\n");
    for (int i = 0; i < num_words; i++) {
        print_ybyteint(&result_large[i]);
    }
    free(result_large);

    // Test INT64_MIN for larger word conversion
    YByteInt* result_large_min = convert_larger_word(INT64_MIN, &num_words);
    printf("Larger word conversion for INT64_MIN:\n");
    for (int i = 0; i < num_words; i++) {
        print_ybyteint(&result_large_min[i]);
    }
    free(result_large_min);
}

// Main test runner
int main() {
    printf("Testing smaller word conversion:\n");
    test_convert_smaller_word();

    printf("\nTesting larger word conversion:\n");
    test_convert_larger_word();

    printf("\nTesting edge cases:\n");
    test_edge_cases();

    return 0;
}
