/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/ADD_NN_N.h"

longNumberN* sumN(longNumberN* a, longNumberN* b) {
    longNumberN* c = malloc(sizeof(longNumberN));

    if(a->len > b->len) c->len = a->len + 1;
    else c->len = b->len + 1;

    c->num = calloc(c->len, sizeof(int));

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
            c->num[i + 1]++;
        }
    }

    removeLeadingZerosN(c);
    
    return c;
}