#include <check.h>

#include "./back/polka.h"
#include "./back/stack.h"

START_TEST(t1_addition) {
  double result = 0;
  double x = 0;
  int code = 0;
  char str[MAX_LEN] = "2+2";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result, 4.0);
}
END_TEST

START_TEST(t2_addition) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "1+1+1+1+1+1+1+1";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result, 8.0);
}
END_TEST

START_TEST(t3_addition) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "2.5+2.45";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result, 4.95);
}
END_TEST

START_TEST(t4_addition) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "(-2)+3";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result, 1);
}
END_TEST

// // sub
START_TEST(t1_sub) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "0.27-0.35";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -0.08, 000000.1);
}
END_TEST

START_TEST(t2_sub) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "5.55-0.378";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 5.172, 000000.1);
}
END_TEST

START_TEST(t3_sub) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "-0.12345-23.23";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -23.35345, 000000.1);
}
END_TEST

// mul
START_TEST(t1_mul) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "23*4.5";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 103.5, 000000.1);
}
END_TEST

START_TEST(t2_mul) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "0.456*(-2.1)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -0.9576, 000000.1);
}
END_TEST

START_TEST(t3_mul) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "-0.910*3";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -2.73, 000000.1);
}
END_TEST

// // div
START_TEST(t1_div) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "5/2/3";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 0.833333333, 000000.1);
}
END_TEST

START_TEST(t2_div) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "5.3/(-2)/0.4";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -6.625, 000000.1);
}
END_TEST

START_TEST(t3_div) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "0/0";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_ldouble_nan(result);
}
END_TEST

// // mod
START_TEST(t1_mod) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "5mod4";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 1, 000000.1);
}
END_TEST

START_TEST(t2_mod) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "15mod3";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 0, 000000.1);
}
END_TEST

// // pow
START_TEST(t1_pow) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "5^2";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 25, 000000.1);
}
END_TEST

START_TEST(t2_pow) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "3.35^2";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 11.2225, 000000.1);
}
END_TEST

START_TEST(t1_unar_plus) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "+5";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 5, 000000.1);
}
END_TEST

START_TEST(t2_unar_plus) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "+(5)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 5, 000000.1);
}
END_TEST

// // unar minus
START_TEST(t1_unar_minus) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "-5";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -5, 000000.1);
}
END_TEST

START_TEST(t2_unar_minus) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "(-5)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, -5, 000000.1);
}
END_TEST

// // cos
START_TEST(t1_cos) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "cos(3)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, cos(3), 000000.1);
}
END_TEST

START_TEST(t2_cos) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "cos(5.1234)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, cos(5.1234), 000000.1);
}
END_TEST

// // sin
START_TEST(t1_sin) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "sin(5.1234)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, sin(5.1234), 000000.1);
}
END_TEST

START_TEST(t2_sin) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "sin(0)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, sin(0), 000000.1);
}
END_TEST

// // tan
START_TEST(t1_tan) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "tan(2.4)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, tan(2.4), 000000.1);
}
END_TEST

START_TEST(t2_tan) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "tan(0.34)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, tan(0.34), 000000.1);
}
END_TEST

// // acos
START_TEST(t1_acos) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "acos(0)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, acos(0), 000000.1);
}
END_TEST

START_TEST(t2_acos) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "acos(0.4)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, acos(0.4), 000000.1);
}
END_TEST

// // asin
START_TEST(t1_asin) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "asin(0.5)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, asin(0.5), 000000.1);
}
END_TEST

START_TEST(t2_asin) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "asin(0.23)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, asin(0.23), 000000.1);
}
END_TEST

// // atan
START_TEST(t1_atan) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "atan(0)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, atan(0), 000000.1);
}
END_TEST

START_TEST(t2_atan) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "atan(1)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, atan(1), 000000.1);
}
END_TEST

// // sqrt
START_TEST(t1_sqrt) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "sqrt(1)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, sqrt(1), 000000.1);
}
END_TEST

START_TEST(t2_sqrt) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "sqrt(5)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, sqrt(5), 000000.1);
}
END_TEST

// // log
START_TEST(t1_log) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "log(11)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, log10(11), 000000.1);
}
END_TEST

START_TEST(t2_log) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "log(1.23)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, log10(1.23), 000000.1);
}
END_TEST

// // ln
START_TEST(t1_ln) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "ln(0.23)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, log(0.23), 000000.1);
}
END_TEST

START_TEST(t2_ln) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "ln(5.03)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, log(5.03), 000000.1);
}
END_TEST

// // general
START_TEST(t1_general_tests) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "coss(0)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(t2_general_tests) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "-(3)*(-1-(7*(-(-(-(-7))))))";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 150, 000000.1);
}
END_TEST

START_TEST(t3_general_tests) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[MAX_LEN] = "(1+2)4(cos(x*7-2)+sin(2*x))70^(-10)5(-3)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(t4_general_tests) {
  int code = 0;
  double result = 0;
  double x = 0;
  char str[] = "5+(+5)";
  if (calculate(str, x, &result))
    code = 0;
  else
    code = 1;
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result, 10, 000000.1);
}

int main() {
  Suite* calc = suite_create("calc");
  SRunner* sr = srunner_create(calc);

  TCase* tc_add = tcase_create("add");
  TCase* tc_sub = tcase_create("sub");
  TCase* tc_mul = tcase_create("mul");
  TCase* tc_div = tcase_create("div");
  TCase* tc_mod = tcase_create("mod");
  TCase* tc_pow = tcase_create("pow");
  TCase* tc_unar_plus = tcase_create("unar_plus");
  TCase* tc_unar_minus = tcase_create("unar_minus");
  TCase* tc_cos = tcase_create("cos");
  TCase* tc_sin = tcase_create("sin");
  TCase* tc_tan = tcase_create("tan");
  TCase* tc_acos = tcase_create("acos");
  TCase* tc_asin = tcase_create("asin");
  TCase* tc_atan = tcase_create("atan");
  TCase* tc_sqrt = tcase_create("sqrt");
  TCase* tc_log = tcase_create("log");
  TCase* tc_ln = tcase_create("ln");
  TCase* tc_general_tests = tcase_create("general_tests");

  //   tcase_set_timeout(tc_add, 90);
  suite_add_tcase(calc, tc_add);
  tcase_add_test(tc_add, t1_addition);
  tcase_add_test(tc_add, t2_addition);
  tcase_add_test(tc_add, t3_addition);
  tcase_add_test(tc_add, t4_addition);

  suite_add_tcase(calc, tc_sub);
  tcase_add_test(tc_sub, t1_sub);
  tcase_add_test(tc_sub, t2_sub);
  tcase_add_test(tc_sub, t3_sub);

  suite_add_tcase(calc, tc_mul);
  tcase_add_test(tc_mul, t1_mul);
  tcase_add_test(tc_mul, t2_mul);
  tcase_add_test(tc_mul, t3_mul);

  suite_add_tcase(calc, tc_div);
  tcase_add_test(tc_div, t1_div);
  tcase_add_test(tc_div, t2_div);
  tcase_add_test(tc_div, t3_div);

  suite_add_tcase(calc, tc_mod);
  tcase_add_test(tc_mod, t1_mod);
  tcase_add_test(tc_mod, t2_mod);

  suite_add_tcase(calc, tc_pow);
  tcase_add_test(tc_pow, t1_pow);
  tcase_add_test(tc_pow, t2_pow);

  suite_add_tcase(calc, tc_unar_plus);
  tcase_add_test(tc_unar_plus, t1_unar_plus);
  tcase_add_test(tc_unar_plus, t2_unar_plus);

  suite_add_tcase(calc, tc_unar_minus);
  tcase_add_test(tc_unar_minus, t1_unar_minus);
  tcase_add_test(tc_unar_minus, t2_unar_minus);

  suite_add_tcase(calc, tc_cos);
  tcase_add_test(tc_cos, t1_cos);
  tcase_add_test(tc_cos, t2_cos);

  suite_add_tcase(calc, tc_sin);
  tcase_add_test(tc_sin, t1_sin);
  tcase_add_test(tc_sin, t2_sin);

  suite_add_tcase(calc, tc_tan);
  tcase_add_test(tc_tan, t1_tan);
  tcase_add_test(tc_tan, t2_tan);

  suite_add_tcase(calc, tc_acos);
  tcase_add_test(tc_acos, t1_acos);
  tcase_add_test(tc_acos, t2_acos);

  suite_add_tcase(calc, tc_asin);
  tcase_add_test(tc_asin, t1_asin);
  tcase_add_test(tc_asin, t2_asin);

  suite_add_tcase(calc, tc_atan);
  tcase_add_test(tc_atan, t1_atan);
  tcase_add_test(tc_atan, t2_atan);

  suite_add_tcase(calc, tc_sqrt);
  tcase_add_test(tc_sqrt, t1_sqrt);
  tcase_add_test(tc_sqrt, t2_sqrt);

  suite_add_tcase(calc, tc_log);
  tcase_add_test(tc_log, t1_log);
  tcase_add_test(tc_log, t2_log);

  suite_add_tcase(calc, tc_ln);
  tcase_add_test(tc_ln, t1_ln);
  tcase_add_test(tc_ln, t2_ln);

  suite_add_tcase(calc, tc_general_tests);
  tcase_add_test(tc_general_tests, t1_general_tests);
  tcase_add_test(tc_general_tests, t2_general_tests);
  tcase_add_test(tc_general_tests, t3_general_tests);
  tcase_add_test(tc_general_tests, t4_general_tests);

  srunner_run_all(sr, CK_ENV);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf;
}
