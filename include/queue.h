#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
  int elementSize;
  struct queue_node *qnode;
  int numElements;
} Queue;


Queue *createQueue(int elementSize);
int queueDestroy(Queue *q);
int enqueue(Queue *q, void *data);
int dequeue(Queue *q, void *target);
int front(Queue *q, void *target);
int back(Queue *q, void *target);
