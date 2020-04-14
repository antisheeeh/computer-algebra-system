#include "../lib/FAC_P_Q.h"

#include "../../N/lib/GCF_NN_N.h"
#include "../../N/lib/LCM_NN_N.h"
#include "../../N/lib/NZER_N_B.h"
#include "../../Z/lib/TRANS_Z_N.h"

void facP(longNumberP* number, longNumberN** gcf, longNumberN** lcm) {
    *gcf = transZtoN(number->coefficient[number->degree]->numerator);
    *lcm = number->coefficient[number->degree]->denominator;

    for(int i = number->degree - 1; i >= 0; --i) {
        if(!isZero(transZtoN(number->coefficient[i]->numerator))) {
            *gcf = gcfN(*gcf, transZtoN(number->coefficient[i]->numerator));
        }

        *lcm = lcmN(*lcm, number->coefficient[i]->denominator);
    }
}