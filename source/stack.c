#include "stack.h"

typedef struct node{
	void* value;
	node* next;
} node;

typedef struct stack{
	size_t size;
	node* latest;
} stack;

stack *stack_init(){
	stack* s = (stack*)malloc(sizeof(stack));
	s->size = 0;
	s->latest = NULL;

	return s;
}

bool stack_empty(stack* stack){
	return stack->size == 0;
}

size_t stack_size(stack* stack){
	return stack->size;
}

void* stack_back(stack* stack){
	return stack->latest->value;
}

void stack_push_back(stack* stack, void* value){
	node* n = (node*)malloc(sizeof(node));
	n->next = stack->latest;
	n->value = value;
	
	stack->size++;
	stack->latest = n;
}

void* stack_pop_back(stack* stack){
	if(stack->size == 0)
		return NULL;	

	node* temp = stack->latest;
	void* val = temp->value;

	stack->size--;
	stack->latest = temp->next;
	free(temp);

	return val;
}

void stack_free(stack *stack){
	if(stack->size == 0){
		free(stack);
		return;
	}

	node* temp = stack->latest;
	node* temp1 = NULL;

	while(temp->next != NULL){
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	free(temp);	
	free(stack);
}
