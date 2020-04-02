#include <stdio.h>

#include "../lib/MUL_ZZ_Z.h"

longNumberZ* multyZ(longNumberZ* a, longNumberZ* b) {
    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);

    if(a->sign == NEUTRAL) return transNtoZ(aN);
    if(b->sign == NEUTRAL) return transNtoZ(bN);

    if(a->sign != b->sign) {
        return changeSign(transNtoZ(multiN(aN, bN)));
    } else {
        return transNtoZ(multiN(aN, bN));
    }
}