#include "../s21_SmartCalculator.h"

void s21_parser(char *input_str, Stack **top, double x) {
  for (int i = 0; input_str[i] != '\0'; i++) {
    if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x')
      parsing_numbers(&i, input_str, top, x);
    else if (check_unary_minus(i, input_str)) {
      push(top, 0, 0, UNARY_MINUS);
    } else if (!math_operations(&i, input_str, FAILURE) &&
               !check_unary_plus(i, input_str))
      math_operations_priority(&i, input_str, top);
    else if (!check_trigonometry_functions_and_x(i, input_str, 1, 0))
      parse_trigonometry_func(&i, input_str, top);
    else if (input_str[i] == '(')
      push(top, 0, 0, LEFT_BRACKET);
    else if (input_str[i] == ')')
      push(top, 0, 0, RIGHT_BRACKET);
  }
}

bool check_unary_minus(int i, char *input_str) {
  bool unary_minus = false;
  if (i == 0 && input_str[i] == '-')
    unary_minus = true;
  else if (input_str[i - 1] == '(' && input_str[i] == '-')
    unary_minus = true;
  else if (input_str[i - 1] == '^' && input_str[i] == '-')
    unary_minus = true;
  return unary_minus;
}

bool check_unary_plus(int i, char *input_str) {
  bool unary_minus = false;
  if (i == 0 && input_str[i] == '+')
    unary_minus = true;
  else if (input_str[i - 1] == '(' && input_str[i] == '+')
    unary_minus = true;
  else if (input_str[i - 1] == '^' && input_str[i] == '+')
    unary_minus = true;
  return unary_minus;
}

void parsing_numbers(int *i, char *input_str, Stack **top, double x) {
  char number[256] = {'\0'};
  if (input_str[*i] != 'x') {
    int j = 0;
    bool flag_for = true;
    for (; input_str[*i] != '\0' && flag_for;) {
      if (!math_operations(i, input_str, SUCCES))
        flag_for = false;
      else {
        number[j++] = input_str[*i];
        *i += 1;
      }
    }
    *i -= (input_str[*i] == '\0' && input_str[*i - 1] == ')') ? 2 : 1;
    push(top, atof(number), 0, NUMBER);
  } else {
    push(top, x, 0, X);
  }
}

void math_operations_priority(int *i, char *input_str, Stack **top) {
  if (input_str[*i] == '+' || input_str[*i] == '-')
    if (input_str[*i] == '+')
      push(top, 0, 1, PLUS);
    else
      push(top, 0, 1, MINUS);
  else if (input_str[*i] == '*' || input_str[*i] == '/')
    if (input_str[*i] == '*')
      push(top, 0, 2, MULT);
    else
      push(top, 0, 2, DIV);
  else if (input_str[*i] == 'm') {
    push(top, 0, 2, MOD);
    *i += 2;
  } else if (input_str[*i] == '^')
    push(top, 0, 3, EXP);
}

bool math_operations(int *i, char *input_str, int not_check_brack) {
  bool flag = true;
  if (input_str[*i] == '+' || input_str[*i] == '-' || input_str[*i] == 'm' ||
      input_str[*i] == '*' || input_str[*i] == '/' || input_str[*i] == '^' ||
      (input_str[*i] == ')' && not_check_brack == SUCCES))
    flag = false;
  return flag;
}

void parse_trigonometry_func(int *i, char *input_str, Stack **top) {
  char *str = input_str + *i;
  char functions[256] = {'\0'};
  // i++;
  char *functions_t[9] = {"tan(", "atan(", "log(", "ln(",  "sqrt(",
                          "cos(", "acos(", "sin(", "asin("};
  strncpy(functions, str, 5);
  int this_func;
  int res = SUCCES;
  int j = 0;
  for (; j < 9 && res == SUCCES; j++) {
    if (!strncmp(functions, functions_t[j], strlen(functions_t[j]))) {
      this_func = j;
      res = FAILURE;
      j--;
    }
  }
  int const_numbers[9] = {TAN, ATAN, LOG, LN, SQRT, COS, ACOS, SIN, ASIN};
  int const_num;
  for (int n = 0; n < 9; n++) {
    if (this_func == n) {
      const_num = const_numbers[n];
    }
  }
  push(top, 0, 4, const_num);
  _iterations_str_for_func(i, input_str);
}
