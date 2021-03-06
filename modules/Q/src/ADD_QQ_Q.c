/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>

#include "../../../modules/N/lib/DIV_NN_N.h"
#include "../../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../../modules/Z/lib/ADD_ZZ_Z.h" 
#include "../../../modules/N/lib/LCM_NN_N.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"
#include "../lib/RED_Q_Q.h"

#include "../lib/ADD_QQ_Q.h"

longNumberQ* addQ(longNumberQ* a , longNumberQ* b){
    a = redQ(a);
    b = redQ(b);

    longNumberQ *res = malloc(sizeof(longNumberQ));
    
    res->denominator = lcmN(a->denominator , b->denominator);

    res->numerator = sumZ(multiZ(a->numerator, transNtoZ(divN(res->denominator, a->denominator))), 
    multiZ(b->numerator, transNtoZ(divN(res->denominator, b->denominator))));
    
    return redQ(res);
}