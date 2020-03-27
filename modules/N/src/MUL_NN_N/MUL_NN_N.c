#include <stdlib.h>

#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../lib/ADD_NN_N/ADD_NN_N.h"
#include "../../lib/MUL_NN_N/MUL_NN_N.h"

#include "../../../../utils/input.h"

longNumber* multi(longNumber* a, longNumber* b) {
    if(a->len == 1) {
        return multiByDigit(b, a->num[0]);
    } else if(b->len == 1) {
        return multiByDigit(a, b->num[0]);
    } else {
        longNumber* c = malloc(sizeof(longNumber));

        if(c == NULL) return NULL;

        c->len = a->len + b->len + 1;
        c->num = calloc(c->len, sizeof(int));

        int i, j;
        long long t;

        for(i = 0; i < a->len; ++i) {
            for(j = 0; j < b->len; ++j) {
                t = c->num[i + j] + a->num[i] * 1ll * b->num[j];
                c->num[i + j] = t % BASE;
                c->num[i + j + 1] += t / BASE;
            }
        }

        removeTrailingZeros(c);

        return c;
    }
}