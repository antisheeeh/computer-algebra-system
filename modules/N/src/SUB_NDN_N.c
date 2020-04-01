#include <stdlib.h>

#include "../lib/SUB_NDN_N.h"
#include "../lib/SUB_NN_N.h"
#include "../lib/MUL_ND_N.h"
#include "../lib/COM_NN_D.h"

#include "../../../utils/lib/input.h"
#include "../../../utils/lib/memory.h"

longNumber* sub_ndn(longNumber* a, longNumber* b, int d) {
    longNumber* temp = multiByDigit(b, d);

    if(compare(a, temp) == LESS) {
        clearStruct(temp);
        return NULL;
    }
    
    clearStruct(temp);
    return sub(a, temp);
}