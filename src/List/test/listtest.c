#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/list.h"

//size_t malloc_size = 100;
 
void list_with_ints();
void list_with_strings();
void list_with_floats();
 
bool iterate_int(void *data);
bool iterate_string(void *data);
bool iterate_float(void *data);
void free_string(void *data);
 
int main(int argc, char *argv[])
{
  printf("Loading demo...\n");
  list_with_ints();
  list_with_strings();
  list_with_floats();
}
 
void list_with_ints()
{
  //int numbers = 10;
 // printf("Generating list with the first %d positive numbers...\n", numbers);
  int numbers;
  printf("Enter the number of items");
  scanf("%d",&numbers);
  int elem;
  printf("Enter the list items");
  list list;
  list_new(&list, sizeof(int), NULL);
 
 /* for(i = 1; i <= numbers; i++) {
    list_append(&list, &i);
  }
 */
  for(int i=0;i<numbers;i++){
	scanf("%d",&elem);
	list_append(&list, &elem);
  }



  list_for_each(&list, iterate_int);
  printf("\n");
  list_destroy(&list);
  printf("Successfully freed %d numbers...\n", numbers);
}
 
void list_with_strings()
{
  int numNames = 5;
  const char *names[] = { "David", "Kevin", "Michael", "Craig", "Jimi" };
  /*int numNames;
  printf("Enter the number of items");
  scanf("%d",&numNames);
  const char *elem[] = { "" };
  printf("Enter the list items");*/

  int i;
  list list;
  list_new(&list, sizeof(char *), free_string);
 
  char *name;
  for(i = 0; i < numNames; i++) {
    //scanf("%s",elem[i]);
    name = strdup(names[i]);
    list_append(&list, &name);
  }
 
  list_for_each(&list, iterate_string);
  printf("\n");
  list_destroy(&list);
  printf("Successfully freed %d strings...\n", numNames);
}

void list_with_floats()
{
  //int numbers = 10;
 // printf("Generating list with the first %d positive numbers...\n", numbers);
  int numbers;
  printf("Enter the number of items");
  scanf("%d",&numbers);
  float elem;
  printf("Enter the list items");
  int i;
  list list;
  list_new(&list, sizeof(float), NULL);
 
 /* for(i = 1; i <= numbers; i++) {
    list_append(&list, &i);
  }
 */
  for(int i=0;i<numbers;i++){
	scanf("%f",&elem);
	list_append(&list, &elem);
  }



  list_for_each(&list, iterate_float);
  printf("\n");
  list_destroy(&list);
  printf("Successfully freed %d numbers...\n", numbers);
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
