/*
   Author: Epifantsev Egor
   Group: 9305
*/

#include "../lib/NZER_N_B/NZER_N_B.h"

int isZero(longNumber a)
{
    int i;
    
    for(i = 0; i < a.len; i++) {
        if(a.num[i] != 0) return 0;
    }

    return 1;
}