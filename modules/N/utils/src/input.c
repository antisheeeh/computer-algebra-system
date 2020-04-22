#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/input.h"

#define BLOCK 128

void removeLeadingZerosN(longNumberN* number) {
    while(number->len > 1 && number->num[number->len - 1] == 0) number->len--;
    number->num = realloc(number->num, number->len * sizeof(int));
}

longNumberN* parseNumberN(char* s) {
    longNumberN* number = malloc(sizeof(longNumberN));

    char* str = copy(s);

    int i, len = strlen(str);
    char buf[BLOCK_SIZE + 1];

    number->len = (len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    number->num = calloc(number->len, sizeof(int));

    if(number->num == NULL) return NULL;

    for(i = len; i > 0; i -= BLOCK_SIZE) {
        str[i] = 0;
        number->num[number->len - (i + BLOCK_SIZE - 1) / BLOCK_SIZE] = atoi(i < 9 ? str : str + i - BLOCK_SIZE);
    }

    removeLeadingZerosN(number);

    return number;
}

char* getStringN() {
    int symb, len = 0;
    char* str = NULL;

    str = malloc(BLOCK * sizeof(char));

    for(len = 0; (symb = getchar()) != '\n'; ++len) {
        if(len > 0 && len % BLOCK == 0) {
            str = realloc(str, (len + BLOCK) * sizeof(char));
        }

        str[len] = symb;
    }

    str = realloc(str, (len + 1) * sizeof(char));
    str[len] = '\0';

    return str;
}

char* toStringN(longNumberN* number) {
    char* str = malloc((number->len * BLOCK_SIZE + 1) * sizeof(char));

    int i, len = 0;

    len += sprintf(str, "%d", number->num[number->len - 1]);

    for(i = number->len - 2; i >= 0; --i) {
        len += sprintf(str + len, "%09d", number->num[i]);
    }

    if(len != number->len * BLOCK_SIZE) str = realloc(str, (len + 1) * sizeof(char));

    return str;
}

char* copy(char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    return res;
}