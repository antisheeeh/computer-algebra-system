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

longNumberP* parseNumberP(char* str) {
    longNumberP* number = malloc(sizeof(longNumberP));

    removeSpaces(str);
    
    char** monomials = getMonomials(str);
    int count = getCount(monomials);

    number->degree = getMaxPower(monomials);
    number->coefficient = malloc((number->degree + 1) * sizeof(longNumberQ*));

    int i, j = 0;

    for(i = number->degree; i >= 0; --i) {
        if(j < count && getPower(monomials[j]) == i) {
            puts(monomials[j]);
            printf("%d\n", getPower(monomials[j]));
            number->coefficient[i] = parseNumberQ(getCoef(monomials[j]));
            j++;
        } else {
            number->coefficient[i] = parseNumberQ("0");
        }
        puts(toStringQ(number->coefficient[i]));
    }

    return number;
}

char* toStringP(longNumberP *number) {
    char* str = malloc(2048 * sizeof(char));
    char buf[1024];

    strcpy(str, "");

    int i;

    for(i = number->degree; i >= 0; --i) {
        if(!isZero(transZtoN(number->coefficient[i]->numerator))) {
            if(getSign(number->coefficient[i]->numerator) == PLUS) {
                if(i != number->degree) {
                    strcat(str, " + ");
                }
            }

            char* numerator = toStringZ(number->coefficient[i]->numerator);
            char* denominator = toStringN(number->coefficient[i]->denominator);

            if(i == 0 || (strcmp(numerator, "1") == 0 ^ strcmp(denominator, "1") == 0)) {
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
    int power = 1, count = 0;

    words = malloc(sizeof(char*));

    for(word = strtok(str, "+-"); word; word = strtok(NULL, "+-")) {
        if(count == power) {
            words = realloc(words, (power *= 2) * sizeof(char*));
        }

        words[count++] = word;
    }

    words = realloc(words, count * sizeof(char*));
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
    char* res;

    if(str[0] == 'x') {
        res = "1";
    } else {
        res = strtok(s, "x");
    }

    return res;
}

int getPower(char* str) {
    char* s = copy(str);
    char* res = strtok(s, "^");

    if(strlen(res) == strlen(str)) {
        char* t = copy(str);
        res = strtok(t, "x");

        if(strlen(t) == strlen(str)) {
            res = "0";
        } else {
            res = "1";
        }
    } else {
        res = strtok(NULL, "^");
    }

    return atoi(res);
}

int getMaxPower(char** str) {
    int i, mx, p;

    if(str[0] != NULL) mx = getPower(str[0]);

    for(i = 0; str[i] != NULL; ++i) {
        p = getPower(str[i]);
        if(p > mx) mx = p;
    }

    return mx;
}

void removeSpaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}