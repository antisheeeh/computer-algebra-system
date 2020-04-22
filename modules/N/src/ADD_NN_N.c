/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include <stdlib.h>
#include "../utils/lib/input.h"

#include "../lib/ADD_NN_N.h"

longNumberN* sumN(longNumberN* a, longNumberN* b) {
    longNumberN* c = malloc(sizeof(longNumberN));

    //добавление незначащего нуля к результату для случая переполнения

    c->len = a->len > b->len ? a->len + 1 : b->len + 1;
    c->num = calloc(c->len, sizeof(int));

    for(int i = 0; i < c->len - 1; ++i) {
        if(i >= a->len){
            c->num[i] += b->num[i];
        } else if(i >= b->len) {
            c->num[i] += a->num[i];
        } else {
            c->num[i] += a->num[i] + b->num[i];
        }

        //перенос единицы в следующий разряд результата

        if(c->num[i] >= BASE) {
            c->num[i] -= BASE;
            c->num[i + 1]++;
        }
    }

    removeLeadingZerosN(c);
    
    return c;
}