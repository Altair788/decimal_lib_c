#ifndef MY_HELPERS_H
#define MY_HELPERS_H

#include "../my_decimal.h"

typedef struct {
  unsigned bits[8];
} my_big_decimal;

my_big_decimal my_decimal_to_big(my_decimal value);               // TODO
my_decimal my_big_to_decimal(my_big_decimal value);               // TODO
int my_get_sign(my_decimal value);                                 // TODO
int my_set_sign(my_decimal* value, int sign);                      // TODO
int my_get_scale(my_decimal* value);                                // TODO
int my_set_scale(my_decimal* value, int scale);                    // TODO
int my_get_bit(my_decimal value, int bit_index);                   // TODO
int my_set_bit(my_decimal* value, int bit_index, int bit_value);   // TODO
int my_is_zero(my_decimal value);                                  // UNDER REVIEW
void my_null_decimal(my_decimal* value);                             // TODO
int my_normalize_pair(my_decimal* value_1, my_decimal* value_2);  // TODO
int my_shift_left(my_big_decimal* value, int shift);               // TODO
int my_shift_right(my_big_decimal* value, int shift);              // TODO

void my_round_big_decimal(my_big_decimal* value, int target_scale);  // TODO

#endif
