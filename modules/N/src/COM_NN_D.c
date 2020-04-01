/*
    author Kirill Konoplev
    group 9305
*/

#include "../lib/COM_NN_D.h"

int compare(longNumberN* a, longNumberN* b) {
    if(a->len > b->len) return GREATER;
    if(a->len < b->len) return LESS;

    for(int i = a->len - 1; i >= 0; --i) {
        if(a->num[i] > b->num[i]) return GREATER;
        if(a->num[i] < b->num[i]) return LESS;
    }

    return EQUAL;
}