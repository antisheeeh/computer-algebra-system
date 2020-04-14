#include <stdlib.h>
#include "../lib/MUL_PQ_P.h"

#include "../../Q/lib/MUL_QQ_Q.h"

longNumberP *multyByRational(longNumberP *number, longNumberQ *rat) {
    longNumberP *res = malloc(sizeof(longNumberP));

    res->coefficient = malloc((number->degree+1)*(sizeof(longNumberQ*)));
    res->degree = number->degree;
    int i;
    for(i = res->degree; i >= 0; --i) {
        res->coefficient[i] = mulQ(number->coefficient[i], rat);
    }

    return res;
}