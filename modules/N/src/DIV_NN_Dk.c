/*
    author Kirill Konoplev
    group 9305
*/

#include "../lib/DIV_NN_Dk.h"

int div_nn_dk(longNumberN* a, longNumberN* b, int k) {
    longNumberN* c = multiplyBy10k(b, k);

    int res = compare(a, c);

    if(res == LESS) return 0;
    if(res == EQUAL) return 1;

    int down = 0, up = BASE, mid;

    while(down < up - 1) {
        mid = (down + up) / 2;

        res = compare(a, multiByDigit(c, mid));

        if(res == EQUAL) break;

        if(res == LESS) {
            up = mid;
        } else if(res == GREATER) {
            down = mid;
        }
    }

    if(compare(a, multiByDigit(c, mid)) == LESS) mid--;

    return mid;
}