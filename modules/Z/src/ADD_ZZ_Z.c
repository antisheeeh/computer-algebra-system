/*
    author Valentin Pronin
    group 9305
*/
/*
#include "../lib/ADD_ZZ_Z.h"

longNumber* sumZ(longNumberZ* a, longNumberZ* b) {
    int aSign = checkSign(a);
    int bSign = checkSign(b);    

    if((aSign == POSITIVE) && (bSign == POSITIVE)) return sum(a,b);

    else if((aSign == POSITIVE) && (bSign == NEGATIVE)) {
        changeSign(b);

        if(compare(a,b) == GREATER) return sub(a,b);
        else{            
            return changeSign(sub(b,a));
        }
    }

    else if((aSign == NEGATIVE) && (bSign == POSITIVE)) {
        changeSign(a);     

        if(compare(a,b) == GREATER) return changeSign(sub(a,b));
        else{            
            return sub(b,a);
        }
    }

    else {
        changeSign(a);
        changeSign(b);

        return (changeSign(sum(a,b)));
    }
}
*/