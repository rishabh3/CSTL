#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

int main()
{
  PAIR_int *mypair = make_pair_int(10,20);
  printf("Before Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  swap_int(mypair);
  printf("After Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  destroy_pair_int(mypair);
  return 0;

  vector(integer) x = new_vector(integer);
  for(int i = 0; i < 314; i++)
  {
    x->append(x, i);}
    for(int i = 0; i < x->size(x); i++)
  {
  printf("%f\n", x->get(x, i));}
  free_vector(x);
  return 0;
}
