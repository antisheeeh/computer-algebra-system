/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/MUL_NN_N.h"

longNumberN* multiN(longNumberN* a, longNumberN* b) {
    if(a->len == 1) return multiByDigit(b, a->num[0]);
    if(b->len == 1) return multiByDigit(a, b->num[0]);
        
    longNumberN* c = malloc(sizeof(longNumberN));

    if(c == NULL) return NULL;

    c->len = a->len + b->len + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) {
        clearStructN(c);
        return NULL;
    }

    int i, j;
    long long t;

    for(i = 0; i < a->len; ++i) {
        for(j = 0; j < b->len; ++j) {
            t = c->num[i + j] + a->num[i] * 1ll * b->num[j];
            c->num[i + j] = t % BASE;
            c->num[i + j + 1] += t / BASE;
        }
    }

    removeLeadingZerosN(c);

    return c;
}