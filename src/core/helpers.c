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
