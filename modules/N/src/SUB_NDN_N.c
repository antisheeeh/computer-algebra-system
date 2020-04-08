/*
    author Kirill Konoplev
    group 9305
*/

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/SUB_NDN_N.h"

longNumberN* sub_ndn(longNumberN* a, longNumberN* b, int d) {
    longNumberN* temp = multiByDigit(b, d);

    if(compare(a, temp) == LESS) {
        clearStructN(temp);
        return NULL;
    }
    
    longNumberN* res = subN(a, temp);
    clearStructN(temp);

    return res;
}