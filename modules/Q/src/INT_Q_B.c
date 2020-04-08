/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdio.h>
#include <string.h>

#include "../utils/lib/input.h"
#include "../lib/INT_Q_B.h"

int isInt(longNumberQ *a){
    return isZero(transZtoN(modZ(a->numerator, transNtoZ(a->denominator))));
}