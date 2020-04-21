#include <stdio.h>
#include <stdlib.h>
#include "../lib/DER_P_P.h"
#include "../../Q/lib/MUL_QQ_Q.h"
#include "../../Q/lib/TRANS_Z_Q.h"
#include "../../Z/utils/lib/input.h"


longNumberP *derP(longNumberP *a)
{
    longNumberP *res = malloc(sizeof(longNumberP));
    char str[BLOCK_SIZE];

    res->degree = a->degree - 1;
    
    res->coefficient = malloc((res->degree + 1) * sizeof(longNumberQ*)); 

    for(int i = 0; i <= res->degree; i++){
        sprintf(str, "%d", i + 1);
        res->coefficient[i] = mulQ(a->coefficient[i + 1], transZtoQ(parseNumberZ(str)));
    }

    return res;
}