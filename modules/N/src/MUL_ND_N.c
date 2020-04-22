/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>
#include "../utils/lib/input.h"

#include "../lib/MUL_ND_N.h"

longNumberN* multiByDigit(longNumberN* number, int digit) {
    longNumberN* c = malloc(sizeof(longNumberN));

    c->len = number->len + 1;
    c->num = calloc(c->len, sizeof(int));    

    long long temp;

    for(int i = 0; i < c->len - 1; ++i) {
        //The result of multiplying two numbers//
        temp = c->num[i] + number->num[i] * 1ll * digit;
        //The remainder of the division goes to this digit
        c->num[i] = temp % BASE;
        //The remainder of the intger division goes to the next digit
        c->num[i + 1] += temp / BASE;
    }

    removeLeadingZerosN(c);

    return c;
}