#include "../lib/FAC_P_Q.h"

#include <stdlib.h>

#include "../../Q/lib/number.h"
#include "../../Q/lib/DIV_QQ_Q.h"
#include "../../Q/utils/lib/input.h"
#include "../../P/utils/lib/input.h"

#include "../../N/lib/GCF_NN_N.h"
#include "../../N/lib/LCM_NN_N.h"
#include "../../N/lib/NZER_N_B.h"
#include "../../Z/lib/TRANS_Z_N.h"
#include "../../Z/lib/TRANS_N_Z.h"

longNumberP* facP(longNumberP* number) {
    longNumberN* gcf = transZtoN(number->coefficient[number->degree]->numerator);
    longNumberN* lcm = number->coefficient[number->degree]->denominator;

    for(int i = number->degree - 1; i >= 0; --i) {
        if(!isZeroN(transZtoN(number->coefficient[i]->numerator))) {
            gcf = gcfN(gcf, transZtoN(number->coefficient[i]->numerator));
        }

        lcm = lcmN(lcm, number->coefficient[i]->denominator);
    }

    longNumberQ* t = malloc(sizeof(longNumberQ));
    t->numerator = transNtoZ(gcf);
    t->denominator = lcm;

    longNumberP* res = parseNumberP(toStringQ(t));

    return res;
}