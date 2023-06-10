#include "../s21_SmartCalculator.h"

double s21_calculator(char *input_str, char *output_res, double x) {
  int res = SUCCES;
  res = validator(input_str, res);
  double result = 0.0;
  if (res == FAILURE)
    strcpy(output_res, "INVALID INPUT");
  else if (res == ERROR)
    strcpy(output_res, "Enter less expression!");
  else if (res == SUCCES) {
    Stack *top = NULL;
    s21_parser(input_str, &top, x);
    Stack *new = inverse_stack(top);
    delete_stack(&top);
    Stack *polish_notation = s21_polish_notation(new);
    result = s21_calculate(polish_notation);
    if (isnan(result))
      strcpy(output_res, "NAN");
    else if (isinf(result))
      strcpy(output_res, "INF");
  }
  return result;
}

double s21_calculate(Stack *polish_notation) {
  Stack *temp = NULL;
  double result = 0.0;
  if (get_size_stack(polish_notation) > 1) {
    while (polish_notation != NULL) {
      if (polish_notation->type == NUMBER || polish_notation->type == X) {
        push(&temp, polish_notation->number, 0, NUMBER);
        pop(&polish_notation);
      } else if (check_stack_math_operation(polish_notation) ||
                 check_stack_functions(&polish_notation) ||
                 polish_notation->type == MOD) {
        push(&temp, 0, polish_notation->priority, polish_notation->type);
        pop(&polish_notation);
        s21_calc_two_operands_in_temp_stack(&temp, &polish_notation);
      } else if (polish_notation->type == UNARY_MINUS) {
        pop(&temp);
        pop(&polish_notation);
        polish_notation->number *= -1;
      }
      polish_notation = peek(&polish_notation);
      if (get_size_stack(polish_notation) == 1 &&
          polish_notation->type == NUMBER) {
        result = polish_notation->number;
        pop(&polish_notation);
      }
    }
  } else
    result = polish_notation->number;
  return result;
}

void s21_calc_two_operands_in_temp_stack(Stack **temp,
                                         Stack **polish_notation) {
  double o1 = 0.0;
  double o2 = 0.0;
  double res = 0.0;
  int operation = -1;
  int iterator_for = 3;
  if (check_stack_functions(temp)) {
    iterator_for = 2;
  }
  for (int i = 0; i < iterator_for; i++) {
    if (i == 0) {
      operation = (int)(*temp)->type;
    } else if (i == 1) {
      o2 = (*temp)->number;
    } else if (iterator_for != 2) {
      o1 = (*temp)->number;
    }
    pop(temp);
  }
  if (iterator_for != 2)
    s21_resolve_for_two_operands_math(o1, o2, &res, operation);
  else
    s21_resolve_for_two_operands_functions(o2, &res, operation);
  push(temp, res, 0, NUMBER);
  Stack *current_temp = *temp;
  while (current_temp != NULL) {
    push(polish_notation, current_temp->number, 0, NUMBER);
    current_temp = current_temp->next;
  }
  delete_stack(temp);
}

// Решение с математическими операциями
void s21_resolve_for_two_operands_math(double o1, double o2, double *res,
                                       int operation) {
  if (operation == PLUS)
    *res = o1 + o2;
  else if (operation == MINUS)
    *res = o1 - o2;
  else if (operation == MOD)
    *res = fmod(o1, o2);
  else if (operation == DIV)
    *res = o1 / o2;
  else if (operation == MULT)
    *res = o1 * o2;
  else if (operation == EXP)
    *res = pow(o1, o2);
}
// Решения с тригонометрическими функциями
void s21_resolve_for_two_operands_functions(double o2, double *res,
                                            int operation) {
  if (operation == TAN)
    *res = tan(o2);
  else if (operation == ATAN)
    *res = atan(o2);
  else if (operation == LOG)
    *res = log10(o2);
  else if (operation == LN)
    *res = log(o2);
  else if (operation == SQRT)
    *res = sqrt(o2);
  else if (operation == COS)
    *res = cos(o2);
  else if (operation == ACOS)
    *res = acos(o2);
  else if (operation == SIN)
    *res = sin(o2);
  else if (operation == ASIN)
    *res = asin(o2);
}
