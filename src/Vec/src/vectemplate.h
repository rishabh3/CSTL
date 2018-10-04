#ifndef __VEC_IMPL_H_
#define __VEC_IMPL_H_
#include<stdlib.h>
/* Scaling factor for vector size increase */
#define SCALING 2
/* Initial size of newly created vector */
#define INITIAL 4
/* Macro to make vector declaration more intuitive */
#define vector(identifier) vector_ ## identifier *
/* Macro to make initialization more intuitive */
#define new_vector(identifier) new_vector ## identifier()
/* Macro to free a vector */
#define free_vector(vector) do {free(vector->data); free(vector);} while (0)
/* MACRO THAT DEFINES VECTOR AND CORRESPONDING FUNCTIONS */
#define TOKENPASTE(x, y) x ## y
#define GENNAME(name, type) TOKENPASTE(name, type)
#define initial_vector(type_t, identifier) \
/* STRUCTURE DEFINING VECTOR */ \
  typedef struct GENNAME(_vector_, identifier) \
  { \
    /* Array holding data */\
    type_t *data;\
    \
    /* Size parameters */\
    size_t curr_size;\
    size_t maxi_size;\
    \
    /* Methods */\
    void (*append)(struct GENNAME(_vector_, identifier) *self, type_t x);\
    void (*extend)(struct GENNAME(_vector_, identifier) *self, \
        struct GENNAME(_vector_, identifier) * input);\
    void (*set)(struct GENNAME(_vector_, identifier) *self, int index, type_t x);\
    type_t (*get)(struct GENNAME(_vector_, identifier) *self, int index);\
    type_t (*pop)(struct GENNAME(_vector_, identifier) *self);\
    size_t (*size)(struct GENNAME(_vector_, identifier) *self);\
    size_t (*max_size)(struct GENNAME(_vector_, identifier) *self);\
    \
} GENNAME(vector_, identifier) ;\
\
/* FUNCTION PROTOTYPES */\
GENNAME(vector_, identifier) *GENNAME(new_vector, identifier)();\
\
void GENNAME(append_,identifier)(GENNAME(vector_, identifier) *self, type_t x);\
void GENNAME(extend_,identifier)(GENNAME(vector_, identifier) *self, \
    GENNAME(vector_, identifier) * input);\
void GENNAME(set_,identifier)(GENNAME(vector_, identifier) *self, int index, type_t x);\
type_t GENNAME(get_,identifier)(GENNAME(vector_, identifier) *self, int index);\
type_t GENNAME(pop_,identifier)(GENNAME(vector_, identifier) *self);\
size_t GENNAME(size_,identifier)(GENNAME(vector_, identifier) *self);\
size_t GENNAME(max_size_,identifier)(GENNAME(vector_, identifier) *self);

#endif
