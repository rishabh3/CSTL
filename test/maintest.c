#include "pair.h"
#include <stdio.h>

int main(){
  PAIR_int *mypair = make_pair_int(10,20);
  printf("Before Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  swap_int(mypair);
  printf("After Swapping First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  destroy_pair_int(mypair);
  return 0;

  int i;
  vec_int_t vec;
  vec_int_init(vec);
  vec_int_append(vec, 2);
  vec_int_append(vec, 100);
  vec_int_append(vec, 101);
  vec_int_append(vec, 102);
  vec_int_append(vec, 103);
  vec_int_append(vec, 104);
  vec_int_append(vec, 105);
  vec_int_append(vec, 106);
  vec_int_append(vec, 107);
  vec_int_append(vec, 108);
  vec_int_append(vec, 109);
  vec_int_pop(vec);
  vec_int_append(vec, 200);
  vec_int_pop(vec);
  vec_int_pop(vec);
  vec_int_del(vec, 0);
  vec_int_del(vec, 1);

  for (i = 0; i < vec_int_size(vec); i++) {
    printf("%d\n", vec_int_get(vec, i));
}
