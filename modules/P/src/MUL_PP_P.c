#include <stdio.h>
#include <stdlib.h>
#include "../lib/MUL_PQ_P.h"
#include "../../../modules/Q/utils/lib/input.h"

#include "../../P/lib/MUL_PP_P.h"
#include "../../P/lib/ADD_PP_P.h"
#include "../../P/lib/MUL_PQ_P.h"
#include "../../P/lib/MUL_PXK_P.h"
#include "../../Q/lib/MUL_QQ_Q.h"
#include "../../Q/lib/ADD_QQ_Q.h"
#include "../utils/lib/input.h"
#include "../../N/utils/lib/input.h"
#include "../../Z/utils/lib/input.h"

longNumberP *mulP(longNumberP *a , longNumberP *b)
{
    longNumberP *res = malloc(sizeof(longNumberP));

    res->degree = a->degree + b->degree;
    res->coefficient = malloc((res->degree + 1) * sizeof(longNumberQ*));

    for(int i = 0; i <= res->degree; i++){
        res->coefficient[i] = parseNumberQ("0");
    }

    //65x^4+7x^2+8x
    //46x^5+7x^4+90

    for(int i = 0; i <= a->degree; i++){
        for(int j = 0; j <= b->degree; j++) {
            res->coefficient[i+j] = addQ(res->coefficient[i+j], mulQ(a->coefficient[i], b->coefficient[j]));
        }
    } 

    return res;
}