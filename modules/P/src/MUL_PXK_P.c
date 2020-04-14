#include <stdlib.h>
#include "../lib/MUL_PXK_P.h"

longNumberP* multyByXk(longNumberP* number, int k) {
    longNumberP* res = malloc(sizeof(longNumberP));

    res->degree = number->degree + k;
    res->coefficient = malloc((res->degree+1) * sizeof(longNumberQ*));

    for(int i = res->degree; i >= k; --i) {
        res->coefficient[i] = number->coefficient[i - k];
    }

    for(int i = k-1; i >= 0; i--){
        res->coefficient[i] = malloc(sizeof(longNumberQ));
        res->coefficient[i]->numerator = malloc(sizeof(longNumberZ));
        res->coefficient[i]->numerator->num = malloc(sizeof(int));
        res->coefficient[i]->numerator->num[0] = 0;
        res->coefficient[i]->denominator = malloc(sizeof(longNumberN));
        res->coefficient[i]->denominator->num = malloc(sizeof(int));
        res->coefficient[i]->denominator->num[0] = 1;
    }

    return res;
}