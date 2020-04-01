/*
    author Valentin Pronin
    group 9305
*/

#include <stdlib.h>

#include "../lib/POZ_Z_D.h"

int getSign(longNumberZ* number) {
    if(number->sign == PLUS) return POSITIVE;
    if(number->sign == MINUS) return NEGATIVE;
    return ZERO;
}