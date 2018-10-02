#include "pair.h"
#include <stdio.h>

int main(){
  PAIR_int *mypair = make_pair_int(10,20);
  printf("Before Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  swap_int(mypair);
  printf("After Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  destroy_pair_int(mypair);
  return 0;
}
