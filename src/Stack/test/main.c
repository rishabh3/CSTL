#include "../src/stack.h"


int intCompare(const void* a, const void* b) {
  int *ia = (int*)a;
  int *ib = (int*)b;
  return *ia < *ib;
}

int floatCompare(const void* a, const void* b) {
  float *ia = (float*)a;
  float *ib = (float*)b;
  return *ia < *ib;
}

int main() {
  Stack *s = createStack(sizeof(float), 3);
  assert(s);
  assert(s->memberSize == sizeof(float));
  assert(s->totalElements == 3);
  float a=4.1f,b=5.2f,c=2.3f;
  float d;int r;
 
  r = stackPush(s, (void*)&a);
  assert(s->top == 0);
  assert(r == 0);
 
  r = stackPush(s, (void*)&b);
  assert(s->top == 1);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(r == 0);
  assert(s->top == 0);
  assert(d == 5.2f);

  r = stackTop(s, (void*)&d);
  assert(r == 0);
  assert(s->top == 0);
  assert(d == 4.1f);

  r = stackPush(s, (void*)&c);
  assert(s->top == 1);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == 0);
  assert(d == 2.3f);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == -1);
  assert(d == 4.1f);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == -1);
  assert(r == 1);

  r = stackTop(s, (void*)&d);
  assert(s->top == -1);
  assert(r == 1);

  r = stackPush(s, (void*)&a);
  assert(s->top == 0);
  assert(r == 0);

  r = stackPush(s, (void*)&b);
  assert(s->top == 1);
  assert(r == 0);

  r =stackPush(s, (void*)&c);
  assert(s->top == 2);
  assert(r == 0);

  r =stackPush(s, (void*)&c);
  assert(s->top == 3);
  assert(r == 0);
  assert(s->totalElements == 6);

  r = getMax(s, (void*)&d, floatCompare);
  assert(r == 0);
  assert(s->top == 3);
  assert(d == 2.3f);

  r = stackDestroy(s);
  assert(r == 0);
	
  printf("success\n");
}
