/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include "../lib/TRANS_Q_Z.h"

longNumberZ *transQtoZ(longNumberQ *a) {
    return divZ(a->numerator, transNtoZ(a->denominator));
}