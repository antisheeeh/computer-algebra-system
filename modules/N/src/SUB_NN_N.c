/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>

#include "../lib/SUB_NN_N.h"
#include "../lib/COM_NN_D.h"
#include "../../../utils/lib/input.h"
#include "../../../utils/lib/memory.h"

longNumber* sub(longNumber* a, longNumber* b) {
    if(compare(a, b) == LESS) return NULL;

    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = a->len;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) {
        clearStruct(c);
        return NULL;
    }

    for(int i = 0; i < c->len; ++i) {
        c->num[i] += a->num[i];

        if(i < b->len) {
            c->num[i] = a->num[i] - b->num[i];
        }

        if(c->num[i] < 0) {
            c->num[i] += BASE;
            c->num[i + 1]--;
        }
    }

    removeTrailingZeros(c);

    return c;
}