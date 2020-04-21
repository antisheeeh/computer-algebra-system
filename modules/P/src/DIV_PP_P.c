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
    longNumberP* r = malloc(sizeof(longNumberP));

    r->degree = a->degree - b->degree;
    if(r->degree < 0) return parseNumberP("0"); 

    r->coefficient = malloc((r->degree + 1) * sizeof(longNumberQ));

    for(int i = r->degree; i >= 0; --i) {
        r->coefficient[i] = parseNumberQ("0");
    }

    for(int i = r->degree; deg(a) >= deg(b); --i) {
        longNumberP* p = multyByXk(parseNumberP(toStringQ(divQ(led(a), led(b)))), deg(a) - deg(b));
        r = sumP(r, p);
        a = subP(a, mulP(p, b)); 
    }

    return r;
}