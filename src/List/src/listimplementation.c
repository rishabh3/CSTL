#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

void list_new(list *list, int elementSize, freeFunction freeFn)
{
  /*
    this function creates a new list with some of the properties mentioned above
    @params:
            list *list: in-out : Pointer to list
            int elementSize: in : Size of the element type
            freeFunction freeFn: in-out: Function pointer to free function
    @return-type:
            void
  */
  assert(elementSize > 0);
  list->logicalLength = 0;
  list->elementSize = elementSize;
  list->head = list->tail = NULL;
  list->freeFn = freeFn;
}

void list_destroy(list *list)
{
  /*
    this function destroys the list
    @params:
            list *list: in-out : Pointer to list
    @return-type:
            void
  */
  listNode *current;
  while(list->head != NULL) {
    current = list->head;
    list->head = current->next;

    if(list->freeFn) {
      list->freeFn(current->data);
    }

    free(current->data);
    free(current);
  }
}

void list_prepend(list *list, void *element)
{
  /*
    this function prepends elemnet to the list
    @params:
            list *list: in-out : Pointer to list
            void *element: in : Element to be prepended
    @return-type:
            void
  */
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  memcpy(node->data, element, list->elementSize);

  node->next = list->head;
  list->head = node;

  // first node?
  if(!list->tail) {
    list->tail = list->head;
  }

  list->logicalLength++;
}

void list_append(list *list, void *element)
{
  /*
    this function appends elemnet to the list
    @params:
            list *list: in-out : Pointer to list
            void *element: in : Element to be prepended
    @return-type:
            void
  */
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  node->next = NULL;

  memcpy(node->data, element, list->elementSize);

  if(list->logicalLength == 0) {
    list->head = list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  list->logicalLength++;
}

void list_for_each(list *list, listIterator iterator)
{
  /*
    this function iterates over the list
    @params:
            list *list: in-out : Pointer to list
            listIterator iterator: Function pointer to the iterator function
    @return-type:
            void
  */
  assert(iterator != NULL);

  listNode *node = list->head;
  bool result = TRUE;
  while(node != NULL && result) {
    result = iterator(node->data);
    node = node->next;
  }
}

void list_head(list *list, void *element, bool removeFromList)
{
  /*
    this function retrieves the head element and removes it from list if specified
    @params:
            list *list: in-out : Pointer to list
            void *element: out : Pointer to store the retrieved element
            bool removeFromList: in: specifies to delete the element
    @return-type:
            void
  */
  assert(list->head != NULL);

  listNode *node = list->head;
  memcpy(element, node->data, list->elementSize);

  if(removeFromList) {
    list->head = node->next;
    list->logicalLength--;

    free(node->data);
    free(node);
  }
}

void list_tail(list *list, void *element)
{
  /*
    this function retrieves the head element
    @params:
            list *list: in-out : Pointer to list
            void *element: out : Pointer to store the retrieved element
    @return-type:
            void
  */
  assert(list->tail != NULL);
  listNode *node = list->tail;
  memcpy(element, node->data, list->elementSize);
}

int list_size(list *list)
{
  /*
    this function returns the size of the list
    @params:
            list *list: in-out : Pointer to list
    @return-type:
            int
  */
  if(list == NULL)
	return 0;
  return list->logicalLength;
}
