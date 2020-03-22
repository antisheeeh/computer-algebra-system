#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "input.h"

longNumber* parseNumber(char* str) {
    while(*str == '0') ++str;
    if(*str == '\0') *str-- = '0';

    longNumber* number = malloc(sizeof(longNumber));

    if(number == NULL) return NULL;

    int i, len = strlen(str);
    char buf[BLOCK_SIZE + 1], *ptr = str + len;


    number->len = (len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    number->num = malloc(sizeof(int) * number->len);

    if(number->num == NULL) return NULL;

    for(i = len; i > 0; i -= BLOCK_SIZE) {
        if(i < BLOCK_SIZE){
            strncpy(buf, ptr -= i , i);
            buf[i] = '\0';
            number->num[number->len-1] = atoi(buf);
        } else {
            strncpy(buf, ptr -= BLOCK_SIZE, BLOCK_SIZE);
            buf[BLOCK_SIZE] = '\0'; 
            number->num[number->len - (i + BLOCK_SIZE - 1) / BLOCK_SIZE] = atoi(buf);
        }
    }
    return number;
}

char* getString() {
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

void printNumber(longNumber* num) {
    int i;

    printf("%d", num->num[num->len - 1]);

    if(num->len > 1) {
        for(i = num->len - 2; i >= 0; --i) {
            printf("%09d", num->num[i]);
        }
    }
}