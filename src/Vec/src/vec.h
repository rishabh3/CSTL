#include <stdlib.h>
#include <string.h>

#ifndef VECTOR_NAME
#error "Must declare VECTOR_NAME"
#endif

#ifndef VECTOR_TYPE
#error "Must declare VECTOR_TYPE"
#endif

#ifndef VECTOR_PREFIX
#define VECTOR_PREFIX vec
#endif

#define VECTOR_CONCAT(x, y) x ## _ ## y
#define VECTOR_MAKE_STR1(x, y) VECTOR_CONCAT(x,y)
#define VECTOR_MAKE_STR(x) VECTOR_MAKE_STR1(VECTOR_PREFIX, VECTOR_MAKE_STR1(VECTOR_NAME,x))

#define VECTOR_STRUCT  VECTOR_MAKE_STR(struct)
#define VECTOR         VECTOR_MAKE_STR(t)
#define VECTOR_INIT    VECTOR_MAKE_STR(init)
#define VECTOR_GET     VECTOR_MAKE_STR(get)
#define VECTOR_POP     VECTOR_MAKE_STR(pop)
#define VECTOR_DEL     VECTOR_MAKE_STR(del)
#define VECTOR_SIZE    VECTOR_MAKE_STR(size)
#define VECTOR_APPEND  VECTOR_MAKE_STR(append)

typedef struct {
  VECTOR_TYPE *arr;
  size_t size;
  size_t alloc;
} VECTOR_STRUCT;

typedef VECTOR_STRUCT VECTOR[1];

#undef VECTOR_CONCAT
#undef VECTOR_MAKE_STR1
#undef VECTOR_MAKE_STR
#undef VECTOR_NAME
#undef VECTOR_TYPE
#undef VECTOR_STRUCT
#undef VECTOR
#undef VECTOR_INIT
#undef VECTOR_GET
#undef VECTOR_POP
#undef VECTOR_DEL
#undef VECTOR_SIZE
#undef VECTOR_APPEND
#undef VECTOR_PREFIX
