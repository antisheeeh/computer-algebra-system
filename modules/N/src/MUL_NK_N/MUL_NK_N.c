/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../../../utils/input.h"

longNumber* multiplyBy10k(longNumber* a ,int k)
{
    int i;
    char* str = toString(a);
    int len = strlen(str);
    char *res = NULL;
    if(k == 0) return parseNumber(str); // if k = 1
    if((res = malloc((len + k + 1)*sizeof(char)))!=NULL){
        strncpy(res , str, len);
        for(i = len; i < len + k; i++){
            res[i] = '0';
        }
        res[i] = '\0';
    } else {
        return NULL;
    }  

    return parseNumber(res);
}