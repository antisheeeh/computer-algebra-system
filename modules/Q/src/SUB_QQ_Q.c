/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include "../lib/SUB_QQ_Q.h"
#include "../../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../../modules/Z/lib/SUB_ZZ_Z.h" 
#include "../../../modules/N/lib/LCM_NN_N.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"
#include "../lib/RED_Q_Q.h"

longNumberQ *subQ(longNumberQ *a , longNumberQ *b){
    longNumberQ *res = malloc(sizeof(longNumberQ));

    if(res == NULL) return NULL;
    
    res->numerator = subZ(multiZ(a->numerator , transNtoZ(b->denominator)), multiZ(b->numerator , transNtoZ(a->denominator)));
    res->denominator = lcmN(a->denominator , b->denominator);
    
    return redQ(res);
}