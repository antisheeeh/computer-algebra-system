#include <stdio.h>
#include <stdlib.h>
#include "../lib/ADD_PP_P.h"
#include "../../../modules/Q/lib/SUB_QQ_Q.h"
#include "../utils/lib/input.h"

longNumberP *subP(longNumberP* a , longNumberP * b)
{
    int i;
    longNumberP *res = malloc(sizeof(longNumberQ));

    if(a->degree > b->degree) res->degree = a->degree;
    else res->degree = b->degree;

    res->coefficient = malloc((res->degree+1) * sizeof(longNumberQ*));

    for(i = 0; i <= res->degree; i++){
        if(i > a->degree){
            res->coefficient[i] = b->coefficient[i];
        } else if(i > b->degree) {
            res->coefficient[i] = a->coefficient[i];
        } else {
            res->coefficient[i] = subQ(a->coefficient[i] , b->coefficient[i]);
        }
    }

    removeLeadingZerosP(res);

    return res;
}