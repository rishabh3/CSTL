#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#include "pairtemplateimplementation.h"
DEFINE_PAIR( TYPE )
#undef TYPE


#define TYPE float
#include "pairtemplateimplementation.h"
DEFINE_PAIR( TYPE )
#undef TYPE


#define TYPE double
#include "pairtemplateimplementation.h"
DEFINE_PAIR( TYPE )
#undef TYPE


#define TYPE char
#include "pairtemplateimplementation.h"
DEFINE_PAIR( TYPE )
#undef TYPE
