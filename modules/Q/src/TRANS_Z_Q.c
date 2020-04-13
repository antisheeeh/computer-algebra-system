/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>

#include "../lib/TRANS_Z_Q.h"

longNumberQ* transZtoQ(longNumberZ* number) {
    longNumberQ* res = malloc(sizeof(longNumberQ));

    res->numerator = number;
    res->denominator = malloc(sizeof(longNumberN));
    res->denominator->len = 1;
    res->denominator->num[0] = 1;

    return res;
}