#include <stdio.h>
#include <string.h>

#include "utils/input.h"
#include "modules/N/lib/number.h"

int main() {
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    str[strlen(str) - 1] = '\0';

    longNumber a = parseNumber(str);
    
    return 0;
}