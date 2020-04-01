/*
    author Valentin Pronin
    group 9305
*/

#include <stdlib.h>

#include "../lib/ABS_Z_N.h"

longNumberZ* absolute(longNumberZ* number) {
    if(number->sign == MINUS) number->sign = PLUS;
    return number;
}