/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>

#include "../lib/TRANS_Z_Q.h"
#include "../../N/utils/lib/input.h"

longNumberQ* transZtoQ(longNumberZ* number) {
    longNumberQ* res = malloc(sizeof(longNumberQ));

    res->numerator = number;
    res->denominator = parseNumberN("1");

    return res;
}