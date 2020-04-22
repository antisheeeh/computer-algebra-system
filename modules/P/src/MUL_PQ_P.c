#include <stdlib.h>
#include "../lib/MUL_PQ_P.h"
#include "../utils/lib/input.h"

#include "../../Q/lib/MUL_QQ_Q.h"

longNumberP *multyByRational(longNumberP *number, longNumberQ *rat) {
    longNumberP *res = malloc(sizeof(longNumberP));

    res->degree = number->degree;
    res->coefficient = malloc((res->degree + 1) * sizeof(longNumberQ*));

    for(int i = res->degree; i >= 0; --i) {
        res->coefficient[i] = mulQ(number->coefficient[i], rat);
    }

    removeLeadingZerosP(res);

    return res;
}