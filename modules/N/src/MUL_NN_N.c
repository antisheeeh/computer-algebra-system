/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/input.h"

#include "../lib/MUL_ND_N.h"
#include "../lib/MUL_NK_N.h"
#include "../lib/ADD_NN_N.h"

#include "../lib/MUL_NN_N.h"

longNumberN* multiN(longNumberN* a, longNumberN* b) {
    if(a->len == 1) return multiByDigit(b, a->num[0]);
    if(b->len == 1) return multiByDigit(a, b->num[0]);

    longNumberN* res = parseNumberN("0");

    for(int i = 0; i < b->len; ++i) {
        res = sumN(res, multiBy10k(multiByDigit(a, b->num[i]), i));
    }

    return res;
}