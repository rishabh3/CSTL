#include <stdio.h>
#define VECTOR_TYPE float
#define VECTOR_NAME float

#include "vec.h"

int main(void) {
  int i;
  vec_float_t vec;
  vec_float_init(vec);
  vec_float_append(vec, 2.1);
  vec_float_append(vec, 100);
  vec_float_append(vec, 101);
  vec_float_append(vec, 102);
  vec_float_append(vec, 103);
  vec_float_append(vec, 104);
  vec_float_append(vec, 105);
  vec_float_append(vec, 106);
  vec_float_append(vec, 107);
  vec_float_append(vec, 108);
  vec_float_append(vec, 109);
  vec_float_pop(vec);
  vec_float_append(vec, 200);
  vec_float_pop(vec);
  vec_float_pop(vec);
  vec_float_del(vec, 0);
  vec_float_del(vec, 1);

  for (i = 0; i < vec_float_size(vec); i++) {
    printf("%f\n", vec_float_get(vec, i));
  }
}