/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>

#include "../../lib/SUB_NN_N/SUB_NN_N.h"
#include "../../lib/COM_NN_D/COM_NN_D.h"
#include "../../../../utils/input.h"

longNumber* sub(longNumber* a, longNumber* b) {
    if(compare(a, b) == LESS) return NULL;

    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = a->len;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) return NULL;

    int i;

    for(i = 0; i < a->len; ++i) {
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