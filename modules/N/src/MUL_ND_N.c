#include <stdio.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/MUL_ND_N.h"

longNumberN* multiByDigit(longNumberN* number, int digit) {
    longNumberN* c = malloc(sizeof(longNumberN));
    if(c == NULL) return NULL;

    c->len = number->len + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) {
        clearStructN(c);
        return NULL;
    }

    long long temp;
    int i;

    for(i = 0; i < c->len - 1; ++i) {
        temp = c->num[i] + number->num[i] * 1ll * digit;
        c->num[i] = temp % BASE;
        c->num[i + 1] += temp / BASE;
    }

    removeLeadingZerosN(c);

    return c;
}