#include <check.h>
#include <stdio.h>
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


START_TEST(my_get_bit_basic){
    my_decimal val = {{0, 0, 1 << 6, 0}};
    int index_of_bit = 70;
    int result;
    result = my_get_bit(val, index_of_bit);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(my_set_bit_basic){
    my_decimal val = {{0, 0, 1 << 6, 0}};
    int index_of_bit = 70;
    int bit_value = 0;
    printf("%u\n", val.bits[2]);
    my_set_bit(&val, index_of_bit, bit_value);
    printf("%u\n", val.bits[2]);
    int result;
    result = my_get_bit(val, index_of_bit);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(my_get_scale_basic){
    my_decimal val = {{0, 0, 0, 0}};
    val.bits[3] = 5 << 16;
    int result = my_get_scale(&val);
    ck_assert_int_eq(result, 5);

}
END_TEST


START_TEST(my_get_sign_basic){
    my_decimal val = {{0, 0, 0, 0}};
    val.bits[3] = 1 << 31;
    int result = my_get_sign(&val);
    ck_assert_int_eq(result, 1);

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
    tcase_add_test(tc_core, my_get_bit_basic);
    tcase_add_test(tc_core, my_set_bit_basic);
    tcase_add_test(tc_core, my_get_scale_basic);
    tcase_add_test(tc_core, my_get_sign_basic);


    suite_add_tcase(s, tc_core);
    return s;
}

