/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include <stdio.h>

#include "../../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"
#include "../../../modules/Z/lib/TRANS_Z_N.h"
#include "../../../modules/Z/lib/MUL_ZM_Z.h"
#include "../../../modules/Q/utils/lib/input.h"
#include "../lib/RED_Q_Q.h"

#include "../lib/DIV_QQ_Q.h"

longNumberQ* divQ(longNumberQ* a , longNumberQ* b) {
    a = redQ(a);
    b = redQ(b);

    longNumberQ* res = malloc(sizeof(longNumberQ));
    
    res->numerator = multiZ(a->numerator , transNtoZ(b->denominator));
    res->denominator = transZtoN(multiZ(transNtoZ(a->denominator), b->numerator));

    if(b->numerator->sign == MINUS) res->numerator = changeSign(res->numerator);

    return redQ(res);
}