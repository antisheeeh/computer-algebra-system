/*
    author Kirill Konoplev
    group 9305
*/

#include "../lib/MUL_NK_N.h"
#include "../lib/COM_NN_D.h"
#include "../lib/MUL_ND_N.h"

#include "../lib/DIV_NN_DK.h"

int div_nn_dk(longNumberN* a, longNumberN* b, int k) {
    longNumberN* c = multiBy10k(b, k);
    
    int res = compN(a, c);

    if(res == LESS) return 0;
    if(res == EQUAL) return 1;

    int down = 0, up = BASE, mid;

    //Dichotomy method to get the first digit of the divisor//

    while(down < up - 1) {
        mid = (down + up) / 2;

        res = compN(a, multiByDigit(c, mid));

        if(res == EQUAL) break;

        if(res == LESS) {
            up = mid;
        } else if(res == GREATER) {
            down = mid;
        }
    }

    if(compN(a, multiByDigit(c, mid)) == LESS) mid--;

    return mid;
}
