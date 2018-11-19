#include "queue.h"

/*
  Private Implementation of Queue Node
*/
struct queue_node{
  void *data;
  struct queue_node *next;
};

/*
  Helper Functions for internal queue node
*/

struct queue_node *createNode(void *data, int elementSize){
  assert(data);
  struct queue_node *new_node = (struct queue_node *)malloc(sizeof(struct queue_node));
  assert(new_node);
  new_node->data = (void *)malloc(elementSize);
  memcpy(new_node->data, data, elementSize);
  new_node->next = NULL;
  return new_node;
}

struct queue_node* free_qnode(struct queue_node* qnode){
  struct queue_node *temp = qnode->next;
  assert(qnode->data);
  free(qnode->data);
  assert(qnode);
  free(qnode);
  qnode = NULL;
  return temp;
}

Queue *createQueue(int elementSize){
  Queue *q = (Queue *)malloc(sizeof(Queue));
  assert(q);
  q->elementSize = elementSize;
  q->numElements = 0;
  q->qnode = NULL;
  return q;
}

int queueDestroy(Queue *q){
  if(q == NULL){
    return 0;
  }
  assert(q);
  struct queue_node *temp = q->qnode;
  while(temp != NULL){
    temp = free_qnode(temp);
  }
  free(q);
  return 1;
}

int enqueue(Queue *q, void *data){
  assert(q);
  struct queue_node *new_node;
  struct queue_node *temp = q->qnode;
  new_node = createNode(data, q->elementSize);
  if(temp == NULL){
    q->qnode = new_node;
  }
  else{
    for(int i = 0;i < q->numElements-1; i++){
      temp = temp->next;
    }
    temp->next = new_node;
  }
  q->numElements++;
  return 1;
}

int dequeue(Queue *q, void *target){
  assert(q);
  assert(target);
  if(q->numElements == 0){
    return 0;
  }
  memcpy(target, q->qnode->data, q->elementSize);
  q->qnode = free_qnode(q->qnode);
  q->numElements--;
  return 1;
}

int front(Queue *q, void *target){
  assert(q);
  assert(target);
  if(q->numElements == 0){
    return 0;
  }
  memcpy(target, q->qnode->data, q->elementSize);
  return 1;
}

int back(Queue *q, void *target){
  assert(q);
  assert(target);
  if(q->numElements == 0){
    return 0;
  }
  struct queue_node *temp = q->qnode;
  for(int i = 0;i < q->numElements-1; i++){
    temp = temp->next;
  }
  memcpy(target, temp->data, q->elementSize);
  return 1;
}

void printQueue(Queue *q){
  assert(q);
  assert(q->qnode);
  struct queue_node *temp = q->qnode;
  while(temp->next != NULL){
    printf("%s->", (char *)temp->data);
    temp = temp->next;
  }
  printf("\n");
}
