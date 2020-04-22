#include "../../N/lib/MUL_NN_N.h"
#include "../lib/MUL_ZM_Z.h"
#include "../lib/TRANS_N_Z.h"
#include "../lib/TRANS_Z_N.h"

#include "../lib/MUL_ZZ_Z.h"

longNumberZ* multiZ(longNumberZ* a, longNumberZ* b) {
    if(a->sign == NEUTRAL) return a;
    if(b->sign == NEUTRAL) return b;
    
    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);

    if(a->sign != b->sign) {
        return changeSign(transNtoZ(multiN(aN, bN)));
    } else {
        return transNtoZ(multiN(aN, bN));
    }
}