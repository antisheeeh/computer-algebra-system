#include "../lib/ADD_ZZ_Z.h"

#include "../lib/ADD_ZZ_Z.h"
#include "../lib/MUL_ZM_Z.h"

longNumberZ* subZ(longNumberZ* a, longNumberZ* b) {
    return sumZ(a, changeSign(b));
}