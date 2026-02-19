#include <check.h>
#include "../headers/my_helpers.h"



START_TEST(my_is_zero_first_bit_is_digit){
    my_decimal val = {{21, 0, 0, 0}};
    ck_assert_int_eq(my_is_zero(val), 0);
}
END_TEST

START_TEST(my_is_zero_second_bit_is_digit){
    my_decimal val = {{0, 40, 0, 0}};
    ck_assert_int_eq(my_is_zero(val), 0);
}
END_TEST

START_TEST(my_is_zero_third_bit_is_digit){
    my_decimal val = {{0, 0, 30, 0}};
    ck_assert_int_eq(my_is_zero(val), 0);
}
END_TEST


START_TEST(my_is_zero_fourth_bit_is_digit){
    my_decimal val = {{0, 0, 0, 40}};
    ck_assert_int_eq(my_is_zero(val), 1);
}
END_TEST

START_TEST(my_is_zero_all_zero) {
    my_decimal val = {{0, 0, 0, 0}};
    ck_assert_int_eq(my_is_zero(val), 1);
}
END_TEST

START_TEST(my_is_zero_multiple_nonzero) {
    my_decimal val = {{1, 2, 0, 0}};
    ck_assert_int_eq(my_is_zero(val), 0);
}
END_TEST


START_TEST(my_null_decimal_garbage){
    my_decimal val;
    my_null_decimal(&val);
    ck_assert_int_eq(val.bits[0], 0);
    ck_assert_int_eq(val.bits[1], 0);
    ck_assert_int_eq(val.bits[2], 0);
    ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(my_null_decimal_already_zero){
    my_decimal val = {{0, 0, 0, 0}};
    my_null_decimal(&val);
    ck_assert_int_eq(val.bits[0], 0);
}
END_TEST




Suite* my_helpers_suite(void) {
    Suite *s = suite_create("helpers");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, my_is_zero_first_bit_is_digit);
    tcase_add_test(tc_core, my_is_zero_second_bit_is_digit);
    tcase_add_test(tc_core, my_is_zero_third_bit_is_digit);
    tcase_add_test(tc_core, my_is_zero_fourth_bit_is_digit);
    tcase_add_test(tc_core, my_is_zero_all_zero);
    tcase_add_test(tc_core, my_is_zero_multiple_nonzero);
    tcase_add_test(tc_core, my_null_decimal_garbage);
    tcase_add_test(tc_core, my_null_decimal_already_zero);

    suite_add_tcase(s, tc_core);
    return s;
}

