#include <stdio.h>

#include "../lib/MUL_ZZ_Z.h"

longNumberZ* multyZ(longNumberZ* a, longNumberZ* b) {
    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);

    if(a->sign != b->sign) {
        return changeSign(transNtoZ(multi(aN, bN)));
    } else {
        return transNtoZ(multi(aN, bN));
    }
}