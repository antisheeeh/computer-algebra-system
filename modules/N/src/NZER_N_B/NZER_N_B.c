/*
   Author: Epifantsev Egor
   Group: 9305
*/

#include "../../lib/NZER_N_B/NZER_N_B.h"

int isZero(longNumber* a) {
    return a->num[a->len - 1] ? NO : YES;
}