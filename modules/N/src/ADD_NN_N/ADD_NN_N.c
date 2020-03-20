/*
    author Kirill Konoplev and Egor Epifantsev
    group 9305
*/

#include "../../lib/ADD_NN_N/ADD_NN_N.h"

longNumber sum(longNumber a, longNumber b) {
    int i, carry = 0;
    longNumber c;

    c.len = max(a.len, b.len) + 1;
    c.num = calloc(c.len,sizeof(int));

    for(i = 0; i < c.len; ++i) {
        if(i > a.len){
            c.num[i] += b.num[i];
            if(c.num[i] >= BASE) {
                c.num[i] -= BASE;
                c.num[i+1]++;
            }
        } else if(i > b.len) {
            c.num[i] += a.num[i];
            if(c.num[i] >= BASE) {
                c.num[i] -= BASE;
                c.num[i+1]++;
            }
        } else {
            c.num[i] += a.num[i] + b.num[i];
            if(c.num[i] >= BASE) {
                c.num[i] -= BASE;
                c.num[i+1]++;
            }
        }
    }

    c.len = i;
    c.num = realloc(c.num, sizeof(int) * c.len);

    return c;
}