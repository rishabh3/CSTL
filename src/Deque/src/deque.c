#include <stdlib.h>
#include <assert.h>
#include "deque.h"
//structure of each node in the queue
struct node_struct {
	struct node_struct *next;
	struct node_struct *prev;
	deque_val_type val;
};

//structure of queue
struct deque_struct {
	struct node_struct *head;
	struct node_struct *tail;
};

//allocate memory to the new queue using malloc
deque_type * deque_alloc() {
	deque_type *d = malloc(sizeof(deque_type));
	if (d != NULL)
		d->head = d->tail = NULL;
	return d;
}

//free the queue
void deque_free(deque_type *d) {
	free(d);
}

//checking if queue is empty
bool deque_is_empty(deque_type *d) {
	return d->head == NULL;
}

//add elements to the front of the queue
void deque_push_front(deque_type *d, deque_val_type v) {
	struct node_struct *n = malloc(sizeof(struct node_struct));
	assert(n != NULL);
	n->val = v;
	n->next = d->head;
	n->prev = NULL;
	if (d->tail == NULL) {
		d->head = d->tail = n;
	} else {
		d->head->prev = n;
		d->head = n;
	}
}


//add elements to the back of the queue
void deque_push_back(deque_type *d, deque_val_type v) {
	struct node_struct *n = malloc(sizeof(struct node_struct));
	assert(n != NULL);
	n->val = v;
	n->prev = d->tail;
	n->next = NULL;
	if (d->head == NULL) {
		d->head = d->tail = n;
	} else {
		d->tail->next = n;
		d->tail = n;
	}
}

//removes and returns front value of the queue
deque_val_type deque_pop_front(deque_type *d) {
	deque_val_type v = d->head->val;
	struct node_struct *n = d->head;
	if (d->head == d->tail)
		d->head = d->tail = NULL;
	else
		d->head = n->next;
	free(n);
	return v;
}


//removes and returns back value of the queue
deque_val_type deque_pop_back(deque_type *d) {
	deque_val_type v = d->tail->val;
	struct node_struct *n = d->tail;
	if (d->head == d->tail)
		d->head = d->tail = NULL;
	else
		d->tail = n->prev;
	free(n);
	return v;
}

//returns front value of the queue
deque_val_type deque_peek_front(deque_type *d) {
	return d->head->val;
}

//returns back value of the queue
deque_val_type deque_peek_back(deque_type *d) {
	return d->tail->val;
}

