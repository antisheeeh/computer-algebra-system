#include "../lib/MOD_PP_P.h"

#include "../lib/DIV_PP_P.h"
#include "../lib/MUL_PP_P.h"
#include "../lib/SUB_PP_P.h"

longNumberP* modP(longNumberP* a, longNumberP* b) {
    return subP(a, mulP(divP(a, b), b));
}