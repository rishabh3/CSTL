#ifndef _PAIR_H_
#define _PAIR_H_

#define TYPE int
#include "pairtemplate.h"
DECLARE_PAIR( TYPE )
#undef TYPE

#define TYPE float
#include "pairtemplate.h"
DECLARE_PAIR( TYPE )
#undef TYPE

#define TYPE char
#include "pairtemplate.h"
DECLARE_PAIR( TYPE )
#undef TYPE

#define TYPE double
#include "pairtemplate.h"
DECLARE_PAIR( TYPE )
#undef TYPE
#endif
