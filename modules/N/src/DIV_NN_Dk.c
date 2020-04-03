#include <stdio.h>
#include <string.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/DIV_NN_Dk.h"

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

    int d = 2, lenC;

    char* strA = toStringN(a);
    char* strC = toStringN(c);
    char temp;

    lenC = strlen(strC);
    temp = strA[lenC];

    strA[lenC] = '\0';

    longNumberN* t = parseNumberN(strA);

    if(compare(t, c) == LESS) {
        strA[lenC] = temp;
        strA[lenC + 1] = '\0';

        t = parseNumberN(strA);
    }

    while(compare(t, multiByDigit(c, d)) != LESS) ++d;

    clearStructN(c);
    clearStructN(t);
    clearStringN(strA);
    clearStringN(strC);

    return d - 1;
}