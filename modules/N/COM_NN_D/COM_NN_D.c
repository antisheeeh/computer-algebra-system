#include "..//number.h"

int compare(longNumber a, longNumber b) {
    if(a.len > b.len) return GREATER;
    else if(a.len < b.len) return LESS;
    else {
        int i;

        for(i = 0; i < a.len; ++i) {
            if(a[i] > b[i]) return GREATER;
            else if(a[i] < b[i]) return LESS;
            else return EQUAL;
        }
    }
}
