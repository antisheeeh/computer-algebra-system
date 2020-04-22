/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>
#include "../utils/lib/input.h"

#include "../lib/COM_NN_D.h"
#include "../lib/SUB_NN_N.h"

longNumberN* subN(longNumberN* a, longNumberN* b) {
    if(compN(a, b) == LESS) return NULL;
    
    longNumberN* c = malloc(sizeof(longNumberN));

    c->len = a->len;
    c->num = calloc(c->len, sizeof(int));

    for(int i = 0; i < c->len; ++i) {
        c->num[i] += a->num[i];

        //Вычитаем из числа a число b 
        if(i < b->len) {
            c->num[i] -= b->num[i];
        }

        //В случае отрицательного значения в разряде результирующего числа, заимствуется величина BASE из следующего разряда
        if(c->num[i] < 0) {
            c->num[i] += BASE;
            c->num[i + 1]--;
        }
    }

    removeLeadingZerosN(c);

    return c;
}