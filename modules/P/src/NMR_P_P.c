#include "../lib/NMR_P_P.h"

#include "../lib/GCF_PP_P.h"
#include "../lib/DER_P_P.h"
#include "../lib/DIV_PP_P.h"

longNumberP* multipleRootsToSimple(longNumberP* number) {
    return divP(number, gcfP(number, derP(number)));
}