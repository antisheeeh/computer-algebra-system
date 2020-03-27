#include <stdlib.h>

#include "../../lib/SUB_NDN_N/SUB_NDN_N.h"
#include "../../lib/SUB_NN_N/SUB_NN_N.h"
#include "../../lib/MUL_ND_N/MUL_ND_N.h"
#include "../../lib/COM_NN_D/COM_NN_D.h"

longNumber* sub_ndn(longNumber* a, longNumber* b, int d) {
    longNumber* res = sub(a, multiByDigit(b, d));

    if(compare(res, 0) == LESS) return NULL;
    return res;
}