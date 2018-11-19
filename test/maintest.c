#include "pair.h"
#include "stack.h"
#include "list.h"
#include "vec.h"
#include "queue.h"
#include "pqueue.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define PRINT(x) printf(x)

int intCompare(const void* a, const void* b) {
  int *ia = (int*)a;
  int *ib = (int*)b;
  return *ia < *ib;
}

void list_with_ints();
void list_with_strings();
void list_with_floats();

bool iterate_int(void *data);
bool iterate_string(void *data);
bool iterate_float(void *data);
void free_string(void *data);

void test_pair()
{
  // PRINT("TEST for PAIR\n");
  int iterate = 0;
  PAIR_int *mypair = NULL;
  PAIR_int *myspair = NULL;
  while(iterate==0)
  {
    PRINT("1.Construction 2.Swap 3.Compare 4. Modification 5.Destruction\n");
    int func=-1;
    scanf("%d",&func);
    switch(func)
    {
      case 1 :
        PRINT("TEST for construction\n");
        if(mypair != NULL || myspair != NULL){
          destroy_pair_int(mypair);
          mypair = NULL;
          destroy_pair_int(myspair);
          myspair = NULL;
        }
        mypair = make_pair_int(10,20);
        myspair = make_pair_int(20, 30);
        // printf("Before Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
        PRINT("TEST CASE PASSED!\n");
        break;

      case 2:
        PRINT("TEST for swap\n");
        if(mypair == NULL || myspair == NULL){
          PRINT("Error: First Create Pair\n");
          break;
        }
        assert(get_first_int(mypair) == 10 && get_second_int(mypair) == 20);
        swap_int(mypair);
        //printf("After Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
        assert(get_first_int(mypair) == 20 && get_second_int(mypair) == 10);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 3:
        PRINT("TEST for compare\n");
        if(mypair == NULL || myspair == NULL){
          PRINT("Error: First Create Pair\n");
          break;
        }
        assert(compare_int(mypair, myspair) == -1);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 4:
        PRINT("TEST for modification\n");
        if(mypair == NULL || myspair == NULL){
          PRINT("Error: First Create Pair\n");
          break;
        }
        modify_pair_int(mypair, 20, 30);
        assert(get_first_int(mypair) == 20 && get_second_int(mypair) == 30);
        assert(compare_int(mypair, myspair) == 0);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 6:
        PRINT("TEST for destruction\n");
        if(mypair == NULL || myspair == NULL){
          PRINT("Error: First Create Pair\n");
          break;
        }
        destroy_pair_int(mypair);
        mypair = NULL;
        destroy_pair_int(myspair);
        myspair = NULL;
        PRINT("TEST CASE PASSED!\n");
        break;

      default:
        iterate = 1;
    }
  }
  PRINT("SUCCESS! ALL TEST CASES PASSED\n");
}

void test_stack()
{
  PRINT("TEST for STACK\n");
  int iterate = 0;
  Stack *s = NULL;
  while(iterate==0)
  {
    PRINT("1.Construction 2.Push 3.Pop 4.Top 5.MaxElements 6.Destruction\n");
    int func=-1;
    scanf("%d",&func);
    switch(func)
    {
      case 1:
        PRINT("TEST for construction\n");
        if(s != NULL){
          stackDestroy(s);
          s = NULL;
        }
        s = createStack(sizeof(float), 3);
        assert(s);
        assert(s->memberSize == sizeof(float));
        assert(s->totalElements == 3);
        float a=4.1f,b=5.2f,c=7.2f;
        float d;int r;
        PRINT("TEST CASE PASSED!\n");
        break;

      case 2:
        PRINT("TEST for push\n");
        if(s == NULL){
          PRINT("Error: First Create the Stack\n");
          break;
        }
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
        if(s == NULL){
          PRINT("Error: First Create the Stack\n");
          break;
        }
        r = stackPop(s, (void*)&d);
        assert(r == 0);
        assert(s->top == 0);
        assert(d == 5.2f);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 4:
        PRINT("TEST for top\n");
        if(s == NULL){
          PRINT("Error: First Create the Stack\n");
          break;
        }
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
        if(s == NULL){
          PRINT("Error: First Create the Stack\n");
          break;
        }
        r = getMax(s, (void*)&d, intCompare);
        assert(r == 0);
        assert(s->top == 3);
        assert(d == 7.2f);
        PRINT("TEST CASE PASSED!\n");
        break;

      case 6:
        PRINT("TEST for destruction\n");
        if(s == NULL){
          PRINT("Error: First Create the Stack\n");
          break;
        }
        r = stackDestroy(s);
        s = NULL;
        assert(r == 0);
        PRINT("TEST CASE PASSED!\n");
        break;

      default:
        iterate = 1;
    }
  }
  PRINT("SUCCESS! ALL TEST CASES PASSED\n");
}
void test_list()
{
  int iterate = 0;
  while(iterate==0)
  {
    PRINT("1.List With Ints  2.List With Strings  3.List With Floats\n");
    int func=-1;
    scanf("%d",&func);
    switch(func)
    {
      case 1:
        list_with_ints();
        break;
      case 2:
        list_with_strings();
        break;
      case 3:
        list_with_floats();
        break;
      default:
        iterate = 1;
    }
  }
  PRINT("SUCCESS! ALL TEST CASES PASSED!\n");
}
void test_vec()
{
  int iterate = 0;
  vector(char) x = NULL;vector(char) y = NULL;
  while(iterate==0)
  {
    PRINT("1.Construction 2.Append 3.Get 4.Pop 5.Extend 6.Current Size 7.Maximum Size 8.Destruction\n");
    int func=-1;
    scanf("%d",&func);
    switch(func)
    {
      case 1 :PRINT("Test for Vector construction\n");
        if(x != NULL || y != NULL){
          free_vector(x);// free works here
          x = NULL;
          free_vector(y);
          y = NULL;
        }
        x = new_vector(char);
        y = new_vector(char);
        PRINT("Test Case Passed\n");
        break;

      case 2:PRINT("Test for Vector Append\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        for(int i = 0; i < 14; i++)
        {
          x->append(x, 'a'); //append working here
          y->append(y,'b');
        }
        PRINT("Test Case Passed\n");
        break;

      case 3:PRINT("Test for Vector Get\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        for(int i = 0; i < x->size(x); i++) //size working here
        {
          printf("%c\n", x->get(x, i));//get working here
        }
        PRINT("Test Case Passed\n");
        break;

      case 4:PRINT("Test for Vector Pop\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        x->pop(x);
        x->pop(x); //pop works here
        PRINT("Test Case Passed\n");
        break;

      case 5:PRINT("Test for Vector Extend\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        y->extend(y,x);// extends works here
        printf("Y\n");
        for(int i = 0; i < y->size(y); i++) //size working here
        {
          printf("%c\n", y->get(y, i));
        }
        PRINT("Test Case Passed\n");
        break;

      case 6:PRINT("Test for Vector Size\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        printf("Current Size: %u\n", y->size(y)); //size works here
        PRINT("Test Case Passed\n");
        break;

      case 7:PRINT("Test for Vector Capacity\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        printf("Max Size: %u\n", y->max_size(y)); //max_size works here
        PRINT("Test Case Passed\n");
        break;

      case 8:PRINT("Test for Vector Destruction\n");
        if(x == NULL || y == NULL){
          PRINT("Error: First Create the Vector\n");
          break;
        }
        free_vector(x);// free works here
        x = NULL;
        free_vector(y);
        y = NULL;
        PRINT("Test Case Passed\n");
        break;
      default:
        iterate = 1;
    }
  }
  printf("ALL TEST CASES WORKING!");
}


void test_queue()
{
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


int cmp_floats(const void *val1, const void *val2) {
    return *(float*) val1 - *(float*) val2;
}

int cmp_ints(const void *val1, const void *val2)
{
	return *(int*) val1 - *(int*) val2;
}

void test_pqueue(){
  PQueue* pq = pqueue_new(cmp_floats, 200);
  PQueue *pq1 = pqueue_new(cmp_ints , 200);
  float x = 100.0, y = 50.2, z = 300.3, k = 100.9;
  float w = 1000.0;
  int a = 10, b= 20, c = 30, d = 40, e = 50;

  pqueue_enqueue(pq, &x);
  pqueue_enqueue(pq, &y);
  pqueue_enqueue(pq, &z);
  pqueue_enqueue(pq, &k);
  pqueue_enqueue(pq, &w);
  pqueue_enqueue(pq1, &a);
  pqueue_enqueue(pq1, &b);
  pqueue_enqueue(pq1, &c);
  pqueue_enqueue(pq1, &d);
  pqueue_enqueue(pq1, &e);

  int i = 0;
  for(;i<5;++i)
      printf("%f\n", *(float*) pqueue_dequeue(pq));
  i = 0;
  for(;i<5;++i)
      printf("%d\n", *(int*) pqueue_dequeue(pq1));

  pqueue_delete(pq);
  pqueue_delete(pq1);

}


int main()
{
  int ds=-1;
  while(1)
  {
    printf("1. Test for Pair\n2.Test for Stack\n3.Test for List\n4.Test for Vector\n5.Test for Queue\n6.Test for Priority Queue\n9.Exit\n");
    scanf("%d",&ds);
    switch(ds)
    {
      case 1 : test_pair();
               break;
      case 2 : test_stack();
              break;
      case 3 : test_list();
              break;
      case 4 : test_vec();
              break;
      case 5 : test_queue();
              break;
      case 6: test_pqueue();
              break;
      case 9 : exit(0);
      default : printf("Invalid Input for Data Structure");
    }
  }
  return 0;
}

void list_with_ints()
{
  //int numbers = 10;
 // printf("Generating list with the first %d positive numbers...\n", numbers);
 	PRINT("TEST for int list\n");
  int numbers = 10;
  list list;
  PRINT("TEST for int list creation\n");
  list_new(&list, sizeof(int), NULL);

  for(int i = 1; i <= numbers; i++) {
    list_append(&list, &i);
  }
	assert(list_size(&list) == numbers);
	PRINT("TEST CASE PASSED!\n");

	PRINT("TEST for int list iteration\n");
  list_for_each(&list, iterate_int);
  PRINT("\nTEST CASE PASSED!\n");


  PRINT("TEST for int list destruction\n");
  list_destroy(&list);
  PRINT("TEST CASE PASSED!\n");
}

void list_with_strings()
{
	PRINT("TEST for string list\n");
  int numNames = 5;
  const char *names[] = { "David", "Kevin", "Michael", "Craig", "Jimi" };
  /*int numNames;
  printf("Enter the number of items");
  scanf("%d",&numNames);
  const char *elem[] = { "" };
  printf("Enter the list items");*/
  PRINT("TEST for string list creation\n");
  int i;
  list list;
  list_new(&list, sizeof(char *), free_string);

  char *name;
  for(i = 0; i < numNames; i++) {
    //scanf("%s",elem[i]);
    name = strdup(names[i]);
    list_append(&list, &name);
  }
  assert(list_size(&list) == 5);
  PRINT("TEST CASE PASSED!\n");


 	PRINT("TEST for string list iteration\n");
  list_for_each(&list, iterate_string);
  PRINT("\nTEST CASE PASSED!\n");

  PRINT("TEST for string list destruction\n");
  list_destroy(&list);
  PRINT("TEST CASE PASSED!\n");
}

void list_with_floats()
{
  //int numbers = 10;
 // printf("Generating list with the first %d positive numbers...\n", numbers);
  PRINT("TEST for float list\n");
  int numbers = 10;
  //float elem;
  PRINT("TEST for float list creation\n");
  list list;
  list_new(&list, sizeof(float), NULL);

	for(float i = 1.0f; i <= (float)numbers; i++) {
    list_append(&list, &i);
  }
  assert(list_size(&list) == 10);
  PRINT("TEST CASE PASSED!\n");

	PRINT("TEST for float list iteration\n");
  list_for_each(&list, iterate_float);
  PRINT("\nTEST CASE PASSED!\n");

  PRINT("TEST for float list destruction\n");
  list_destroy(&list);
  PRINT("TEST CASE PASSED!\n");
}

bool iterate_int(void *data)
{
  //printf("Found value: %d\n", *(int *)data);
  printf("%d-> ", *(int *)data);
  return TRUE;
}

bool iterate_string(void *data)
{
 // printf("Found string value: %s\n", *(char **)data);
   printf("%s-> ", *(char **)data);
  return TRUE;
}

bool iterate_float(void *data)
{
  //printf("Found value: %d\n", *(int *)data);
  printf("%f-> ", *(float *)data);
  return TRUE;
}


void free_string(void *data)
{
  free(*(char **)data);
}
