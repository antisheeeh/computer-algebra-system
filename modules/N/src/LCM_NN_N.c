#include "../lib/LCM_NN_N.h"

longNumberN* lcmN(longNumberN* a, longNumberN* b) {
    return divN(multiN(a, b), gcfN(a, b));
}