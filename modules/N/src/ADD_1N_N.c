/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>

#include "../lib/ADD_1N_N.h"
#include "../../../utils/lib/input.h"
#include "../../../utils/lib/memory.h"

longNumber* inc(longNumber* number) {
    longNumber* res = malloc(sizeof(longNumber));

    if(res == NULL) return NULL;

    res->len = number->len + 1;
    res->num = calloc(res->len, sizeof(int));

    if(res->num == NULL) {
        clearStruct(res);
        return NULL;
    }

    res->num[0]++;

    for(int i = 0; i < res->len - 1; ++i) {
        res->num[i] += number->num[i];

        if(res->num[i] >= BASE) {
            res->num[i] -= BASE;
            res->num[i + 1]++;
        }
    }

    removeTrailingZeros(res);

    return res;
}