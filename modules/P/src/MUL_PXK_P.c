#include <stdlib.h>
#include "../../../modules/Q/utils/lib/input.h"
#include "../lib/MUL_PXK_P.h"

longNumberP* multyByXk(longNumberP* number, int k) {
    longNumberP* res = malloc(sizeof(longNumberP));

    res->degree = number->degree + k;
    res->coefficient = malloc((res->degree + 1) * sizeof(longNumberQ*));

    for(int i = res->degree; i >= k; --i) {
        res->coefficient[i] = number->coefficient[i - k];
    }

    for(int i = k - 1; i >= 0; i--){
        res->coefficient[i] = parseNumberQ("0");
    }

    return res;
}