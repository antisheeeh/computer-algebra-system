#include <stdio.h>
#include <stdlib.h>
#include "../lib/ADD_PP_P.h"
#include "../lib/ADD_PP_P.h"
#include "../lib/MUL_PQ_P.h"
#include "../../../modules/Q/lib/SUB_QQ_Q.h"
#include "../utils/lib/input.h"
#include "../../Q/utils/lib/input.h"

longNumberP* subP(longNumberP* a , longNumberP* b) {
    longNumberP *res = sumP(a, multyByRational(b, parseNumberQ("-1")));

    removeLeadingZerosP(res);

    return res;
}