/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/ADD_1N_N.h"

longNumberN* incN(longNumberN* number) {
    longNumberN* res = malloc(sizeof(longNumberN));

    res->len = number->len + 1;
    res->num = calloc(res->len, sizeof(int));

    res->num[0]++;

    for(int i = 0; i < res->len - 1; ++i) {
        res->num[i] += number->num[i];

        if(res->num[i] >= BASE) {
            res->num[i] -= BASE;
            res->num[i + 1]++;
        }
    }

    removeLeadingZerosN(res);

    return res;
}