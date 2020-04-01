/*
   Author: Epifantsev Egor
   Group: 9305
*/

#include "../lib/NZER_N_B.h"

int isZero(longNumberN* a) {
    return a->num[a->len - 1] ? NO : YES;
}