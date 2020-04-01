#include "../../lib/DIV_NN_Dk/DIV_NN_Dk.h"
#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../lib/COM_NN_D/COM_NN_D.h"
#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../../../utils/input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int div_nn_dk(longNumber* a, longNumber* b, int k) {
    longNumber* c = multiplyBy10k(b, k);
    int res = compare(a, c);

    if(res == LESS) {
        return 0;
    } else if(res == EQUAL) {
        return 1;
    } else if(res == GREATER) {
        int d = 2, lenC;

        char* strA = toString(a);
        char* strC = toString(c);
        char temp;

        lenC = strlen(strC);
        temp = strA[lenC];

        strA[lenC] = '\0';

        longNumber* t = parseNumber(strA);

        if(compare(t, c) == LESS) {
            strA[lenC] = temp;
            strA[lenC + 1] = '\0';

            t = parseNumber(strA);
        }

        while(compare(t, multiByDigit(c, d)) != LESS) ++d;

        return d - 1;
    }
}