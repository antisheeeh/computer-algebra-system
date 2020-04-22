/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <string.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/MUL_NK_N.h"

longNumberN* multiBy10k(longNumberN* number, int k) {
    longNumberN* res = malloc(sizeof(longNumberN));

    res->len = number->len + k;
    res->num = calloc(res->len, sizeof(int));
    //Добавляем нули в конце числа
    for(int i = k; i < res->len; ++i) {
        res->num[i] = number->num[i - k];
    }

    return res;
}