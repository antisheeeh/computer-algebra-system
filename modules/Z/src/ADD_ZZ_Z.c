/*
    author Valentin Pronin
    group 9305
*/

#include "../../N/lib/COM_NN_D.h"
#include "../../N/lib/ADD_NN_N.h"
#include "../../N/lib/SUB_NN_N.h"
#include "../lib/MUL_ZM_Z.h"
#include "../lib/TRANS_Z_N.h"
#include "../lib/TRANS_N_Z.h"

#include "../lib/ADD_ZZ_Z.h"

longNumberZ* sumZ(longNumberZ* a, longNumberZ* b) {
    longNumberN* aN = transZtoN(a);
    longNumberN* bN = transZtoN(b);

    if(a->sign == NEUTRAL) return b;
    if(b->sign == NEUTRAL) return a;

    if(a->sign == PLUS && b->sign == PLUS) return transNtoZ(sumN(aN, bN));
    if(a->sign == MINUS && b->sign == MINUS) return changeSign(transNtoZ(sumN(aN, bN)));
    //Если знаки двух чисел различаются, тогда мы вычитаем из большего меньшее
    if(a->sign == PLUS && b->sign == MINUS) {
        if(compN(aN, bN) == GREATER) return transNtoZ(subN(aN, bN));
        else return changeSign(transNtoZ(subN(bN, aN)));
    }

    if(a->sign == MINUS && b->sign == PLUS) {
        if(compN(aN, bN) == LESS) return transNtoZ(subN(bN, aN));
        else return changeSign(transNtoZ(subN(aN, bN)));
    }
}