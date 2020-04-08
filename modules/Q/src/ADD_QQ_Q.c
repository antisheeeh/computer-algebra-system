/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include "../lib/ADD_QQ_Q.h"
#include "../../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../../modules/Z/lib/ADD_ZZ_Z.h" 
#include "../../../modules/N/lib/LCM_NN_N.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"

longNumberQ *addQ(longNumberQ *a , longNumberQ *b){
    longNumberQ *res = malloc(sizeof(longNumberQ));

    if(res == NULL) return NULL;
    
    res->numerator = sumZ(multyZ(a->numerator , transNtoZ(b->denominator)), multyZ(b->numerator , transNtoZ(a->denominator)));
    res->denominator = lcmN(a->denominator , b->denominator);
    
    return res;
}