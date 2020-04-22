/*
    author Kirill Konoplev
    group 9305
*/

#include <stddef.h>
#include "../utils/lib/input.h"

#include "../lib/SUB_NN_N.h"
#include "../lib/MUL_ND_N.h"
#include "../lib/COM_NN_D.h"

#include "../lib/SUB_NDN_N.h"

longNumberN* sub_ndn(longNumberN* a, longNumberN* b, int d) {
    if(compN(a, multiByDigit(b, d)) == LESS) return NULL;
    return subN(a, multiByDigit(b, d));
}