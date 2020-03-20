#include <stdio.h>
#include <string.h>

#include "utils/input.h"
#include "modules/N/lib/number.h"
#include "modules/N/lib/NZER_N_B/NZER_N_B.h"
#include "modules/N/lib/COM_NN_D/COM_NN_D.h"

int main() {
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    str[strlen(str) - 1] = '\0';

    longNumber a = parseNumber(str);
    fgets(str, MAXLEN, stdin);
    str[strlen(str) - 1] = '\0';
    longNumber b = parseNumber(str);

    printf("%d" , compare(a , b));
    
    return 0;
}