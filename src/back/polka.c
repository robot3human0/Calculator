#include "polka.h"

int is_num(char ch) {
  return ((ch >= '0' && ch <= '9') || ch == '.' || ch == 'x');
}

void to_lower_case_without_spaces(char *src) {
  char *tmp = src;
  size_t i = 0, j = 0, limit = strlen(src);
  for (; i < limit; i++) {
    if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
      src[j] = tmp[i] + 32;
    } else if (tmp[i] == ' ') {
      continue;
    } else {
      src[j] = tmp[i];
    }
    j++;
  }
  src[j] = '\0';
}

int is_valid_str(char *src) {
  char valid_chars[] = ".*+-/^acdgilmnoqrst()0123456789x";
  int flag = 1;
  size_t limit = strlen(src);
  for (size_t i = 0; i < limit; i++) {
    if (!strchr(valid_chars, src[i])) {
      flag = ERR_CALC;
      break;
    }
  }
  return flag;
}

int is_brackets_paired(char *str) {
  int flag = 1;
  size_t brackets_counter = 0, limit = strlen(str);
  for (size_t i = 0; i < limit; i++) {
    if (str[i] == '(' || str[i] == ')') brackets_counter++;
  }
  if (brackets_counter % 2 != 0) {
    flag = ERR_CALC;
  }
  return flag;
}

int no_operation_before(char *str) {
  int err = 0;
  size_t limit = strlen(str);
  for (size_t i = 0; i < limit; i++) {
    if (str[i] == '(' && is_num(str[i - 1])) {
      err = 1;
      break;
    } else if (str[i] == ')' && is_num(str[i + 1])) {
      err = 1;
      break;
    }
  }
  return err;
}

int is_unar_plus(char *str, int i) { return (str[i - 1] == '(' || i == 0); }

char base(char *src, size_t *position, int *err) {
  char answear = src[*position];
  int n = *position;
  if ((src[n] == '-' && n == 0) || (src[n] == '-' && src[n - 1] == '(')) {
    answear = U_MINUS;
  } else if (src[n] == 'l' && src[n + 1] == 'n' && src[n + 2] == '(') {
    answear = LN;
    *position += 1;
  } else if (src[n] == 'l' && src[n + 1] == 'o' && src[n + 2] == 'g' &&
             src[n + 3] == '(') {
    answear = LOG;
    *position += 2;
  } else if (src[n] == 's' && src[n + 1] == 'i' && src[n + 2] == 'n' &&
             src[n + 3] == '(') {
    answear = SIN;
    *position += 2;
  } else if (src[n] == 'c' && src[n + 1] == 'o' && src[n + 2] == 's' &&
             src[n + 3] == '(') {
    answear = COS;
    *position += 2;
  } else if (src[n] == 't' && src[n + 1] == 'a' && src[n + 2] == 'n' &&
             src[n + 3] == '(') {
    answear = TAN;
    *position += 2;
  } else if (src[n] == 'm' && src[n + 1] == 'o' && src[n + 2] == 'd') {
    answear = MOD;
    *position += 2;
  } else if (src[n] == 'a' && src[n + 1] == 's' && src[n + 2] == 'i' &&
             src[n + 3] == 'n' && src[n + 4] == '(') {
    answear = ASIN;
    *position += 3;
  } else if (src[n] == 'a' && src[n + 1] == 'c' && src[n + 2] == 'o' &&
             src[n + 3] == 's' && src[n + 4] == '(') {
    answear = ACOS;
    *position += 3;
  } else if (src[n] == 'a' && src[n + 1] == 't' && src[n + 2] == 'a' &&
             src[n + 3] == 'n' && src[n + 4] == '(') {
    answear = ATAN;
    *position += 3;
  } else if (src[n] == 's' && src[n + 1] == 'q' && src[n + 2] == 'r' &&
             src[n + 3] == 't' && src[n + 4] == '(') {
    answear = SQRT;
    *position += 3;
  } else if (src[n] != '-' && src[n] != 'x') {
    *err = 1;
  }

  return answear;
}

int make_it_shorter(char *src) {
  int err = 0;
  char *tmp = src;
  size_t i = 0, j = 0, limit = strlen(src);
  for (; i < limit; i++) {
    if (err) break;
    if ((tmp[i] >= 'a' && tmp[i] <= 'z') || tmp[i] == '-') {
      src[j] = base(tmp, &i, &err);
    } else if (tmp[i] == '+') {
      if (is_unar_plus(src, i))
        continue;
      else
        src[j] = tmp[i];
    } else
      src[j] = tmp[i];
    j++;
  }
  if (!err) {
    src[j] = '\0';
    err = no_operation_before(src);
  }
  return err;
}

int check_priority(char ch) {
  int res = 0;
  if (ch == '+' || ch == '-') {
    res = 1;
  } else if (ch == '*' || ch == '/' || ch == MOD) {
    res = 2;
  } else if (ch == '^') {
    res = 3;
  } else if (ch == U_MINUS) {
    res = 4;
  } else if (ch == SIN || ch == COS || ch == TAN || ch == ASIN || ch == ACOS ||
             ch == ATAN || ch == LN || ch == LOG || ch == SQRT) {
    res = 5;
  }
  return res;
}

void to_polka(char *src, char *dst, Stack_t **stack) {
  size_t i = 0, j = 0, limit = strlen(src);
  char val;
  for (; i < limit; i++) {
    if (!is_num(src[i]) && src[i] != '(' && src[i] != ')') {
      if (*stack == NULL ||
          (check_priority(src[i]) > check_priority(peek(*stack)))) {
        push(stack, src[i]);
      } else if (check_priority(src[i]) <= check_priority(peek(*stack))) {
        while (*stack &&
               check_priority(src[i]) <= check_priority(peek(*stack))) {
          val = pop(stack);
          dst[j++] = ' ';
          dst[j++] = val;
        }
        push(stack, src[i]);
      }
      if (src[i] != '(' && src[i] != ')' && dst[j - 1] != ' ' && j != 0)
        dst[j++] = ' ';
    } else {
      if (src[i] == '(') {
        push(stack, src[i]);
      } else if (src[i] == ')') {
        while (1) {
          val = pop(stack);
          if (val == '(') break;
          dst[j++] = ' ';
          dst[j++] = val;
        }
      } else {
        dst[j] = src[i];
        j++;
      }
    }
  }

  if (*stack) {
    while (*stack) {
      val = pop(stack);
      if (val != '(' || val != ')') {
        dst[j++] = ' ';
        dst[j++] = val;
      }
    }
  }
  dst[j] = '\0';
}

void stack_em(Double_stack **nums, char *str, size_t n, double x) {
  char buff[17];
  double tmp = 0;
  char num_exist = 0;
  size_t j = 0, i;
  for (i = 0; i < n; i++) {
    if (is_num(str[i]) || str[i] == U_MINUS) num_exist++;
    if (str[i] == 'x') {
      push_num(nums, x);
      i++;
    } else if (str[i] == ' ' && num_exist) {
      buff[j] = '\0';
      tmp = atof(buff);
      j = 0;
      push_num(nums, tmp);
      num_exist = 0;
    } else if (str[i] == 'u') {
      buff[j++] = '-';
    } else if (num_exist) {
      buff[j++] = str[i];
    }
  }
}

int true_calc(char *str, double *result, Double_stack **nums, double x) {
  int j = -1, flag = 1;
  double a = 0;
  double b = 0;
  int no_func = 1;
  size_t limit = strlen(str);
  char *p = str;
  for (size_t i = 0; i < limit; i++) {
    j++;
    if (!is_num(str[i]) && str[i] != ' ') {
      no_func = 0;
      stack_em(nums, p, j, x);
      p = str + ((i + 2) * sizeof(char));
      j = -1;
    } else {
      continue;
    }
    b = pop_num(nums);
    if (str[i] == U_MINUS) {
      *result = 0 - b;
    } else if (str[i] == '^') {
      a = pop_num(nums);
      *result = pow(a, b);
    } else if (str[i] == '+') {
      a = pop_num(nums);
      *result = a + b;
    } else if (str[i] == '-') {
      a = pop_num(nums);
      *result = a - b;
    } else if (str[i] == '*') {
      a = pop_num(nums);
      *result = a * b;
    } else if (str[i] == '/') {
      a = pop_num(nums);
      *result = a / b;
    } else if (str[i] == LN) {
      *result = log(b);
    } else if (str[i] == LOG) {
      *result = log10(b);
    } else if (str[i] == SIN) {
      *result = sin(b);
    } else if (str[i] == COS) {
      *result = cos(b);
    } else if (str[i] == TAN) {
      *result = tan(b);
    } else if (str[i] == ASIN) {
      *result = asin(b);
    } else if (str[i] == ACOS) {
      *result = acos(b);
    } else if (str[i] == ATAN) {
      *result = atan(b);
    } else if (str[i] == SQRT) {
      *result = sqrt(b);
    } else if (str[i] == MOD) {
      a = pop_num(nums);
      *result = fmod(a, b);
    }
    push_num(nums, *result);
  }
  if (no_func) *result = atof(p);
  return flag;
}

int calculate(char *str, double x, double *result) {
  int code = 0;
  Stack_t *polka = NULL;
  Double_stack *nums = NULL;
  char res[MAX_LEN];
  to_lower_case_without_spaces(str);
  if (is_valid_str(str) && is_brackets_paired(str) && !make_it_shorter(str)) {
    to_polka(str, res, &polka);
    if (true_calc(res, result, &nums, x)) code = 1;
  }
  return code;
}
