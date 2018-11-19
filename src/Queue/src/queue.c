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
  /*
    This function creates a node with the data of size elementSize.
    param1: void * data
      Data to be entered.
    param2: int elementSize
      ElementSize of data to be entered.
    return: struct queue_node *
      Returns the newly created node.
  */
  assert(data);
  struct queue_node *new_node = (struct queue_node *)malloc(sizeof(struct queue_node));
  assert(new_node);
  new_node->data = (void *)malloc(elementSize);
  memcpy(new_node->data, data, elementSize);
  new_node->next = NULL;
  return new_node;
}

struct queue_node* free_qnode(struct queue_node* qnode){
  /*
    This function frees a node of the queue.
    param1: struct queue_node * qnode
      The node to be deleted
    return: struct queue_node *
      Returns the next node to the calle.

  */
  struct queue_node *temp = qnode->next;
  assert(qnode->data);
  free(qnode->data);
  assert(qnode);
  free(qnode);
  qnode = NULL;
  return temp;
}

Queue *createQueue(int elementSize){
  /*
    This function constructs the Queue containing elements of elementSize.
    param1: int elementSize
      Size of member elements.
    return: Queue *
      Returns the pointer to the newly created queue.
  */
  Queue *q = (Queue *)malloc(sizeof(Queue));
  assert(q);
  q->elementSize = elementSize;
  q->numElements = 0;
  q->qnode = NULL;
  return q;
}

int queueDestroy(Queue *q){
  /*
    This function destroys the queue.
    param1: Queue *q
      Pointer to the Queue to be destroyed.
    return: int
      Returns 1 on success and 0 on failure.
  */
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
  /*
    This function appends an element to the Queue.
    param1: Queue *q
      Pointer to the queue to append the element.
    param2: void *data
      Pointer to the data to be appended.
    return: int
      Returns 1 on success and 0 on failure.
  */
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
  /*
    This function pops an element from the Queue.
    param1: Queue *q
      Pointer to the queue to pop the element.
    param2: void *target
      Pointer to the target to store the data.
    return: int
      Returns 1 on success and 0 on failure.
  */
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
  /*
    This function peeks the Queue from front.
    param1: Queue *q
      Pointer to the queue to peek.
    param2: void *target
      Pointer to the target to store the data.
    return: int
      Returns 1 on success and 0 on failure.
  */
  assert(q);
  assert(target);
  if(q->numElements == 0){
    return 0;
  }
  memcpy(target, q->qnode->data, q->elementSize);
  return 1;
}

int back(Queue *q, void *target){
  /*
    This function peeks the Queue from back.
    param1: Queue *q
      Pointer to the queue to peek.
    param2: void *target
      Pointer to the target to store the data.
    return: int
      Returns 1 on success and 0 on failure.
  */
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
