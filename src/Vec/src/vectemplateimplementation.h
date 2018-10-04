#ifndef _VECTOR_H
#define _VECTOR_H
#define PASTETOKEN(x, y) x ## y
#define NAMEGEN(name, type) PASTETOKEN(name, type)

/* Scaling factor for vector size increase */
#define SCALING 2
/* Initial size of newly created vector */
#define INITIAL 4

#define initialize_vector(type_t, identifier) \
/* INITIALIZE VECTOR */ \
NAMEGEN(vector_,identifier) *NAMEGEN(new_vector,identifier)() \
{ \
    /* Allocate memory */ \
    NAMEGEN(vector_,identifier) *result; \
    result = (NAMEGEN(vector_,identifier) *) \
        malloc(sizeof(NAMEGEN(vector_,identifier))); \
    if (result == NULL) \
    { \
        fprintf(stderr, "Memory allocation failure!n");\
        exit(1);\
    }\
    result->data = (type_t *)calloc(INITIAL, sizeof(type_t));\
    if (result->data == NULL)\
    {\
        fprintf(stderr, "Memory allocation failure!n");\
        exit(1);\
    }\
    result->curr_size = 0;\
    result->maxi_size = INITIAL;\
\
    /* Setting appropriate function pointers to work as methods */\
    result->append = &NAMEGEN(append_ ,identifier);\
    result->extend = &NAMEGEN(extend_, identifier);\
    result->set = &NAMEGEN(set_, identifier);\
    result->get = &NAMEGEN(get_, identifier);\
    result->pop = &NAMEGEN(pop_, identifier);\
    result->size = &NAMEGEN(size_, identifier);\
    result->max_size = &NAMEGEN(max_size_, identifier);\
\
    /* return pointer to memory type */\
    return result;\
}\
\
/* METHODS */\
\
/* Appends value to Vector */\
void NAMEGEN(append_ ,identifier)(NAMEGEN(vector_,identifier) *self, type_t x)\
{\
    if (self->curr_size == self->maxi_size)\
    {\
        self->maxi_size *= SCALING;\
        self->maxi_size++;\
        self->data = (type_t *)realloc(self->data,\
            self->maxi_size * sizeof(type_t));\
        if (self->data == NULL)\
        {\
            fprintf(stderr, "Memory reallocation failure!n");\
            exit(1);\
        }\
    }\
    self->data[self->curr_size] = x;\
    self->curr_size++;\
}\
\
/* Extends a vector with the values of a given vector of the same type */\
void NAMEGEN(extend_, identifier)(NAMEGEN(vector_,identifier) *self, \
    NAMEGEN(vector_,identifier) * input)\
{\
    int i;\
    while ((self->maxi_size - self->curr_size) < input->curr_size)\
    {\
        self->maxi_size *= SCALING;\
        self->maxi_size++;\
        self->data = (type_t *)realloc(self->data,\
            self->maxi_size * sizeof(type_t));\
        if (self->data == NULL)\
        {\
            fprintf(stderr, "Memory reallocation failure!n");\
            exit(1);\
        }\
    }\
    for (i = 0; i < input->curr_size; i++)\
    {\
        self->data[self->curr_size] = input->data[i];\
        self->curr_size++;\
    }\
}\
\
/* Sets value at index to new value */\
void NAMEGEN(set_, identifier)(NAMEGEN(vector_,identifier) *self, int index, type_t x)\
{\
    if(index >= self->curr_size || index < 0)\
    {\
        fprintf(stderr, "Index out of range!n");\
        exit(1);\
    }\
    self->data[index] = x;\
}\
\
/* Gets value at given index */\
type_t NAMEGEN(get_, identifier)(NAMEGEN(vector_,identifier) *self, int index)\
{\
    if(index >= self->curr_size || index < 0)\
    {\
        fprintf(stderr, "Index out of range!n");\
        exit(1);\
    }\
    return self->data[index];\
}\
\
/* Pops vector */\
type_t NAMEGEN(pop_, identifier)(NAMEGEN(vector_,identifier) *self)\
{\
    if (self->curr_size == 0)\
    {\
        fprintf(stderr, "Cannot pop with vector size of zero!n");\
        exit(1);\
    }\
    self->curr_size--;\
    return self->data[self->curr_size + 1];\
}\
\
/* Returns current size of vector */\
size_t NAMEGEN(size_, identifier)(NAMEGEN(vector_,identifier) *self)\
{\
    return self->curr_size;\
}\
\
/* Returns maximum size before needing to resize */\
size_t NAMEGEN(max_size_, identifier)(NAMEGEN(vector_,identifier) *self)\
{\
    return self->maxi_size;\
}


#endif  /* _VECTOR_H */
