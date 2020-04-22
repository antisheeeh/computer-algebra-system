#include <stdio.h>

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
    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);
    longNumberN* div = divN(aN, bN);
    longNumberN* mod = modN(aN, bN);

    if(getSign(b) == NEUTRAL) return NULL;

    if(a->sign == NEUTRAL) return transNtoZ(div);

    if(isZero(mod)) {
        if(a->sign == b->sign) return transNtoZ(div);
        else return changeSign(transNtoZ(div));
    }

    //Если делимое имеет отрицательный знак, тогда результат будет на единицу больше, т.к в обратном случае выйдет, что у нас отрицательный остаток, чего быть не может.
    if(a->sign == MINUS) {
        if(b->sign == MINUS) return transNtoZ(incN(div));
        if(b->sign == PLUS) return changeSign(transNtoZ(incN(div)));
    }

    if(a->sign == PLUS) {
        if(b->sign == MINUS) return changeSign(transNtoZ(div));
        if(b->sign == PLUS) return transNtoZ(div);
    }
}