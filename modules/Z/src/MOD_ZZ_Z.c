#include "../lib/MOD_ZZ_Z.h"

longNumberZ* modZ(longNumberZ* a, longNumberZ* b) {
    return subZ(a, multyZ(b, divZ(a, b)));
}