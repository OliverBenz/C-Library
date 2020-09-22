#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node node;
typedef struct stack stack;

stack *stack_init();

bool stack_empty(stack *stack);

size_t stack_size(stack *stack);

void *stack_back(stack *stack);

void stack_push_back(stack *stack, void *val);

void *stack_pop_back(stack *stack);

void stack_free(stack *stack);

#endif // MY_STACK_H
