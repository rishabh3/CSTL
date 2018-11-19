#include "../src/queue.h"

int main(){
  printf("TEST for QUEUE\n");
  int iterate = 0;
  float a, b, c, d;
  int r;
  Queue *q = NULL;
  while(iterate == 0){
    printf("1.Construction 2.Enqueue 3.Dequeue 4.Front 5.Back 6.Destruction\n");
    int func = -1;
    scanf("%d", &func);
    switch(func){
      case 1:
        printf("TEST for construction\n");
        q = createQueue(sizeof(float));
        assert(q);
        assert(q->elementSize == sizeof(float));
        assert(q->numElements == 0);
        printf("TEST CASE PASSED!\n");
        break;
      case 2:
        printf("TEST for enqueue\n");
        assert(q != NULL);
        a = 4.1f; b=7.2f; c= 6.1f;
        r = enqueue(q, (void*)&a);
        assert(q->numElements == 1);
        assert(r == 1);

        r = enqueue(q, (void*)&b);
        assert(q->numElements == 2);
        assert(r == 1);

        r = enqueue(q, (void*)&c);
        assert(q->numElements == 3);
        assert(r == 1);
        printf("TEST CASE PASSED!\n");
        break;
      case 3:
        printf("TEST for dequeue\n");
        assert(q != NULL);
        r = dequeue(q, (void*)&d);
        assert(r == 1);
        assert(q->numElements == 2);
        assert(d == 4.1f);
        printf("TEST CASE PASSED!\n");
        break;
      case 4:
        printf("TEST for front\n");
        assert(q != NULL);
        r = front(q, (void *)&d);
        assert(r == 1);
        assert(q->numElements == 2);
        assert(d == 7.2f);
        printf("TEST CASE PASSED\n");
        break;
      case 5:
        printf("TEST for back\n");
        assert(q != NULL);
        r = back(q, (void *)&d);
        assert(r == 1);
        assert(q->numElements == 2);
        assert(d == 6.1f);
        printf("TEST CASE PASSED\n");
        break;
      case 6:
        printf("TEST for destruction\n");
        assert(q != NULL);
        printQueue(q);
        r = queueDestroy(q);
        assert(r == 1);
        printf("TEST CASE PASSED\n");
        q = NULL;
        break;
      default:
        iterate = 1;

    }
  }
  printf("SUCCESS! ALL TEST CASES PASSED\n");
}
