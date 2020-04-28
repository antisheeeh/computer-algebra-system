/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include "../../../modules/Z/lib/MOD_ZZ_Z.h"
#include "../../N/lib/NZER_N_B.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"
#include "../../../modules/Z/lib/TRANS_Z_N.h"

#include "../lib/INT_Q_B.h"

int isInt(longNumberQ* number){
    return isZeroN(transZtoN(modZ(number->numerator, transNtoZ(number->denominator))));
}