#include "../s21_SmartCalculator.h"

void push(Stack **top, long double number, int priority, type_t type) {
  Stack *new_struct = (Stack *)malloc(sizeof(Stack));
  new_struct->number = number;
  new_struct->priority = priority;
  new_struct->type = type;
  new_struct->next = *top;
  *top = new_struct;
}

void pop(Stack **top) {
  Stack *next_node = NULL;
  if (*top != NULL) {
    next_node = (*top)->next;
    free(*top);
    *top = next_node;
  }
}

Stack *peek(Stack **top) {
  Stack *node_top = NULL;
  if (*top != NULL) {
    node_top = *top;
  }
  return node_top;
}

int get_size_stack(Stack *top) {
  Stack *current = top;
  int size_stack = 0;
  while (current != NULL) {
    size_stack++;
    current = current->next;
  }
  return size_stack;
}

Stack *inverse_stack(Stack *top) {
  Stack *new_stack = NULL;
  Stack *current = top;
  while (current != NULL) {
    push(&new_stack, current->number, current->priority, current->type);
    current = current->next;
  }
  return new_stack;
}

void delete_stack(Stack **top) {
  while (*top != NULL) {
    pop(top);
  }
}