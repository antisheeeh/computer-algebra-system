/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/memory.h"

#include "../lib/DIV_NN_DK.h"
#include "../lib/MUL_NK_N.h"
#include "../lib/SUB_NDN_N.h"
#include "../lib/COM_NN_D.h"

#include "../lib/DIV_NN_N.h"

longNumberN* divN(longNumberN* a, longNumberN* b) {
    longNumberN* res = malloc(sizeof(longNumberN));
    
    res->len = a->len - b->len;

    if(res->len < 1) res->len = 1; 

    if(compN(a, multiBy10k(b, res->len)) == LESS) {
        res->len--;
    }

    res->len++;

    res->num = malloc(res->len * sizeof(int));

    for(int i = res->len - 1; i >= 0; --i) {
        res->num[i] = div_nn_dk(a, b, i);
        a = sub_ndn(a, multiBy10k(b, i), res->num[i]);
    }

    return res;
}