/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include <stdlib.h>

#include "../../lib/ADD_NN_N/ADD_NN_N.h"
#include "../../lib/COM_NN_D/COM_NN_D.h"
#include "../../../../utils/input.h"

longNumber* sum(longNumber* a, longNumber* b) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = max(a->len, b->len) + 1;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) return NULL;

    int i;

    for(i = 0; i < c->len - 1; ++i) {
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

    removeTrailingZeros(c);
    
    return c;
}