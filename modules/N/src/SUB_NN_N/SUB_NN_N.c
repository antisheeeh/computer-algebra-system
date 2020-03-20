/*
    author Kirill Konoplev
    group 9305
*/

#include "../../lib/SUB_NN_N/SUB_NN_N.h"

longNumber sub(longNumber a, longNumber b) {
    int i;

    for(i = 0; i < a.len; ++i) {
        if(i < b.len) {
            a.num[i] -= b.num[i];
        }

        if(a.num[i] < 0) {
            a.num[i] += BASE;
            a.num[i+1]--;
        }
    }

    return a;
}