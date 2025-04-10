#include "stdio.h"
#include "x_to_y_int.h"

// Function to print YByteInt as hexadecimal
void print_ybyteint(YByteInt* y_int) {
    for (uint8_t i = 0; i < WORDBYTES; i++) {
        printf("%02X ", y_int->bytes[i]);
    }
    printf("\n");
}

int main() {
    int64_t test_value = -2;
    uint8_t word_length = sizeof(test_value);

    YByteInt result = convert_smaller_word(test_value, word_length);

    // Print the result
    printf("Converted value of -2: ");
    print_ybyteint(&result);

    // Test the convert_large_word function with a negative value
    int64_t test_value_neg = -922337203685477580;
    uint8_t num_words_neg = 0;

    YByteInt* result_neg = convert_larger_word(test_value_neg, &num_words_neg);
    printf("Converted negative value %d:\n", INT64_MIN);
    for (int i = 0; i < num_words_neg; i++) {
        print_ybyteint(&result_neg[i]);
    }

    // Test the convert_large_word function with a positive value
    int64_t test_value_pos = 123456;
    uint8_t num_words_pos = 0;

    YByteInt* result_pos = convert_larger_word(test_value_pos, &num_words_pos);
    printf("Converted positive value (123456):\n");
    for (int i = 0; i < num_words_pos; i++) {
        print_ybyteint(&result_pos[i]);
    }

    // Free the allocated memory
    free(result_neg);
    free(result_pos);

    return 0;
}
