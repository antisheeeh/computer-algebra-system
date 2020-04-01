#include <stdlib.h>
#include <stdio.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../../../utils/lib/input.h"
#include "../../../../utils/lib/memory.h"

longNumber* multiByDigit(longNumber* number, int digit) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = number->len + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) {
        clearStruct(c);
        return NULL;
    }

    long long temp;

    for(int i = 0; i < c->len - 1; ++i) {
        temp = c->num[i] + number->num[i] * 1ll * digit;
        c->num[i] = temp % BASE;
        c->num[i + 1] += temp / BASE;
    }

    removeTrailingZeros(c);

    return c;
}