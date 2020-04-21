#include <stdio.h>

#include "../lib/DIV_ZZ_Z.h"
#include "../lib/MUL_ZZ_Z.h"
#include "../lib/SUB_ZZ_Z.h"
#include "../lib/POZ_Z_D.h"

#include "../lib/MOD_ZZ_Z.h"

longNumberZ* modZ(longNumberZ* a, longNumberZ* b) {
    if(getSign(b) == NEUTRAL) return NULL;
    return subZ(a, multiZ(b, divZ(a, b)));
}