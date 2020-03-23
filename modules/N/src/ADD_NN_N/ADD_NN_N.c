/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include <stdlib.h>

#include "../../lib/ADD_NN_N/ADD_NN_N.h"

longNumber* sum(longNumber* a, longNumber* b) {
    int i;
    longNumber* c = malloc(sizeof(longNumber));

    c->len = max(a->len, b->len);
    c->num = calloc(c->len + 1, sizeof(int));

    if(c->num == NULL) return NULL;

    for(i = 0; i < c->len; ++i) {
        if(i >= a->len){
            c->num[i] += b->num[i];
        } else if(i >= b->len) {
            c->num[i] += a->num[i];
        } else {
            c->num[i] += a->num[i] + b->num[i];
        }

        if(c->num[i] >= BASE) {
            c->num[i] -= BASE;
            c->num[i+1]++;
        }
    }

    if(c->num[c->len] == 0) {
        c->num = realloc(c->num, sizeof(int) * c->len);
    } else {
        c->len++;
    }

    return c;
}
