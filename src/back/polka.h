#ifndef SRC_BACK_POLKA_H_
#define SRC_BACK_POLKA_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define P printf
#define MAX_LEN 255
#define ERR_CALC 0

#define LN 'l'
#define LOG 'g'
#define MOD 'm'
#define COS 'c'
#define SIN 's'
#define TAN 't'
#define ACOS 'a'
#define ASIN 'i'
#define ATAN 'n'
#define SQRT 'q'
#define U_MINUS 'u'

int is_num(char ch);
void to_lower_case_without_spaces(char *src);
int is_valid_str(char *src);
int is_brackets_paired(char *str);
int no_operation_before(char *str);
int is_unar_plus(char *str, int i);
char base(char *src, size_t *position, int *err);
int make_it_shorter(char *src);
int check_priority(char ch);
void to_polka(char *src, char *dst, Stack_t **stack);
void stack_em(Double_stack **nums, char *str, size_t n, double x);
int true_calc(char *str, double *result, Double_stack **nums, double x);
int calculate(char *str, double x, double *result);

#endif  //  SRC_BACK_POLKA_H_
