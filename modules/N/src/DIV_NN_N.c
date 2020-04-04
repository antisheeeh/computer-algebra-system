#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../utils/lib/input.h"

#include "../lib/DIV_NN_N.h"

longNumberN* divN(longNumberN* a, longNumberN* b) {
    longNumberN* res = malloc(sizeof(longNumberN));

    res->len = a->len;
    res->num = calloc(res->len, sizeof(int));

    int i = 0, j;

    for(i = res->len - 1; compare(a, b) != LESS; --i) {
        for(j = res->len - 1; j > 0; --j) res->num[j] = res->num[j - 1];
        res->num[0] = div_nn_dk(a, b, 0);
        a = subN(a, multiplyBy10k(multiByDigit(b, res->num[0]), i * BLOCK_SIZE));
    }

    removeLeadingZerosN(res);

    return res;
}