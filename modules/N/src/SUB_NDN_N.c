#include <stdlib.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/SUB_NN_N.h"
#include "../lib/MUL_ND_N.h"
#include "../lib/COM_NN_D.h"

#include "../lib/SUB_NDN_N.h"

longNumberN* sub_ndn(longNumberN* a, longNumberN* b, int d) {
    longNumberN* temp = multiByDigit(b, d);

    if(compare(a, temp) == LESS) {
        clearStructN(temp);
        return NULL;
    }
    
    clearStructN(temp);
    return subN(a, temp);
}