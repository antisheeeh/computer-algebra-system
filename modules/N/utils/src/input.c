#include <string.h>
#include <stdio.h>

#include "../lib/memory.h"

#include "../lib/input.h"

void removeLeadingZerosN(longNumberN* number) {
    while(number->len > 1 && number->num[number->len - 1] == 0) number->len--;
    number->num = realloc(number->num, number->len * sizeof(int));
}

longNumberN* parseNumberN(char* str) {
    longNumberN* number = malloc(sizeof(longNumberN));
    if(number == NULL) return NULL;

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

void assign(longNumberN* to, longNumberN* from) {
    to->len = from->len;
    to = realloc(to, to->len * sizeof(longNumberN));

    int i;
    for(i = 0; i < to->len; ++i) {
        to->num[i] = from->num[i];
    }
}

char* getStringN() {
    int symb, len = 0;
    char* str = NULL;

    str = malloc(BLOCK * sizeof(char));
    if(str == NULL) return NULL;

    for(len = 0; (symb = getchar()) != '\n'; ++len) {
        if(len > 0 && len % BLOCK == 0) {
            str = realloc(str, (len + BLOCK) * sizeof(char));
            if(str == NULL) return NULL;
        }

        str[len] = symb;
    }

    str = realloc(str, (len + 1) * sizeof(char));
    str[len] = '\0';

    return str;
}

char* toStringN(longNumberN* number) {
    char* str = malloc((number->len * BLOCK_SIZE + 1) * sizeof(char));
    if(str == NULL) return NULL;

    int i, len = 0;

    len += sprintf(str, "%d", number->num[number->len - 1]);

    for(i = number->len - 2; i >= 0; --i) {
        len += sprintf(str + len, "%09d", number->num[i]);
    }

    if(len != number->len * BLOCK_SIZE) str = realloc(str, (len + 1) * sizeof(char));

    return str;
}