#include "../../lib/DIV_NN_Dk/DIV_NN_Dk.h"
#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../lib/COM_NN_D/COM_NN_D.h"
#include "../../lib/SUB_NN_N/SUB_NN_N.h"

int div_nn_dk(longNumber* a, longNumber* b, int k) {
    longNumber* c = multiplyBy10k(b, k);
    int res = compare(a, c);

    if(res == LESS) {
        return 0;
    } else if(res == EQUAL) {
        return 1;
    } else if(res == GREATER) {
        int l = 0, r = c->num[0];

        res = 0;
        
        while((compare(a, c) == GREATER) || (compare(a, c) == EQUAL)) {
            a = sub(a, c);
            res++;
        }
        
        while (res > 9){            
            res = res/10;
        }
        
        return res;
    }
}