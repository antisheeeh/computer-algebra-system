#include <stdio.h>
#include <string.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/DIV_NN_Dk.h"

int power(int a, int b) {
    int res = 1;
    while(b--) res *= a;
    return res;
}

int div_nn_dk(longNumberN* a, longNumberN* b, int k) {
    longNumberN* c = multiplyBy10k(b, k);
    int res = compare(a, c);

    if(res == LESS) {
        clearStructN(c);
        return 0;
    }

    if(res == EQUAL) {
        clearStructN(c);
        return 1;
    }

    int l = 0, r, m, i, len = 0;

    longNumberN* cut = malloc(sizeof(longNumberN));
    cut->len = b->len;
    cut->num = malloc(cut->len * sizeof(int));

    for(i = a->len - b->len; i < a->len; ++i) {
        cut->num[len++] = a->num[i];
    }

    if(compare(cut, b) == LESS) {
        cut->len++;
        cut->num = realloc(cut->num, cut->len * sizeof(int));
        for(i = cut->len - 1; i > 0; --i) cut->num[i] = cut->num[i - 1];
        cut->num[0] = a->num[a->len - b->len - 1];
    }

    r = power(10, strlen(toStringN(cut)) - strlen(toStringN(b)) + 1);

    while(l < r) {
        m = (l + r) / 2;

        res = compare(cut, multiByDigit(b, m));

        if(res == LESS) {
            r = m - 1;
        } else if(res == GREATER) {
            l = m + 1;
        } else if(res == EQUAL) {
            break;
        }
    }

    clearStructN(c);
    clearStructN(cut);
    return m;
}