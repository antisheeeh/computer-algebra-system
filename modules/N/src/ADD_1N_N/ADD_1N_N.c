#include <stdlib.h>

#include "../../lib/ADD_1N_N/ADD_1N_N.h"
#include "../../../../utils/input.h"

longNumber* inc(longNumber* number) {
    number->len++;
    number->num = realloc(number->num, number->len * sizeof(int));

    if(number->num == NULL) return NULL;

    number->num[number->len - 1] = 0;
    number->num[0]++;

    for(int i = 0; i < number->len - 1; ++i) {
        if(number->num[i] >= BASE) {
            number->num[i] -= BASE;
            number->num[i + 1]++;
        }
    }

    removeTrailingZeros(number);

    return number;
}