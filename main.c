#include <stdio.h>
#include <string.h>

#include "utils/input.h"
#include "modules/N/lib/number.h"
#include "modules/N/lib/NZER_N_B/NZER_N_B.h"
#include "modules/N/lib/COM_NN_D/COM_NN_D.h"
#include "modules/N/lib/ADD_NN_N/ADD_NN_N.h"
#include "modules/N/lib/SUB_NN_N/SUB_NN_N.h"

int main() {
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    str[strlen(str) - 1] = '\0';

    longNumber a = parseNumber(str);
    fgets(str, MAXLEN, stdin);
    str[strlen(str) - 1] = '\0';
    longNumber b = parseNumber(str);

    printNumber(sub(a, b));
    
    return 0;
}