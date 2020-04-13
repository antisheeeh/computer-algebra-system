#include "../lib/DIV_NN_N.h"
#include "../lib/SUB_NN_N.h"
#include "../lib/MUL_NN_N.h"

#include "../lib/MOD_NN_N.h"

longNumberN* modN(longNumberN* a, longNumberN* b) {
    return subN(a, multiN(b, divN(a, b)));
}