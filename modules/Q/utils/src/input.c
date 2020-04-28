#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../../modules/N/lib/number.h"
#include "../../../../modules/N/utils/lib/input.h"
#include "../../../../modules/Z/utils/lib/input.h"
#include "../../../../modules/Z/lib/TRANS_N_Z.h"

#include "../lib/input.h"

longNumberQ* parseNumberQ(char* s) {
    char* str = copyZ(s);

    removeSpacesQ(str);
    
    if(!isValidQ(str)) {
        puts("\nInvalid input");
        return NULL;
    }

    longNumberQ* number = malloc(sizeof(longNumberQ));
 
    char* res = strtok(str, "/");

    if(strlen(res) == strlen(s)) {
        number->numerator = parseNumberZ(res);
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

char* copyQ(char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    return res;
}

void removeSpacesQ(char* s) {
    const char* d = s;

    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int isValidQ(char* str) {
    if(!str) return 0;

    if(*str == '\0') return 0;

    char* t = copyQ(str);

    char* numerator = strtok(t, "/");
    if(!isValidZ(numerator)) return 0;

    char* denominator = strtok(NULL, "/");
    if(denominator && !isValidN(denominator)) return 0;

    return 1;
}
