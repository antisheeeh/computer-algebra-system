#include <stdlib.h>
#include <stdio.h>
#include "../../../modules/Q/lib/ADD_QQ_Q.h"
#include "../lib/ADD_PP_P.h"
#include "../../../modules/Q/utils/lib/input.h"
#include "../utils/lib/input.h"

longNumberP* sumP(longNumberP* a , longNumberP* b) {
    longNumberP* res = malloc(sizeof(longNumberP));

    if(a->degree > b->degree) res->degree = a->degree;
    else res->degree = b->degree;

    res->coefficient = malloc((res->degree + 1) * sizeof(longNumberQ*));

    for(int i = 0; i <= res->degree; i++){
        if(i > a->degree){
            res->coefficient[i] = b->coefficient[i];
        } else if(i > b->degree) {
            res->coefficient[i] = a->coefficient[i];
        } else {
            res->coefficient[i] = addQ(a->coefficient[i] , b->coefficient[i]);
        }
    }

    removeLeadingZerosP(res);

    return res;
}