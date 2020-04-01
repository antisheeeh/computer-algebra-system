/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include "../../lib/MUL_NK_N/MUL_NK_N.h"
#include "../../../../utils/lib/input.h"
#include "../../../../utils/lib/memory.h"

#include <stdlib.h>
#include <string.h>

longNumber* multiplyBy10k(longNumber* number, int k) {
    char* str = toString(number);
    int len = strlen(str);
    char* temp = malloc((len + k + 1) * sizeof(char));

    if(temp == NULL) {
        clearString(str);
        return NULL;
    }

    strcpy(temp, str);
    for(int i = 0; i < k; ++i) temp[i + len] = '0';
    temp[len + k] = '\0';

    longNumber* res = parseNumber(temp);

    clearString(str);
    clearString(temp);

    return res;
}