#include <stddef.h>

#include "../../N/lib/DIV_NN_N.h"
#include "../../N/lib/ADD_1N_N.h"
#include "../../N/lib/MOD_NN_N.h"
#include "../../N/lib/NZER_N_B.h"
#include "../lib/TRANS_Z_N.h"
#include "../lib/TRANS_N_Z.h"
#include "../lib/MUL_ZM_Z.h"
#include "../lib/POZ_Z_D.h"

#include "../lib/DIV_ZZ_Z.h"

longNumberZ* divZ(longNumberZ* a, longNumberZ* b) {
    if(b->sign == NEUTRAL) return NULL;

    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);
    longNumberN* div = divN(aN, bN);
    longNumberN* mod = modN(aN, bN);

    if(a->sign == NEUTRAL) return transNtoZ(div);

    if(isZero(mod)) {
        if(a->sign == b->sign) return transNtoZ(div);
        else return changeSign(transNtoZ(div));
    }

    //If the dividend has a negative sign, then the result will increase by one//
    
    if(a->sign == MINUS) {
        if(b->sign == MINUS) return transNtoZ(incN(div));
        if(b->sign == PLUS) return changeSign(transNtoZ(incN(div)));
    }

    if(a->sign == PLUS) {
        if(b->sign == MINUS) return changeSign(transNtoZ(div));
        if(b->sign == PLUS) return transNtoZ(div);
    }
}