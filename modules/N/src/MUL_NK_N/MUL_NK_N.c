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
    char *res = NULL;

    if((res = malloc((strlen(a) + k + 1)*sizeof(char)))!=NULL){
        strncpy(res , a, strlen(a));
        for(i = strlen(a); i < strlen(a) + k; i++){
            res[i] = '0';
        }
        res[i] = '\0';
    } else {
        return NULL;
    }  

    return res;
}