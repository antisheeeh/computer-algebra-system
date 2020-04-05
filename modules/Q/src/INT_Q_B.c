/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdio.h>
#include <string.h>

#include "../utils/lib/input.h"
#include "../lib/INT_Q_B.h"

int isInt(longNumberQ *a)
{
    if((strcmp(toStringZ(a->numerator),toStringN(a->denominator))) == 0) return WHOLE;
    else return NONWHOLE;
    
    return 1;
}