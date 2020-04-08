#include "../lib/GCF_NN_N.h"

longNumberN* gcfN(longNumberN* a, longNumberN* b) {
    longNumberN* temp;

    while(!isZero(b)) {
        temp = b;
        b = modN(a, b);
        a = temp;
    }

    return a;
}