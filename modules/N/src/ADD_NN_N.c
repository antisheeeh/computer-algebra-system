/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include <stdlib.h>
#include "../utils/lib/input.h"

#include "../lib/ADD_NN_N.h"

longNumberN* sumN(longNumberN* a, longNumberN* b) {
    longNumberN* c = malloc(sizeof(longNumberN));

    //Adding a negligible zero to the result when overflow occurs//

    c->len = a->len > b->len ? a->len + 1 : b->len + 1;
    c->num = calloc(c->len, sizeof(int));

    for(int i = 0; i < c->len - 1; ++i) {
        if(i >= a->len){
            c->num[i] += b->num[i];
        } else if(i >= b->len) {
            c->num[i] += a->num[i];
        } else {
            c->num[i] += a->num[i] + b->num[i];
        }

        //Transfer "1" to the next digit of the number//

        if(c->num[i] >= BASE) {
            c->num[i] -= BASE;
            c->num[i + 1]++;
        }
    }

    removeLeadingZerosN(c);
    
    return c;
}