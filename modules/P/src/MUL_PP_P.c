#include "../lib/MUL_PQ_P.h"
#include "../../P/lib/ADD_PP_P.h"
#include "../../P/lib/MUL_PQ_P.h"
#include "../../P/lib/MUL_PXK_P.h"
#include "../utils/lib/input.h"

#include "../lib/MUL_PP_P.h"

longNumberP* mulP(longNumberP* a , longNumberP* b) {
    longNumberP* res = parseNumberP("0");

    for(int i = 0; i <= b->degree; i++){
        res = sumP(res, multyByXk(multyByRational(a, b->coefficient[i]), i));
    } 

    return res;
}