#ifndef _PAIRTEMPLATE_
#define _PAIRTEMPLATE_
#define TOKENPASTE(x, y) x ## y
#define GENNAME(name, type) TOKENPASTE(name, type)
#define DECLARE_PAIR( TYPE ) \
  typedef struct TOKENPASTE(_PAIR_, TYPE)\
  {                           \
    TYPE first;               \
    TYPE second;              \
  } TOKENPASTE(PAIR_, TYPE);  \
  TOKENPASTE(PAIR_, TYPE) *GENNAME(make_pair_, TYPE)(TYPE first,TYPE second); \
  void GENNAME(destroy_pair_, TYPE)(GENNAME(PAIR_, TYPE) *self); \
  void GENNAME(swap_, TYPE)(GENNAME(PAIR_, TYPE) *self); \
  int GENNAME(compare_, TYPE)(GENNAME(PAIR_, TYPE) *term1, TOKENPASTE(PAIR_, TYPE) *term2); \
  void GENNAME(modify_pair_, TYPE)(GENNAME(PAIR_, TYPE) *self, TYPE first, TYPE second); \
  TYPE GENNAME(get_first_, TYPE)(GENNAME(PAIR_, TYPE) *self); \
  TYPE GENNAME(get_second_, TYPE)(GENNAME(PAIR_, TYPE) *self);
#endif
