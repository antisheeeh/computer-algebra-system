#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/input.h"
#include "../../../Z/lib/TRANS_Z_N.h"
#include "../../../N/lib/NZER_N_B.h"
#include "../../../Z/utils/lib/input.h"
#include "../../../N/utils/lib/input.h"
#include "../../../Q/utils/lib/input.h"
#include "../../../Q/lib/INT_Q_B.h"
#include "../../../Q/lib/TRANS_Q_Z.h"

longNumberP* parseNumberP(char* str) {
    longNumberP* number = malloc(sizeof(longNumberP));

    char** monomials = getMonomials(str);
    int count = getCount(monomials);

    number->degree = getMaxPower(monomials);
    number->coefficient = malloc((number->degree + 1) * sizeof(longNumberQ*));

    int i;

    for(i = number->degree; i >= 0; --i) {
        if(getPower(monomials[count - 1]) == i) {
            number->coefficient[i] = parseNumberQ(getCoef(monomials[count - 1]));
            count--;
        } else {
            number->coefficient[i] = parseNumberQ("0/1");
        }
    }

    return number;
}

char* toStringP(longNumberP *number) {
    char* str = malloc(2048 * sizeof(char));
    char buf[1024];

    int i;

    for(i = number->degree; i >= 0; --i) {
        if(!isZero(transZtoN(number->coefficient[i]->numerator))) {
            if(number->coefficient[i]->numerator->sign == PLUS) {
                strcat(str, "+");
            }

            strcat(str, toStringQ(number->coefficient[i]));

            if(i == 1) {
                strcat(str, "x");
            } else if(i == 0) {
                sprintf(buf, "%d", i);
                strcat(str, buf);
            } else {
                strcat(str, "x^");
                sprintf(buf, "%d", i);
                strcat(str, buf);
            }
        }
    }

    str = realloc(str, (strlen(str) + 1) * sizeof(char));
    
    return str;
}

char** getMonomials(char* str) {
    char** words;
    char* word;
    int power = 1, count = 0;

    words = malloc(sizeof(char*));

    for(word = strtok(str, "+"); word; word = strtok(NULL, "+")) {
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
    char* res = strtok(s, "x");
    if(res) return res;
    else return s;
}

int getPower(char* str) {
    char* s = copy(str);
    char* res = strtok(s, "^");

    if(!res) {
        res = strtok(s, "x");
        if(res) res = "1";
        else res = "0";
    } else {
        res = strtok(NULL, "^");
    }

    return atoi(res);
}

int getMaxPower(char** str) {
    int i, mx, p;

    if(str[0]) mx = getPower(str[0]);

    for(i = 0; str[i]; ++i) {
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