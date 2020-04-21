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

    r->degree = deg(a) - deg(b);
    r->coefficient = malloc((r->degree + 1) * sizeof(longNumberQ));

    for(int i = deg(r); i >= 0; --i) {
        r->coefficient[i] = parseNumberQ("0");
    }

    if(r->degree < 0) return NULL; 

    for(int i = deg(r); deg(a) >= deg(b); --i) {
        longNumberP* p = parseNumberP(toStringQ(divQ(led(a), led(b))));
        r = sumP(r, multyByXk(p, deg(a) - deg(b)));
        a = subP(a, mulP(p, b)); 
    }

    return r;
}