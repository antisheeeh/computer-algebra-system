#include "../lib/NMR_P_P.h"

#include "../lib/GCF_PP_P.h"
#include "../lib/DER_P_P.h"
#include "../lib/DIV_PP_P.h"
#include "../lib/FAC_P_Q.h"

longNumberP* multipleRootsToSimple(longNumberP* number) {
    longNumberP* temp = divP(number, gcfP(number, derP(number)));
    return divP(temp, facP(temp));
}