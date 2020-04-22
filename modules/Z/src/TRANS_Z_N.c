#include <stdlib.h>

#include "../lib/TRANS_Z_N.h"

longNumberN* transZtoN(longNumberZ* number) {
    longNumberN* res = malloc(sizeof(longNumberN));

    res->len = number->len;
    res->num = malloc(res->len * sizeof(int));

    for(int i = number->len - 1; i >= 0; --i) {
        res->num[i] = number->num[i];
    }

    return res;
}