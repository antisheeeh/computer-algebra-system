#include <stdlib.h>

#include "../../lib/ADD_1N_N/ADD_1N_N.h"
#include "../../../../utils/input.h"

longNumber* add_1n(longNumber* number) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = number->len + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) return NULL;

    int i;

    c->num[0]++;

    for(i = 0; i < c->len - 1; ++i) {
        c->num[i] += number->num[i];

        if(c->num[i] >= BASE) {
            c->num[i] -= BASE;
            c->num[i + 1]++;
        }
    }

    removeTrailingZeros(c);

    return c;
}