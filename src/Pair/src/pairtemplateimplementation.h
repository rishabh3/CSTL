#ifndef _PAIRTEMPLATEIMPLEMENT_
#define _PAIRTEMPLATEIMPLEMENT_
#define PASTETOKEN(x, y) x ## y
#define NAMEGEN(name, type) PASTETOKEN(name, type)
#define DEFINE_PAIR( TYPE ) \
  PASTETOKEN(PAIR_, TYPE) *NAMEGEN(make_pair_, TYPE)(TYPE first, TYPE second) \
  {                                                                           \
    /*
      This function basically make a pair object of specified type
      @params:
            TYPE first: in : The first element of the pair
            TYPE second: in: The second element of the pair
      @return-type:
            PAIR_TYPE*
    */ \
    PASTETOKEN(PAIR_, TYPE) *newpair = (PASTETOKEN(PAIR_, TYPE) *)malloc( sizeof(PASTETOKEN(PAIR_, TYPE)) ); \
    newpair->first = first; \
    newpair->second = second; \
    return newpair; \
  } \
  void NAMEGEN(destroy_pair_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    /*
      This function basically destroy a pair object of specified type
      @params:
            PAIR_TYPE *self: in-out: Pointer to the respective pair object
      @return-type:
            void
    */ \
    free(self); \
  } \
  void NAMEGEN(swap_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    /*
      This function swaps the elements of the pair
      @params:
            PAIR_TYPE *self: in-out: Pointer to the respective pair object
      @return-type:
            void
    */ \
    TYPE temp = self->first; \
    self->first = self->second; \
    self->second = temp; \
  } \
  int NAMEGEN(compare_, TYPE)(NAMEGEN(PAIR_, TYPE) *term1, PASTETOKEN(PAIR_, TYPE) *term2) \
  { \
    /*
      This function compares the two pair objects
      @params:
            PAIR_TYPE *term1: in-out: Pointer to the respective pair object
            PAIR_TYPE *term2: in-out: Pointer to the respective pair object
      @return-type:
            int
    */ \
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
    /*
      This function basically modifies a pair object of specified type
      @params:
            PAIR_TYPE *self: in-out: Pointer to the respective pair object
            TYPE first: in : The first element of the pair
            TYPE second: in: The second element of the pair
      @return-type:
           void
    */ \
    self->first = first; \
    self->second = second; \
  } \
  TYPE NAMEGEN(get_first_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    /*
      This function returns the first member of the pair object
      @params:
            PAIR_TYPE *self: in-out: Pointer to the respective pair object
      @return-type:
           TYPE
    */ \
    return self->first; \
  } \
  TYPE NAMEGEN(get_second_, TYPE)(NAMEGEN(PAIR_, TYPE) *self) \
  { \
    /*
      This function returns the second member of the pair object
      @params:
            PAIR_TYPE *self: in-out: Pointer to the respective pair object
      @return-type:
           TYPE
    */ \
    return self->second; \
  }
#endif
