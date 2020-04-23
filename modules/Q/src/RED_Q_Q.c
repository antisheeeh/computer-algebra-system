/*
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include <stdio.h>

#include "../../../modules/N/lib/GCF_NN_N.h"
#include "../../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../../modules/Z/lib/TRANS_Z_N.h"
#include "../../../modules/Z/lib/TRANS_N_Z.h"

#include "../lib/RED_Q_Q.h"

longNumberQ* redQ(longNumberQ* number) {
    longNumberQ* res = malloc(sizeof(longNumberQ));

    res->numerator = divZ(number->numerator , transNtoZ(gcfN(transZtoN(number->numerator), number->denominator)));
    res->denominator = transZtoN(divZ(transNtoZ(number->denominator), transNtoZ(gcfN(transZtoN(number->numerator), number->denominator))));

    return res;
}