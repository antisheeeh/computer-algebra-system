#include <stdlib.h>
#include <stdio.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../../../utils/input.h"

longNumber* multiByDigit(longNumber* a, int d) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = a->len + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) return NULL;

    int i;
    long long t;

    for(i = 0; i < c->len - 1; ++i) {
        t = c->num[i] + a->num[i] * 1ll * d;
        c->num[i] = t % BASE;
        c->num[i + 1] += t / BASE;
    }

    removeTrailingZeros(c);

    return c;
}