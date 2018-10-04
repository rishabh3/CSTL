#include "vec.h"

static __inline void VECTOR_INIT(VECTOR vec) {
  vec[0].alloc = 8;
  vec[0].arr = calloc(vec->alloc, sizeof(VECTOR_TYPE));
  vec[0].size = 0;
}

static __inline void VECTOR_APPEND(VECTOR vec, VECTOR_TYPE elt) {
  if (vec[0].size == vec[0].alloc) {
    vec[0].alloc += (vec[0].alloc >> 1); /* Increase size by 50% */
    vec[0].arr = realloc(vec[0].arr, vec[0].alloc * sizeof(VECTOR_TYPE));
  }

  vec[0].arr[vec[0].size++] = elt;
}

static __inline VECTOR_TYPE VECTOR_GET(VECTOR vec, int i) {
  return vec[0].arr[i];
}

static __inline VECTOR_TYPE VECTOR_POP(VECTOR vec) {
  return vec[0].arr[vec[0].size--];
}

static __inline void VECTOR_DEL(VECTOR vec, int i) {
  if (i == vec[0].size) {
    VECTOR_POP(vec);
  } else {
    memmove(&(vec[0].arr[i]), &(vec[0].arr[i + 1]),
            sizeof(VECTOR_TYPE) * vec[0].size - i - 1);
    vec[0].size--;
  }
}

static __inline size_t VECTOR_SIZE(VECTOR vec) {
  return vec[0].size;
}