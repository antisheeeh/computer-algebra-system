#pragma once

#include "../../N/lib/number.h"
#include "../../Q/lib/number.h"

#define MAXLENGTH 100
#define BLOCK_SIZE 9
#define BASE 1000000000

typedef struct {    
    int degree;
    longNumberQ *coefficient;
} longNumberP;