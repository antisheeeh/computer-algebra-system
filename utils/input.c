#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void removeTrailingZeros(longNumber* number) {
    while(number->num[number->len - 1] == 0) number->len--;
    if(number->len == 0) number->len = 1;
    number->num = realloc(number->num, sizeof(int) * number->len);
}

longNumber* parseNumber(char* str) {
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

    removeTrailingZeros(number);
    
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

/*char *toString(longNumber *a)
{
    int i,j=0,k;
    char *res = NULL;
    char buf[BLOCK_SIZE+1];

    res = malloc((a->len * BLOCK_SIZE)*sizeof(char));
    for(i = a->len - 1; i >= 0; i--){
        sprintf(buf,"%d" ,a->num[i]);
        if(buf[0] == '0'){
            strcpy(buf,"000000000");
        }
        strncpy(res,buf,BLOCK_SIZE);
        res= res + strlen(buf);
        j+=strlen(buf);
    }
    res-=j;
    res = realloc(res , (j+1)*sizeof(char));
    res[j] = '\0';
    return res;
}*/

char* toString(longNumber* number) {
    char* str = malloc(sizeof(char) * (number->len * BLOCK_SIZE + 1));

    if(str == NULL) return NULL;

    int i, num, pow, len = 0;

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

    if(len != number->len * BLOCK_SIZE) str = realloc(str, sizeof(char) * (len + 1));

    return str;
}
