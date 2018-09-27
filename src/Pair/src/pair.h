#ifndef _PAIR_H_
#define _PAIR_H_
#include "../util.h"
struct pair{
  void *first;
  void *second;
};
typedef struct pair PAIR;
PAIR* make_pair(void *first, void *second);
void destroy_pair(PAIR*);
void swap(PAIR*);
bool compare(PAIR *, PAIR *);
void modify_pair(PAIR *, void *, void *);
#endif
