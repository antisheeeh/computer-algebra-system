/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include "../lib/SUB_QQ_Q.h"
#include "../lib/ADD_QQ_Q.h"
#include "../../../modules/Z/lib/MUL_ZM_Z.h"
#include "../lib/RED_Q_Q.h"

longNumberQ *subQ(longNumberQ *a , longNumberQ *b){
    a = redQ(a);
    b = redQ(b);

    b->numerator = changeSign(b->numerator);
    longNumberQ* res = addQ(a, b);
    
    return redQ(res);
}