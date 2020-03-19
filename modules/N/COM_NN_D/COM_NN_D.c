#include "..//number.h"

int compare(longNumber a, longNumber b) {
    if(a.len > b.len) return GREATER;
    else if(a.len < b.len) return LESS;
    else {
        int i, j, p = 1;

        for(i = 0; i < a.len; ++i) {
            if(a.num[i] / p % 10 > a.num[i] / p % 10) {
                return GREATER;
            } else if(a.num[i] / p % 10 < a.num[i] / p % 10) {
                return LESS;
            } else {
                return EQUAL;
            }

            p *= 10;
        }
    }
}
