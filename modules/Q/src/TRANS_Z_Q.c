/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include "../lib/TRANS_Z_Q.h"

longNumberQ *zToQ(longNumberZ *a)
{
    longNumberQ *res = NULL;
    res = malloc(sizeof(longNumberQ));
    res->denominator = malloc(sizeof(longNumberN));
    if(res == NULL) return NULL;

    
    res->numerator = a;
    res->denominator = parseNumberN("1"); // Something wrong here with parseNumber

    return res;
}