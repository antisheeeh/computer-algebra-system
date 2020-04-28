#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/input.h"
#include "../../../Z/lib/TRANS_Z_N.h"
#include "../../../Z/lib/POZ_Z_D.h"
#include "../../../N/lib/NZER_N_B.h"
#include "../../../Z/utils/lib/input.h"
#include "../../../N/utils/lib/input.h"
#include "../../../Q/utils/lib/input.h"
#include "../../../Q/lib/INT_Q_B.h"
#include "../../../Q/lib/TRANS_Q_Z.h"
#include "../../../N/lib/NZER_N_B.h"

longNumberP* parseNumberP(char* s) {
    char* str = copyP(s);

    removeSpacesP(str);

    if(!isValidP(str)) return NULL;

    longNumberP* number = malloc(sizeof(longNumberP));
    
    char** monomials = getMonomials(str);
    int count = getCount(monomials);

    number->degree = getMaxPower(monomials);
    number->coefficient = malloc((number->degree + 1) * sizeof(longNumberQ*));

    int i, j = 0;

    for(i = number->degree; i >= 0; --i) {
        if(j < count && atoi(getPower(monomials[j])) == i) {
            number->coefficient[i] = parseNumberQ(getCoef(monomials[j]));
            j++;
        } else {
            number->coefficient[i] = parseNumberQ("0");
        }
    }

    removeLeadingZerosP(number);

    return number;
}

char* toStringP(longNumberP *number) {
    char* str = malloc(15000 * sizeof(char));
    char buf[1024];

    strcpy(str, "");

    int i;

    if(number->degree == 0 && number->coefficient[0]->numerator->num[0] == 0) return "0";

    for(i = number->degree; i >= 0; --i) {
        if(!isZero(transZtoN(number->coefficient[i]->numerator))) {
            if(getSign(number->coefficient[i]->numerator) == PLUS) {
                if(i != number->degree) {
                    strcat(str, " + ");
                }
            }

            char* numerator = toStringZ(number->coefficient[i]->numerator);
            char* denominator = toStringN(number->coefficient[i]->denominator);

            if(i != 0 && strcmp(numerator, "1") == 0 && strcmp(denominator, "1") == 0) {
                
            } else {
                strcat(str, toStringQ(number->coefficient[i]));
            }

            if(i == 1) {
                strcat(str, "x");
            } else if(i != 0) {
                strcat(str, "x^");
                sprintf(buf, "%d", i);
                strcat(str, buf);
            }
        }
    }

    return str;
}

char** getMonomials(char* str) {
    char** words;
    char* word;
    int power = 1, count = 0, t = 0, len = 0, i;

    words = malloc(sizeof(char*));

    for(i = 0; i <= strlen(str); ++i) {
        if(count == power) {
            words = realloc(words, (power *= 2) * sizeof(char*));
        }

        if(i != 0 && (str[i] == '+' || str[i] == '-' || str[i] == '\0')) {
            words[count] = malloc((i - len + 1) * sizeof(char));
            strncpy(words[count], str + len, i - len + 1);
            len = i;
            count++;
        }
    }

    words = realloc(words, (count + 1) * sizeof(char*));
    words[count] = NULL;

    return words;
}

int getCount(char** monomials) {
    int count = 0;
    while(monomials[count]) count++;
    return count;
}

char* getCoef(char* str) {
    char* s = copy(str);

    if(strlen(s) == 1 && (s[0] == '+' || s[0] == '-')) return s;

    if(s[0] == 'x') return "1";

    char* res = strtok(s, "x");

    if(strcmp(res, "+") == 0 || strcmp(res, "+1") == 0 || strcmp(res, "1") == 0) return "1";
    if(strcmp(res, "-") == 0 || strcmp(res, "-1") == 0) return "-1";

    return res;
}

char* getPower(char* str) {
    char* s = copy(str);

    char* res = strtok(s, "^");

    if(strlen(res) == strlen(str)) {
        if(strcmp(str, "x") == 0) return "1";

        char* t = copy(str);

        res = strtok(t, "x");

        if(strlen(res) == strlen(str)) {
            return "0";
        } else {
            return "1";
        }
    } else {
        return strtok(NULL, "^");
    }
}

int getMaxPower(char** str) {
    int i, mx, p;

    if(str[0] != NULL) mx = atoi(getPower(str[0]));

    for(i = 0; str[i] != NULL; ++i) {
        p = atoi(getPower(str[i]));
        if(p > mx) mx = p;
    }

    return mx;
}

void removeSpacesP(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

char* copyP(char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    return res;
}

void removeLeadingZerosP(longNumberP *number) {
    while(number->degree > 0 && isZero(transZtoN(number->coefficient[number->degree]->numerator))) number->degree--;
    number->coefficient = realloc(number->coefficient, (number->degree + 1) * sizeof(longNumberQ*));
}

int isValidP(char* str) {
    if(!str) return 0;

    if(*str == '\0') return 0;

    char* t = copy(str);

    char** monomials = getMonomials(t);
    int count = getCount(monomials);

    for(int i = 0; i < count; ++i) {
        char* coef = getCoef(monomials[i]);
        if(!isValidQ(coef)) return 0;

        char* power = getPower(monomials[i]);
        if(!power || strlen(power) > 9) return 0;
    }

    return 1;
}