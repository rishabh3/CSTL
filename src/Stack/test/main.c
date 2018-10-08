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

int main()
{
  PRINT("TEST for STACK\n");
  int iterate = 0;
  while(iterate==0)
  {
    PRINT("1.Construction 2.Push 3.Pop 4.Top 5.MaxElements 6.Destruction\n");
    int func=-1;
    scanf("%d",&func);
    switch(func)
    {
      case 1:
        PRINT("TEST for construction\n");
        Stack *s = createStack(sizeof(float), 3);
        assert(s);
        assert(s->memberSize == sizeof(float));
        assert(s->totalElements == 3);
        float a=4.1f,b=5.2f,c=7.2f;
        float d;int r;
        PRINT("TEST CASE PASSED!\n");
        break;
      
      case 2:
        PRINT("TEST for push\n");
        r = stackPush(s, (void*)&a);
        assert(s->top == 0);
        assert(r == 0);

        r = stackPush(s, (void*)&b);
        assert(s->top == 1);
        assert(r == 0);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 3:
        PRINT("TEST for pop\n");
        r = stackPop(s, (void*)&d);
        assert(r == 0);
        assert(s->top == 0);
        assert(d == 5.2f);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 4:
        PRINT("TEST for top\n");
        r = stackTop(s, (void*)&d);
        assert(r == 0);
        assert(s->top == 0);
        assert(d == 4.1f);

        r = stackPush(s, (void*)&c);
        assert(s->top == 1);
        assert(r == 0);

        r = stackPop(s, (void*)&d);
        assert(s->top == 0);
        assert(d == 7.2f);
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
        PRINT("TEST CASE PASSED!\n");
        break;

      case 5:
        PRINT("TEST for get max elements\n");
        r = getMax(s, (void*)&d, intCompare);
        assert(r == 0);
        assert(s->top == 3);
        assert(d == 7.2f);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 6:
        PRINT("TEST for destruction\n");
        r = stackDestroy(s);
        assert(r == 0);
        PRINT("TEST CASE PASSED!\n");
        break;
      
      default:
        iterate = 1;
    }
  }
  PRINT("SUCCESS! ALL TEST CASES PASSED\n");
}
