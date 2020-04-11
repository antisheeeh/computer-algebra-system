#include "../lib/MUL_PQ_P.h"

#include "../../Q/lib/MUL_QQ_Q.h"

longNumberP *multyByRational(longNumberP *number, longNumberQ *rat) {
    longNumberP *res = malloc(sizeof(longNumberP));

    int i;
    for(i = number->degree - 1; i >= 0; --i) {
        res->coefficient[i] = mulQ(res->coefficient[i], rat);
    }

    return res;
}