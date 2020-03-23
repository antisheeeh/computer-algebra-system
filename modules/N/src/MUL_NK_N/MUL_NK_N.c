/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/MUL_NK_N/MUL_NK_N.h"

char *multiplyBy10k(char *a ,int k)
{
    int i;
    int len = strlen(a);
    char *res = NULL;
    if(k == 0) return a; // if k = 1
    if((res = malloc((len + k + 1)*sizeof(char)))!=NULL){
        strncpy(res , a, len);
        for(i = len; i < len + k; i++){
            res[i] = '0';
        }
        res[i] = '\0';
    } else {
        return NULL;
    }  

    return res;
}