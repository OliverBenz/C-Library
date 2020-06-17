#include "queue.h"

typedef struct node{
	void* value;
	node* next;
} node;

typedef struct queue{
	size_t size;
	node* first;
} queue;

queue* queue_init(){
	queue* q = (queue*)malloc(sizeof(queue));
	q->size = 0;
	q->first = NULL;

	return q;
}

bool queue_empty(queue* queue){
	return queue->size == 0;
}

size_t queue_size(queue* queue){
	return queue->size;
}

void* queue_front(queue* queue){
	if(queue->size == 0)
		return NULL;
	return queue->first->value;
}

void* queue_back(queue* queue){
	if(queue->size == 0)
		return NULL;	
	
	node* temp = queue->first;
	while(temp->next != NULL)
		temp = temp->next;
	
	return temp->value;
}

void insertNode(node* ex, void *val){
	node* new = (node*)malloc(sizeof(node));
	new->value = val;
	new->next = NULL;
	ex->next = new;
}

void queue_push_back(queue* queue, void *val){	
	if(queue->size == 0){
		node* new = (node*)malloc(sizeof(node));	
		new->value = val;
		new->next = NULL;
		
		queue->first = new;	
		queue->size++;

		return;	
	}

	node* temp = queue->first;
	while(temp->next != NULL)
		temp = temp->next;

	insertNode(temp, val);
	queue->size++;
}

void* queue_pop_front(queue* queue){
	if(queue->size == 0)
		return NULL;	
	
	void* val = queue->first->value;
	node* first = queue->first;

	queue->first = first->next;
	queue->size--;

	free(first);

	return val;
}

void queue_free(queue* queue){
	if(queue->size == 0){
		free(queue);
		return;
	}

	node* temp = queue->first;
	node* temp1 = NULL;

	while(temp->next != NULL){
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	free(temp);
	free(queue);
}
