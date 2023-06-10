#include "../s21_SmartCalculator.h"

Stack *s21_polish_notation(Stack *input_str) {
  Stack *output = NULL;
  Stack *support = NULL;
  Stack *current_input = input_str;
  while (current_input != NULL) {
    if (current_input->type == NUMBER || current_input->type == X) {
      push(&output, current_input->number, 0, NUMBER);
    } else if (check_stack_functions(&current_input))
      push(&support, 0, 4, current_input->type);
    else if (current_input->type == UNARY_MINUS) {
      push(&output, 0, 0, NUMBER);
      push(&output, 0, 0, UNARY_MINUS);
    } else if (check_stack_math_operation(current_input)) {
      moves_priority_stack_operator_in_sup(&support, &current_input, &output);
    } else if (current_input->type == LEFT_BRACKET) {
      push(&support, 0, 0, LEFT_BRACKET);
    } else if (current_input->type == RIGHT_BRACKET) {
      moves_support_to_output_stack_in_brackets(&support, &output);
    }
    current_input = current_input->next;
  }
  while (support != NULL) {
    push(&output, 0, support->priority, support->type);
    pop(&support);
  }
  delete_stack(&input_str);
  output = inverse_stack(output);
  return output;
}

bool check_stack_functions(Stack **current_input) {
  bool function = false;
  int const_numbers[9] = {TAN, ATAN, LOG, LN, SQRT, COS, ACOS, SIN, ASIN};
  for (int i = 0; i < 9; i++) {
    if (const_numbers[i] == (int)(*current_input)->type) {
      function = true;
    }
  }
  return function;
}

bool check_stack_math_operation(Stack *current_input) {
  bool math_operation = false;
  int const_numbers[6] = {PLUS, MINUS, DIV, MULT, EXP, MOD};
  for (int i = 0; i < 6; i++) {
    if (const_numbers[i] == (int)current_input->type) {
      math_operation = true;
    }
  }
  return math_operation;
}

void moves_support_to_output_stack_in_brackets(Stack **support,
                                               Stack **output) {
  Stack *temp = peek(support);
  while (temp->type != LEFT_BRACKET) {
    push(output, temp->number, temp->priority, temp->type);
    pop(support);
    temp = peek(support);
  }
  pop(support);
}

void moves_priority_stack_operator_in_sup(Stack **support,
                                          Stack **current_input,
                                          Stack **output) {
  if (*support == NULL) {
    push(support, 0, (*current_input)->priority, (*current_input)->type);
  } else {
    while (*support != NULL &&
           (*support)->priority >= (*current_input)->priority) {
      push(output, 0, (*support)->priority, (*support)->type);
      pop(support);
      *support = peek(support);
    }
    push(support, 0, (*current_input)->priority, (*current_input)->type);
  }
}