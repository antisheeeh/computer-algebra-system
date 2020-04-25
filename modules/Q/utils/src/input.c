#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "../lib/input.h"
#include "../../../../modules/N/lib/number.h"
#include "../../../../modules/N/utils/lib/input.h"
#include "../../../../modules/Z/utils/lib/input.h"
#include "../../../../modules/Z/lib/TRANS_N_Z.h"

longNumberQ* parseNumberQ(char* str) {
    longNumberQ* number = malloc(sizeof(longNumberQ));

    char* s = copy(str);
    char* res = strtok(s, "/");

    if(strlen(res) == strlen(str)) {
        number->numerator = parseNumberZ(s);
        number->denominator = parseNumberN("1");
    } else {
        number->numerator = parseNumberZ(res);
        number->denominator = parseNumberN(strtok(NULL, "/"));
    }

    return number;
}

char* toStringQ(longNumberQ* number) {
    char* numerator = toStringZ(number->numerator);
    char* denominator = toStringN(number->denominator);
    char* res;
    
    if(strcmp(denominator, "1") == 0) {
        res = malloc((strlen(numerator) + 1) * sizeof(char));
        strcpy(res, numerator);
    } else {
        res = malloc((strlen(numerator) + strlen(denominator) + 2) * sizeof(char));
        strcpy(res, numerator);
        strcat(res, "/");
        strcat(res, denominator);
    }

    return res;
}
