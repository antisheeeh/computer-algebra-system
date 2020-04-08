#include "../lib/DIV_ZZ_Z.h"

longNumberZ* divZ(longNumberZ* a, longNumberZ* b) {
    longNumberN* c = divN(transZtoN(a), transZtoN(b));

    if(a->sign == NEUTRAL) return transNtoZ(c);

    if(a->sign == MINUS) {
        c = inc(c);

        if(b->sign == PLUS) return changeSign(transNtoZ(c));
        else return transNtoZ(c);
    } else {
        if(b->sign == PLUS) return transNtoZ(c);
        else return changeSign(transNtoZ(c));
    }
}