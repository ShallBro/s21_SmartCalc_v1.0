#ifndef SRC_S21_SMARTCALCULATOR_H_
#define SRC_S21_SMARTCALCULATOR_H_
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { SUCCES = 0, FAILURE = 1, ERROR = 3 } logger;

typedef enum {
  NUMBER = 0,
  LEFT_BRACKET = 1,
  RIGHT_BRACKET = 2,
  X = 3,
  TAN = 4,
  ATAN = 5,
  LOG = 6,
  LN = 7,
  SQRT = 8,
  COS = 9,
  ACOS = 10,
  SIN = 11,
  ASIN = 12,
  MOD = 13,
  PLUS = 14,
  MINUS = 15,
  UNARY_MINUS = 16,
  DIV = 17,
  MULT = 18,
  EXP = 19,
} type_t;

typedef struct Stack {
  long double number;
  int priority;
  type_t type;
  struct Stack *next;
} Stack;

// Main function and calculate

double s21_calculator(char *input_str, char *output_res, double x);
double s21_calculate(Stack *polish_notation);
void s21_calc_two_operands_in_temp_stack(Stack **temp, Stack **polish_notation);
void s21_resolve_for_two_operands_math(double o1, double o2, double *res,
                                       int operation);
void s21_resolve_for_two_operands_functions(double o2, double *res,
                                            int operation);

// Validator functions

int validator(char *input_str, int res);
int check_math_operations(int i, char *input_str, int res, int *check_dot,
                          bool flag_breckets);
int check_brackets(int i, char *input_str, int res, bool this_func);
int check_dot(int i, char *input_str, int res, int n, int check_dot);
int check_mod(int i, char *input_str, int res);
int check_work_trigonometry(int *i, char *input_str, int res);
bool check_trigonometry_functions_and_x(int i, char *input_str, int not_check_x,
                                        int last_symb);
int check_amount_brackets(int i, char *input_str, int res);
int check_x(char *input_str, int res);

// Parser functions

void s21_parser(char *input_str, Stack **top, double x);
void parsing_numbers(int *i, char *input_str, Stack **top, double x);
void math_operations_priority(int *i, char *input_str, Stack **top);
bool math_operations(int *i, char *input_str, int not_check_brack);
void parse_trigonometry_func(int *i, char *input_str, Stack **top);
bool check_unary_minus(int i, char *input_str);
bool check_unary_plus(int i, char *input_str);

// Polish Notation functions

Stack *s21_polish_notation(Stack *input_str);
bool check_stack_functions(Stack **current_input);
bool check_stack_math_operation(Stack *current_input);
void moves_support_to_output_stack_in_brackets(Stack **support, Stack **output);
void moves_priority_stack_operator_in_sup(Stack **support,
                                          Stack **current_input,
                                          Stack **output);
int get_size_stack(Stack *top);

// Stack functions

void push(Stack **top, long double number, int priority, type_t type);
void pop(Stack **top);
Stack *peek(Stack **top);
Stack *inverse_stack(Stack *top);
void delete_stack(Stack **top);

// Support functions
void _iterations_str_for_func(int *i, char *input_str);
bool _check_number(char *input_str, int i);

#endif
