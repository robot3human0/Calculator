#include "stack.h"

Stack_t *new_node(char data) {
  Stack_t *node = calloc(1, sizeof(Stack_t));
  node->data = data;
  return node;
}

void push(Stack_t **stack, char data) {
  Stack_t *node = new_node(data);
  node->next = *stack;
  *stack = node;
}

char pop(Stack_t **stack) {
  char ch;
  Stack_t *tmp = *stack;
  *stack = (*stack)->next;
  ch = tmp->data;
  free(tmp);
  return ch;
}

char peek(Stack_t *stack) { return stack->data; }

Double_stack *new_num(double data) {
  Double_stack *new_node = calloc(1, sizeof(Double_stack));
  new_node->data = data;
  return new_node;
}

void push_num(Double_stack **stack, double data) {
  Double_stack *new_node = new_num(data);
  new_node->next = *stack;
  *stack = new_node;
}

double pop_num(Double_stack **stack) {
  Double_stack *temp = *stack;
  double data = temp->data;
  *stack = (*stack)->next;
  free(temp);
  return data;
}
