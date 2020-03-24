#include <stdio.h>
#include <string.h>

#include "utils/input.h"
#include "utils/memory.h"
#include "modules/N/lib/number.h"
#include "modules/N/lib/NZER_N_B/NZER_N_B.h"
#include "modules/N/lib/COM_NN_D/COM_NN_D.h"
#include "modules/N/lib/ADD_NN_N/ADD_NN_N.h"
#include "modules/N/lib/SUB_NN_N/SUB_NN_N.h"
#include "modules/N/lib/MUL_ND_N/MUL_ND_N.h"
#include "modules/N/lib/MUL_NK_N/MUL_NK_N.h"
#include "modules/N/lib/MUL_NN_N/MUL_NN_N.h"

int main() {
    
    char* str = getString();
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printNumber(multiByDigit(a, b));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);
   
    return 0;
}