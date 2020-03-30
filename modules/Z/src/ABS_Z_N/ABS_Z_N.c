/*
    author Valentin Pronin
    group 9305
*/

#include <stdlib.h>
#include "../../../N/lib/number.h"
#include "../../lib/ABS_Z_N/ABS_Z_N.h"

longNumber* absolute(longNumber* number){  
    if (number->num[number->len-1] < 0) number->num[number->len-1] *= -1;    
    return number;
}