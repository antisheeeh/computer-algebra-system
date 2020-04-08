/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>

#include "../lib/TRANS_Z_Q.h"

longNumberQ* transeZtoQ(longNumberZ* a) {
    longNumberQ* res = malloc(sizeof(longNumberQ));

    res->numerator = a;
    res->denominator = parseNumberN("1");

    return res;
}