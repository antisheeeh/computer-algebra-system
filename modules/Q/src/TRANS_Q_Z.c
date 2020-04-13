/* 
    Author: Epifantsev Egor
    Group: 9305
*/


#include "../../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"

#include "../lib/TRANS_Q_Z.h"

longNumberZ* transQtoZ(longNumberQ* number) {
    return divZ(number->numerator, transNtoZ(number->denominator));
}