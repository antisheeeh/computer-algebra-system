#include <stdlib.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"

longNumber* multiByDigit(longNumber* a, longNumber* b) {
    a->num = realloc(a->num, sizeof(int) * (a->len + 1));

    if(a == NULL) return NULL;

    int i;
    long long t;

    t = a->num[0] * b->num[0];

    a->num[0] = (int) (t % BASE);
    a->num[1] += (int) (t / BASE);

    for(i = 1; i < a->len; ++i) {
        a->num[i] %= BASE;
        a->num[i + 1] = a->num[i] / BASE;
    }

    if(a->num[a->len] == 0) {
        a->num = realloc(a->num, sizeof(int) * a->len);
    }

    return a;
}