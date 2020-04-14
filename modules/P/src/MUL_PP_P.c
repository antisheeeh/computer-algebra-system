#include <stdio.h>
#include <stdlib.h>
#include "../lib/MUL_PQ_P.h"

#include "../../P/lib/MUL_PP_P.h"
#include "../../P/lib/ADD_PP_P.h"
#include "../../P/lib/MUL_PQ_P.h"
#include "../../P/lib/MUL_PXK_P.h"
#include "../../Q/lib/MUL_QQ_Q.h"
#include "../../Q/lib/ADD_QQ_Q.h"
#include "../utils/lib/input.h"
#include "../../N/utils/lib/input.h"
#include "../../Z/utils/lib/input.h"

longNumberP *mulP(longNumberP *a , longNumberP *b)
{
    longNumberP *res = malloc(sizeof(longNumberP));
    longNumberQ *tmp;

    res->degree = a->degree + b->degree;
    res->coefficient = malloc((res->degree + 1)*sizeof(longNumberQ*));

    for(int i = 0; i <= res->degree; i++){
        res->coefficient[i] = malloc(sizeof(longNumberQ));
        res->coefficient[i]->numerator = malloc(sizeof(longNumberZ));
        res->coefficient[i]->numerator->num = malloc(sizeof(int));
        res->coefficient[i]->numerator->num[0] = 0;
        res->coefficient[i]->numerator->len = 1;
        res->coefficient[i]->denominator = malloc(sizeof(longNumberN));
        res->coefficient[i]->denominator->num = malloc(sizeof(int));
        res->coefficient[i]->denominator->num[0] = 1;
        res->coefficient[i]->denominator->len = 1;
    }

    printNumberP(res);

    for(int i = 0; i <= a->degree; i++){
        for(int j = 0; j <= b->degree; j++){ //(x^2 + x + 1) * (x^3 + 1)
            
            
            //printf("Test: %s/%s * %s/%s\n" , toStringZ(a->coefficient[i]->numerator), toStringN(a->coefficient[i]->denominator) , toStringZ(b->coefficient[j]->numerator) , toStringN(b->coefficient[j]->denominator));
            //printf("Res: %s/%s" , toStringZ(mulQ(a->coefficient[i],b->coefficient[j])->numerator) , toStringN(mulQ(a->coefficient[i],b->coefficient[j])->denominator));
            //tmp = addQ(res->coefficient[i+j],mulQ(a->coefficient[i],b->coefficient[j]));
            //res->coefficient[i+j] = addQ(res->coefficient[i+j],mulQ(a->coefficient[i],b->coefficient[j]));
        }
    } 

    return res;
}