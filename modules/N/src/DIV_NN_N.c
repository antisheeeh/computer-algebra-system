/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/memory.h"

#include "../lib/DIV_NN_N.h"

longNumberN* divN(longNumberN* a, longNumberN* b) {
    longNumberN* res = malloc(sizeof(longNumberN));
    
    res->len = a->len - b->len;

    if(res->len < 1) res->len = 1; 

    if(compare(a, multiplyBy10k(b, res->len * BLOCK_SIZE)) == LESS) {
        res->len--;
    }

    res->len++;

    res->num = malloc(res->len * sizeof(int));

    int i;

    for(i = res->len - 1; i >= 0; --i) {
        res->num[i] = div_nn_dk(a, b, i * BLOCK_SIZE);
        a = sub_ndn(a, multiplyBy10k(b, i * BLOCK_SIZE), res->num[i]);
    }

    return res;
}