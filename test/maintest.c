#include "pair.h"
#include "stack.h"
#include "list.h"
#include "vec.h"

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


int main(){
  /*Test for pair*/
  PRINT("TEST for PAIR\n");
  PRINT("TEST for construction\n");
  PAIR_int *mypair = make_pair_int(10,20);
  PAIR_int *myspair = make_pair_int(20, 30);
  // printf("Before Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for swap\n");
  assert(get_first_int(mypair) == 10 && get_second_int(mypair) == 20);
  swap_int(mypair);
  //printf("After Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  assert(get_first_int(mypair) == 20 && get_second_int(mypair) == 10);
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for compare\n");
  assert(compare_int(mypair, myspair) == -1);
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for modification\n");
  modify_pair_int(mypair, 20, 30);
  assert(get_first_int(mypair) == 20 && get_second_int(mypair) == 30);
  assert(compare_int(mypair, myspair) == 0);
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for destruction\n");
  destroy_pair_int(mypair);
  destroy_pair_int(myspair);
  PRINT("TEST CASE PASSED!\n");

  PRINT("SUCCESS! ALL TEST CASES PASSED\n");
	/*Test for Pair Ends*/

	/*Test for Stack*/
  PRINT("TEST for STACK\n");
  PRINT("TEST for construction\n");
  Stack *s = createStack(sizeof(float), 3);
  assert(s);
  assert(s->memberSize == sizeof(float));
  assert(s->totalElements == 3);
  float a=4.1f,b=5.2f,c=7.2f;
  float d;int r;
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for push\n");
  r = stackPush(s, (void*)&a);
  assert(s->top == 0);
  assert(r == 0);

  r = stackPush(s, (void*)&b);
  assert(s->top == 1);
  assert(r == 0);
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for pop\n");
  r = stackPop(s, (void*)&d);
  assert(r == 0);
  assert(s->top == 0);
  assert(d == 5.2f);
  PRINT("TEST CASE PASSED!\n");

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

  PRINT("TEST for get max elements\n");
  r = getMax(s, (void*)&d, intCompare);
  assert(r == 0);
  assert(s->top == 3);
  assert(d == 7.2f);
  PRINT("TEST CASE PASSED!\n");

  PRINT("TEST for destruction\n");
  r = stackDestroy(s);
  assert(r == 0);
  PRINT("TEST CASE PASSED!\n");

  PRINT("SUCCESS! ALL TEST CASES PASSED\n");
  /*Test for Stack Ends*/

  /*Test for List*/
  list_with_ints();
  list_with_strings();
  list_with_floats();
  PRINT("SUCCESS! ALL TEST CASES PASSED!\n");
  /*Test for List ends*/

  /*Test for Vector*/
  PRINT("TEST for vector\n");
  vector(integer) myvec = new_vector(integer);
  for(int i = 0; i < 314; i++)
  {
    myvec->append(x, i);
  }
  for(int i = 0; i < x->size(x); i++)
  {
    printf("%f\n", x->get(x, i));
  }
  free_vector(x);
  PRINT("SUCCESS! ALL TEST CASE PASSED\n");
  /*Test for Vector Ends*/
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
