#ifndef MY_DECIMAL_H
#define MY_DECIMAL_H

typedef struct {
  int bits[4];
} my_decimal;

int my_add(my_decimal value_1, my_decimal value_2,
            my_decimal* result);  // TODO
int my_sub(my_decimal value_1, my_decimal value_2,
            my_decimal* result);  // TODO
int my_mul(my_decimal value_1, my_decimal value_2,
            my_decimal* result);  // TODO
int my_div(my_decimal value_1, my_decimal value_2,
            my_decimal* result);                            // TODO
int my_is_less(my_decimal, my_decimal);                   // TODO
int my_is_less_or_equal(my_decimal, my_decimal);          // TODO
int my_is_greater(my_decimal, my_decimal);                // TODO
int my_is_greater_or_equal(my_decimal, my_decimal);       // TODO
int my_is_equal(my_decimal, my_decimal);                  // TODO
int my_is_not_equal(my_decimal, my_decimal);              // TODO
int my_from_int_to_decimal(int src, my_decimal* dst);      // TODO
int my_from_float_to_decimal(float src, my_decimal* dst);  // TODO
int my_from_decimal_to_int(my_decimal src, int* dst);      // TODO
int my_from_decimal_to_float(my_decimal src, float* dst);  // TODO
int my_floor(my_decimal value, my_decimal* result);       // TODO
int my_round(my_decimal value, my_decimal* result);       // TODO
int my_truncate(my_decimal value, my_decimal* result);    // TODO
int my_negate(my_decimal value, my_decimal* result);      // TODO

#endif
