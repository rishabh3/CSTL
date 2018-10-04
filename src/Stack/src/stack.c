#include "stack.h"

Stack* createStack(int memberSize, int totalElements) {
  /*
    this function creates a new stack with aforementioned properties
    @params:
            int memberSize: in : Size of the member
            int totalElements: in: Total elements to be placed in stack
    @return-type:
            Stack*: Pointer to Stack object
  */
  Stack *s = malloc(sizeof(Stack));
  assert(s);
  s->top = -1;
  s->memberSize = memberSize;
  s->totalElements = totalElements;
  s->data = malloc(totalElements*memberSize);
  return s;
}

int stackDestroy(Stack *s) {
  /*
    this function destroy the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
    @return-type:
            int
  */
  free(s->data);
  free(s);
  return 0;
}

int expandStack(Stack* s) {
  /*
    this function expands the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
    @return-type:
            int
  */
  //double total capacity of the stack
  s->data = realloc(s->data, s->totalElements * 2 * s->memberSize);
  assert(s->data);
  s->totalElements *= 2;
  return 0;
}

int stackPush(Stack *s,  void *data) {
  /*
    this function pushes elements on the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
            void *data: in: Data to be pushed
    @return-type:
            int
  */
  assert(s);
  assert(data);
  //check is the stack is full
  if (s->top == s->totalElements - 1) {
    //if full, call expand function to expand the size of the stack
    expandStack(s);
  }
  s->top++;
  //calculate starting location for the new element
  void* target = (char*)s->data+(s->top*s->memberSize);
  memcpy(target, data, s->memberSize);
  return 0;
}

int stackTop(Stack *s,  void *target) {
  /*
    this function returns the top of the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
            void* target: out: Places the top element on the target memory
    @return-type:
            int
  */
  assert(s);
  assert(target);
  if (s->top == -1) {
    return 1;
  }
  void* source = (char*)s->data+(s->top*s->memberSize);
  memcpy(target, source, s->memberSize);
  return 0;
}

int stackPop(Stack *s,  void *target) {
  /*
    this function pops the element from the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
            void* target: out: Places the popped element on the target memory
    @return-type:
            int
  */
  assert(s);
  assert(target);
  if (s->top == -1) {
    return 1;
  }
  void* source = (char*)s->data+(s->top*s->memberSize);
  s->top--;
  memcpy(target, source, s->memberSize);
  return 0;
}

int getMax(Stack *s, void* max, int (*compare)(const void *a, const void *b)) {
  /*
    this function gets the Maximum element in the stack
    @params:
            Stack* s: in-out: Pointer to stack to destroy
            void* max: out: Places the popped element on the target memory
            int (*compare): in: Function pointer to compare the elements
    @return-type:
            int
  */
  if(s->top == -1) {
    return 1;
  }
  void* maxTemp = s->data;
  int i = 1;
  while(i++ <= s->top) {
    void* b = (char*)s->data + s->memberSize*i;
    int result = compare(maxTemp, b);
    assert(result == 0 || result == 1);
    if(result == 1) {
      maxTemp = b;
    }
  }
  memcpy(max, maxTemp, s->memberSize);
  return 0;
}
