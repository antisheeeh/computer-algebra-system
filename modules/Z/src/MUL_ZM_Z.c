/*
    author Valentin Pronin
    group 9305
*/

#include <stdio.h>

#include "../lib/MUL_ZM_Z.h"

longNumberZ* changeSign(longNumberZ* number) {
    if(number->sign == PLUS) {
        number->sign = MINUS;
    } else if(number->sign == MINUS) {
        number->sign = PLUS;
    }
    
    return number;
}