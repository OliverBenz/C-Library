#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node node;
typedef struct queue queue;

queue *queue_init();

bool queue_empty(queue *queue);
size_t queue_size(queue *queue);
void *queue_front(queue *queue);
void *queue_back(queue *queue);
void queue_push_back(queue *queue, void *val);
void *queue_pop_front(queue *queue);
void queue_free(queue *queue);

#endif // MY_QUEUE_H
