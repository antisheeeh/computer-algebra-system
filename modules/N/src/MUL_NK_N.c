/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>

#include "../lib/MUL_NK_N.h"

longNumberN* multiBy10k(longNumberN* number, int k) {
    longNumberN* res = malloc(sizeof(longNumberN));

    res->len = number->len + k;
    res->num = calloc(res->len, sizeof(int));

    //Adding zeros to the end of a number//
    
    for(int i = k; i < res->len; ++i) {
        res->num[i] = number->num[i - k];
    }

    return res;
}