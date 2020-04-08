/* 
    Author: Epifanstev Egor
    Group: 9305
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/DIV_NN_N.h"
/*
void div_nn_n(longNumberN *a , longNumberN *b)
{
    int i=0;
    int res[10];
    longNumberN *tmp;

    while(compare(a , b) == 2){
        res[i] = div_nn_dk(a,b,0);
        printf("Digit: %d\n" , res[i]);
        tmp = multiByDigit(b,res[i]);
        a = sub_ndn(a,b,res[i]*pow(10,strlen(toStringN(a)) - strlen(toStringN(tmp))));
        puts(toStringN(a));
        i++;
    }
}
*/