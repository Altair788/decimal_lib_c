#include <string.h>
#include "../headers/my_helpers.h"

#define S21_BIG_DECIMAL_DATA_BITS 3

// возвращает 1, если первые три бита zero, иначе 0
int my_is_zero(my_decimal value) {
    int result = 1;
    int i;
    int has_nonzero_bit = 0;

    for (i = 0; i < S21_BIG_DECIMAL_DATA_BITS && !(has_nonzero_bit); i++) {
        if (value.bits[i] != 0) {
            has_nonzero_bit = 1;
            result = 0;
        }  
    }
    
    return result;
}

void my_null_decimal(my_decimal* value) {
    memset(value, 0, sizeof(*value));
}


int my_get_bit(my_decimal value, int index_of_bit) {
    if (index_of_bit < 0 || index_of_bit >= 96) {
        return 0;
    }

    int index_word = index_of_bit / 32;
    int bit_in_word = index_of_bit % 32;

    return (value.bits[index_word] >> bit_in_word) &1;
}
