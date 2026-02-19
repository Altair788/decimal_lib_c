#include <string.h>
#include "../headers/my_helpers.h"

#define S21_BIG_DECIMAL_DATA_BITS 3
#define ERROR 1

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

void my_null_big_decimal(my_big_decimal* value) {
    memset(value, 0, sizeof(*value));
}


int my_get_bit(my_decimal value, int bit_index) {
    if (bit_index < 0 || bit_index >= 96) {
        return 0;
    }

    int index_word = bit_index / 32;
    int bit_in_word = bit_index % 32;

    return (value.bits[index_word] >> bit_in_word) &1;
}



int my_set_bit(my_decimal* value, int bit_index, int bit_value) {
    if (!value || bit_index < 0 || bit_index >= 96) {
        return 0;
    }

    int index_word = bit_index / 32;
    int bit_in_word = bit_index % 32;

    if (bit_value) {
        value->bits[index_word] |= (1 << bit_in_word);
    } else {
        value->bits[index_word] &= ~(1 << bit_in_word);
    }
    return 0;
}

int my_get_scale(my_decimal* value) {
    int scale = 0;
    if (!value) {
        return 0;
    } else {
        scale = value->bits[3] >> 16 & 0xFF;
    }

    if (scale > 28) {
        return 0;
    } else {
        return scale;
    }
}

int my_get_sign(my_decimal* value) {
    int sign = 0;
    if (value) {
        sign = (value->bits[3] &= 1u << 31) != 0;
    }
    return sign;
}

int my_set_sign(my_big_decimal* value1, my_decimal* value2) {
    if (value1 && value2) {
        if (value1->sign == 1) {
            value2->bits[3] |= 1u << 31;
        } else {
            value2->bits[3] &= ~(1u << 31);
        }
    } else {
        return ERROR;
    }
    return 0;
}