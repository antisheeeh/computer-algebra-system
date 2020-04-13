#include "../lib/GCF_NN_N.h"
#include "../lib/MUL_NN_N.h"
#include "../lib/DIV_NN_N.h"

#include "../lib/LCM_NN_N.h"

longNumberN* lcmN(longNumberN* a, longNumberN* b) {
    return divN(multiN(a, b), gcfN(a, b));
}