#include "../lib/MOD_NN_N.h"

longNumberN* modN(longNumberN* a, longNumberN* b) {
    return subN(a, multiN(b, divN(a, b)));
}