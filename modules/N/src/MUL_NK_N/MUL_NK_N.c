/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../../../utils/input.h"

longNumber* multiplyBy10k(longNumber* a, int k) {
    if(k == 0) return a;

    char* str = toString(a);
    int len = strlen(str), i;
    char* res = malloc((len + k + 1) * sizeof(char));

    if(res == NULL) return NULL;

    strcpy(res, str);

    for(i = len; i < len + k; ++i) res[i] = '0';

    res[len + k] = '\0';

    return parseNumber(res);
}


/*longNumber* multiplyBy10k(longNumber* a, int k) {
    longNumber* c = malloc(sizeof(longNumber));

    if(c == NULL) return NULL;

    c->len = a->len + k / BLOCK_SIZE;
    c->num = calloc(c->len, sizeof(int));

    if(c->num == NULL) return NULL;

    if(k % BLOCK_SIZE != 0) {
        c->num = multiByDigit();
    }

    int i;
    
    for(i = k / BLOCK_SIZE; i < c->len; ++i) {
        c->num[i] = a->num[i - k / BLOCK_SIZE];
    }

    multiByDigit();
    k % BLOCK_SIZE;

    removeTrailingZeros(c);
}*/