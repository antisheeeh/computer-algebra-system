/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include "../utils/lib/memory.h"

#include "../../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"
#include "../../../modules/Z/lib/TRANS_Z_N.h"
#include "../lib/RED_Q_Q.h"

#include "../lib/DIV_QQ_Q.h"

longNumberQ* divQ(longNumberQ* a , longNumberQ* b) {   
    longNumberQ* res = malloc(sizeof(longNumberQ));

    res->numerator = multiZ(a->numerator , transNtoZ(b->denominator));
    res->denominator = transZtoN(multiZ(transNtoZ(a->denominator), b->numerator));

    return redQ(res);
}