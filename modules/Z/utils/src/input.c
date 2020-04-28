#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../lib/TRANS_Z_N.h"
#include "../../../N/lib/NZER_N_B.h"
#include "../../../N/utils/lib/input.h"

#include "../lib/input.h"

void removeLeadingZerosZ(longNumberZ* number) {
    while(number->len > 1 && number->num[number->len - 1] == 0) number->len--;
    number->num = realloc(number->num, number->len * sizeof(int));
}

longNumberZ* parseNumberZ(char* s) {
    char* str = copyZ(s);
    
    removeSpacesZ(str);

    if(!isValidZ(str)) return NULL;

    longNumberZ* number = malloc(sizeof(longNumberZ));

    if(number == NULL) return NULL;

    int i, len = strlen(str);
    char buf[BLOCK_SIZE + 1], *ptr = str + len;

    if(str[0] == '-') {
        --len;
        number->sign = MINUS;
    } else {
        number->sign = PLUS;
    }

    number->len = (len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    number->num = calloc(number->len, sizeof(int));

    if(number->num == NULL) return NULL;

    for(i = len; i > 0; i -= BLOCK_SIZE) {
        if(i < BLOCK_SIZE){
            strncpy(buf, ptr -= i , i);
            buf[i] = '\0';
            number->num[number->len - 1] = atoi(buf);
        } else {
            strncpy(buf, ptr -= BLOCK_SIZE, BLOCK_SIZE);
            buf[BLOCK_SIZE] = '\0'; 
            number->num[number->len - (i + BLOCK_SIZE - 1) / BLOCK_SIZE] = atoi(buf);
        }
    }

    removeLeadingZerosZ(number);

    if(isZeroN(transZtoN(number))) {
        number->sign = NEUTRAL;
    }
    
    return number;
}

char* getStringZ() {
    int c, len;
    char* str = NULL;    

    for(len = 0; (c = getchar()) != '\n'; ++len) {
        if(len % BLOCK == 0) {
            str = realloc(str, sizeof(char) * (len + BLOCK));
        }

        if(str == NULL) {
            return NULL;
        } else {
            str[len] = c;
        }
    }

    str = realloc(str, sizeof(char) * (len + 1));
    str[len] = '\0';

    return str;
}

char* toStringZ(longNumberZ* number) {
    char* str = malloc(sizeof(char) * (number->len * BLOCK_SIZE + 2));

    if(str == NULL) return NULL;

    int i, num, pow, len = 0;

    if(number->sign == MINUS) {
        str[len++] = '-';
    }

    for(i = number->len - 1; i >= 0; --i) {
        num = number->num[i];

        if(i == number->len - 1)  {
            for(pow = 1; num /= 10; pow *= 10);
        } else {
            pow = BASE / 10;
        }
        
        do str[len++] = number->num[i] / pow % 10 + '0'; while(pow /= 10);
    }

    str[len] = '\0';

    if(len != number->len * BLOCK_SIZE + 1) str = realloc(str, sizeof(char) * (len + 1));

    return str;
}

char* copyZ(char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    return res;
}

void removeSpacesZ(char* s) {
    const char* d = s;

    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int isValidZ(char* str) {
    if(!str) return 0;

    if(*str == '\0') return 0;

    char* t = copyZ(str);
    if(*t == '-' && '0' <= *(t + 1) && *(t + 1) <= '9') t++;

    return isValidN(t);
}