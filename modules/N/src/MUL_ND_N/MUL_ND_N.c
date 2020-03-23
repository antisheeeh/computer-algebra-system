#include <stdlib.h>
#include <stdio.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"

longNumber* multiByDigit(longNumber* a, longNumber* b) {
    longNumber* c = malloc(sizeof(longNumber));

    c->len = a->len;
    c->num = calloc(c->len + 1, sizeof(int));

    if(c == NULL) return NULL;

    int i;
    long long t;

    t = a->num[0] * 1ll * b->num[0];

    printf("\n%lld\n", t);

    c->num[0] = (int) (t % BASE);
    c->num[1] += (int) (t / BASE);

    for(i = 1; i < c->len; ++i) {
        c->num[i] %= BASE;
        c->num[i + 1] = c->num[i] / BASE;
    }

    if(c->num[c->len] == 0) {
        c->num = realloc(c->num, sizeof(int) * c->len);
    } else {
        c->len++;
    }

    return c;
}