#include <stdlib.h>
#include <stdio.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"

longNumber* multiByDigit(longNumber* a, longNumber* b) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = a->len;
    c->num = calloc(c->len + 1, sizeof(int));

    if(c->num == NULL) return NULL;

    int i;
    long long t;

    for(i = 0; i < c->len; ++i) {
        t = c->num[i] + a->num[i] * 1ll * b->num[0];
        c->num[i] = t % BASE;
        c->num[i + 1] += t / BASE;
    }

    if(c->num[c->len] == 0) {
        c->num = realloc(c->num, sizeof(int) * c->len);
    } else {
        c->len++;
    }

    return c;
}