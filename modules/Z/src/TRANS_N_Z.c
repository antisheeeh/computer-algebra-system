#include "../../N/lib/NZER_N_B.h"

#include "../lib/TRANS_N_Z.h"

#include <stdlib.h>

longNumberZ* transNtoZ(longNumberN* number) {
    longNumberZ* res = malloc(sizeof(longNumberZ));

    res->len = number->len;
    res->num = malloc(res->len * sizeof(int));
    res->sign = isZeroN(number) ? NEUTRAL : PLUS;

    for(int i = number->len - 1; i >= 0; --i) {
        res->num[i] = number->num[i];
    }

    return res;
}