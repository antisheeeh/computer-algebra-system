/*
    author Kirill Konoplev
    group 9305
*/

#include "..//number.h"

int compare(longNumber a, longNumber b) {
    if(a.len > b.len) return GREATER;
    else if(a.len < b.len) return LESS;
    else {
        int i;

        for(i = 0; i < a.len; ++i) {
            if(a.num[i] > b.num[i]) return GREATER;
            else if(a.num[i] < b.num[i]) return LESS;
            else return EQUAL;
        }
    }
}