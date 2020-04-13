/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/COM_NN_D.h"

#include "../lib/SUB_NN_N.h"

longNumberN* subN(longNumberN* a, longNumberN* b) {
    longNumberN* c = malloc(sizeof(longNumberN));

    c->len = a->len;
    c->num = calloc(c->len, sizeof(int));

    for(int i = 0; i < c->len; ++i) {
        c->num[i] += a->num[i];

        if(i < b->len) {
            c->num[i] -= b->num[i];
        }

        if(c->num[i] < 0) {
            c->num[i] += BASE;
            c->num[i + 1]--;
        }
    }

    removeLeadingZerosN(c);

    return c;
}