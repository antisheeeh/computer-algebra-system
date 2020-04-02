/* 
    Author: Epifantsev Egor
    Group: 9305
*/

#include <stdlib.h>
#include <string.h>

#include "../utils/lib/input.h"
#include "../utils/lib/memory.h"

#include "../lib/MUL_NK_N.h"

longNumberN* multiplyBy10k(longNumberN* number, int k) {
    char* str = toStringN(number);
    int len = strlen(str);
    char* temp = malloc((len + k + 1) * sizeof(char));

    if(temp == NULL) {
        clearStringN(str);
        return NULL;
    }

    strcpy(temp, str);
    for(int i = 0; i < k; ++i) temp[i + len] = '0';
    temp[len + k] = '\0';

    longNumberN* res = parseNumberN(temp);

    clearStringN(str);
    clearStringN(temp);

    return res;
}