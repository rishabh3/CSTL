#ifndef _PAIRTEMPLATEIMPLEMENT_
#define _PAIRTEMPLATEIMPLEMENT_
#define PASTETOKEN(x, y) x ## y
#define NAMEGEN(name, type) PASTETOKEN(name, type)
#define DEFINE_PAIR( TYPE ) \
  PASTETOKEN(PAIR_, TYPE) *NAMEGEN(make_pair_, TYPE)(TYPE first, TYPE second) \
  {                                                                           \
    PASTETOKEN(PAIR_, TYPE) *newpair = (PASTETOKEN(PAIR_, TYPE) *)malloc( sizeof(PASTETOKEN(PAIR_, TYPE)) ); \
    newpair->first = first; \
    newpair->second = second; \
    return newpair; \
  } \
  void NAMEGEN(destroy_pair_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    free(self); \
  } \
  void NAMEGEN(swap_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    TYPE temp = self->first; \
    self->first = self->second; \
    self->second = temp; \
  } \
  int NAMEGEN(compare_, TYPE)(NAMEGEN(PAIR_, TYPE) *term1, PASTETOKEN(PAIR_, TYPE) *term2) \
  { \
    if(term1->first == term2->first) \
    { \
      if(term1->second < term2->second) \
      { \
        return -1; \
      } \
      else if(term1->second > term2->second) \
      { \
        return 1; \
      } \
      else \
      { \
        return 0; \
      } \
    } \
    else if(term1->first < term2->first) \
    { \
      return -1; \
    } \
    return 1; \
  } \
  void NAMEGEN(modify_pair_, TYPE)(NAMEGEN(PAIR_, TYPE) *self, TYPE first, TYPE second) \
  { \
    self->first = first; \
    self->second = second; \
  } \
  TYPE NAMEGEN(get_first_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    return self->first; \
  } \
  TYPE NAMEGEN(get_second_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    return self->second; \
  }
#endif
