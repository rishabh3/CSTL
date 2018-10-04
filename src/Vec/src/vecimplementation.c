#include "vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define type_t int
#define identifier int
#include "vectemplateimplementation.h"
initialize_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t char
#define identifier char
#include "vectemplateimplementation.h"
initialize_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t float
#define identifier float
#include "vectemplateimplementation.h"
initialize_vector(type_t, identifier)
#undef type_t
#undef identifier

#define type_t double
#define identifier double
#include "vectemplateimplementation.h"
initialize_vector(type_t, identifier)
#undef type_t
#undef identifier
