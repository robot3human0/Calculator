#ifndef SRC_BACK_STACK_H_
#define SRC_BACK_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

typedef struct Stack_t {
  char data;
  struct Stack_t *next;
} Stack_t;

typedef struct Double_stack {
  double data;
  struct Double_stack *next;
} Double_stack;

Stack_t *new_node(char data);
void push(Stack_t **stack, char data);
char pop(Stack_t **stack);
char peek(Stack_t *stack);

Double_stack *new_num(double data);
void push_num(Double_stack **stack, double data);
double pop_num(Double_stack **stack);

#endif  //  SRC_BACK_STACK_H_
