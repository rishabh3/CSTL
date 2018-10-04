#ifndef __VEC_H_
#define __VEC_H_
#define type_t int
#define identifier int
#include "vectemplate.h"
initial_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t char
#define identifier char
#include "vectemplate.h"
initial_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t float
#define identifier float
#include "vectemplate.h"
initial_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t double
#define identifier double
#include "vectemplate.h"
initial_vector(type_t, identifier)
#undef type_t
#undef identifier

#endif
