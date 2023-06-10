#include "../s21_SmartCalculator.h"

int validator(char *input_str, int res) {
  int n_str = strlen(input_str);
  if (n_str > 255) res = ERROR;
  bool flag_breckets = false;
  bool this_func = false;
  bool amount_brackets = false;
  for (int i = 0; input_str[i] != '\0' && res == SUCCES; i++) {
    if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '*' ||
        input_str[i] == '/' || input_str[i] == '^') {
      res = check_math_operations(i + 1, input_str, res, 0, flag_breckets);
    } else if ((input_str[i] == '(' || input_str[i] == ')')) {
      if (input_str[i] == '(' && !amount_brackets) {
        amount_brackets = true;
        res = check_amount_brackets(i, input_str, res);
      }
      res = check_brackets(i, input_str, res, this_func);
      flag_breckets = true;
      if (input_str[i] == ')') this_func = false;
    } else if (input_str[i] == '.') {
      res = check_dot(i, input_str, res, 1, 0);
    } else if (input_str[i] == 'm') {
      res = check_mod(i, input_str, res);
    } else if (!(check_trigonometry_functions_and_x(i, input_str, 1, 0))) {
      res = check_work_trigonometry(&i, input_str, res);
      this_func = true;
    } else if (_check_number(input_str, i) && i != 0 && input_str[i] != 'x') {
      if (input_str[i - 1] == ')') res = FAILURE;
    } else if (input_str[i] == 'I' || input_str[i] == 'N')
      res = FAILURE;
    else if (input_str[i] == 'x')
      res = check_x(input_str, res);
  }
  return res;
}

int check_amount_brackets(int i, char *input_str, int res) {
  int counter_right_brackets = 0;
  int counter_left_brackets = 0;
  for (; input_str[i] != '\0' && res != FAILURE; i++) {
    if (input_str[i] == ')') counter_right_brackets++;
    if (input_str[i] == '(') counter_left_brackets++;
  }
  if (counter_left_brackets != counter_right_brackets) res = FAILURE;
  return res;
}

int check_x(char *input_str, int res) {
  for (int i = 0; input_str[i] != '\0'; i++) {
    if (_check_number(input_str, i) && input_str[i + 1] == 'x')
      res = FAILURE;
    else if (input_str[i] == 'x' && _check_number(input_str, i + 1))
      res = FAILURE;
  }
  return res;
}

// Будут проблемы с утечками учесть это
int check_math_operations(int i, char *input_str, int res, int *check_dot,
                          bool flag_breckets) {
  int n = 0;
  if (i != 0) n = 1;
  if ((input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '*' ||
       input_str[i] == 'm' || input_str[i] == ')' || input_str[i] == '/' ||
       input_str[i] == '\0' || input_str[i] == '.' || input_str[i] == '^') &&
      !check_unary_minus(i - 1 + n, input_str) &&
      !check_unary_plus(i - 1 + n, input_str))
    res = FAILURE;
  else if (i - 2 < 0 && input_str[i - 1] != '-' && input_str[i - 1] != '+' &&
           check_dot == 0)
    res = FAILURE;
  else if ((!_check_number(input_str, i)) &&
           (check_trigonometry_functions_and_x(i, input_str, 0, 0) &&
            input_str[i] != '(' && check_dot == 0) &&
           !check_unary_minus(i - 1 + n, input_str) &&
           !check_unary_plus(i - 1 + n, input_str))
    res = FAILURE;
  else if ((!_check_number(input_str, i - 2)) && input_str[i - 2] != 'x' &&
           check_dot == 0 && i - 1 != 0 && flag_breckets != true &&
           !check_unary_minus(i - 2 + n, input_str) &&
           !check_unary_plus(i - 2 + n, input_str)) {
    res = FAILURE;
  }
  return res;
}

int check_brackets(int i, char *input_str, int res, bool this_func) {
  int check_math_operation = 1;
  if (input_str[i] == ')' &&
      ((!_check_number(input_str, i - 1)) &&
       (check_trigonometry_functions_and_x(i - 1, input_str, 0, 0)) &&
       this_func == false) &&
      input_str[i - 1] != ')') {
    res = FAILURE;
  } else if (input_str[i] == '(' && input_str[i + 1] == ')') {
    res = FAILURE;
  } else if (i != 0 && input_str[i] == '(' && input_str[i - 1] == ')')
    res = FAILURE;
  else if (input_str[i] == '(' && !(_check_number(input_str, i + 1)) &&
           input_str[i + 1] != '-' && input_str[i + 1] != '+' &&
           (check_trigonometry_functions_and_x(i + 1, input_str, 0, 0)))
    res = FAILURE;
  else if (input_str[i] == '(' &&
           ((_check_number(input_str, i - 1)) && input_str[i + 1] != '-' &&
            input_str[i + 1] != '+' &&
            (check_trigonometry_functions_and_x(i + 1, input_str, 0, 0))) &&
           input_str[i + 2] == ')') {
    int not_check_x = 1;
    if (i - 3 < 0) i++;
    if (check_trigonometry_functions_and_x(i - 3, input_str, not_check_x, 0))
      res = FAILURE;
  } else if (input_str[i] == '(' &&
             check_math_operations(i, input_str, res, &check_math_operation, 0))
    res = FAILURE;
  return res;
}

int check_dot(int i, char *input_str, int res, int n, int check_dot) {
  int checks_dot = 1;
  if (check_math_operations(i + n, input_str, res, &check_dot, 0) == 1)
    res = FAILURE;
  else if (!(_check_number(input_str, i + 1)) && check_dot == 0)
    res = FAILURE;
  else if (check_math_operations(i + n, input_str, res, &checks_dot, 0) &&
           check_dot == 0)
    res = FAILURE;
  else if (check_dot == 0) {
    i++;
    for (; input_str[i] != '\0' && res != FAILURE &&
           math_operations(&i, input_str, FAILURE);
         i++) {
      if (input_str[i] == '.') res = FAILURE;
    }
  }
  return res;
}

int check_mod(int i, char *input_str, int res) {
  if (check_dot(i, input_str, res, 3, 1)) res = FAILURE;
  return res;
}

int check_work_trigonometry(int *i, char *input_str, int res) {
  if (*i != 0) {
    bool this_is_math_oper = false;
    bool this_is_left_brack = false;
    if (*i != 1) *i -= 1;
    if (input_str[*i] == '-' || input_str[*i] == '+' || input_str[*i] == '*' ||
        input_str[*i] == '/' || input_str[*i] == '^' || input_str[*i] == '(') {
      if (input_str[*i] == '(') this_is_left_brack = true;
      this_is_math_oper = true;
    }
    if (this_is_math_oper &&
        ((!_check_number(input_str, *i - 1)) &&
         check_trigonometry_functions_and_x(*i - 1, input_str, 1, 1)) &&
        input_str[*i - 1] != ')' && input_str[*i - 1] != '(') {
      res = FAILURE;
    } else if (this_is_left_brack &&
               ((_check_number(input_str, *i - 1)) ||
                (input_str[*i - 1] != '/' && input_str[*i - 1] != '*' &&
                 input_str[*i - 1] != '-' && input_str[*i - 1] != '+' &&
                 input_str[*i - 1] != '^' &&
                 check_trigonometry_functions_and_x(*i - 1, input_str, 1,
                                                    1)))) {
      res = FAILURE;
    } else if ((_check_number(input_str, *i)) || input_str[*i] == ')')
      res = FAILURE;
    *i += 1;
  }
  _iterations_str_for_func(i, input_str);
  return res;
}

bool check_trigonometry_functions_and_x(int i, char *input_str, int not_check_x,
                                        int last_symb) {
  bool flag = true;
  if (((input_str[i] == 't' || input_str[i] == 'a' || input_str[i] == 'l' ||
        input_str[i] == 'c' || input_str[i] == 's') ||
       (input_str[i] == 'x' && not_check_x == 0)) &&
      last_symb == 0)
    flag = false;
  else if ((input_str[i] == 'n' || input_str[i] == 'g' || input_str[i] == 's' ||
            input_str[i] == 't') &&
           last_symb == 1)
    flag = false;
  return flag;
}

void _iterations_str_for_func(int *i, char *input_str) {
  if (input_str[*i] == 'a' ||
      (input_str[*i] == 's' && input_str[*i + 1] == 'q'))
    *i += 3;
  else if (input_str[*i] == 'l' && input_str[*i + 1] == 'n')
    *i += 1;
  else
    *i += 2;
}

bool _check_number(char *input_str, int i) {
  bool number = false;
  if (input_str[i] >= '0' && input_str[i] <= '9') number = true;
  return number;
}