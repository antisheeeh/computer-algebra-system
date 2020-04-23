#include <stdio.h>
#include <stdlib.h>
#include "../lib/DIV_PP_P.h"
#include "../../Q/lib/DIV_QQ_Q.h"
#include "../lib/DEG_P_N.h"
#include "../lib/MUL_PXK_P.h"
#include "../lib//SUB_PP_P.h"
#include "../lib/ADD_PP_P.h"
#include "../lib/LED_PQ_Q.h"
#include "../lib/MUL_PP_P.h"
#include "../../Q/utils/lib/input.h"
#include "../utils/lib/input.h"

longNumberP* divP(longNumberP* a, longNumberP* b) {
    if(a->degree < b->degree) return parseNumberP("0"); 
    if(a->degree == b->degree) return parseNumberP(toStringQ(divQ(led(a), led(b))));
    
    longNumberP* res = parseNumberP("0");

    while(a->degree != 0 && a->degree >= b->degree) {
        longNumberP* p = multyByXk(parseNumberP(toStringQ(divQ(led(a), led(b)))), a->degree - b->degree);
        res = sumP(res, p);
        a = subP(a, mulP(p, b)); 
    }

    return res;
}