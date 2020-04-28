#include "../lib/MOD_NN_N.h"
#include "../lib/NZER_N_B.h"

#include "../lib/GCF_NN_N.h"

longNumberN* gcfN(longNumberN* a, longNumberN* b) {
    longNumberN* temp;

    while(!isZeroN(b)) {
        temp = b;
        b = modN(a, b);
        a = temp;
    }

    return a;
}