#include <stdio.h>
#include <string.h>

#include "utils/input.h"
#include "modules/N/lib/number.h"
#include "modules/N/lib/NZER_N_B/NZER_N_B.h"
#include "modules/N/lib/COM_NN_D/COM_NN_D.h"
#include "modules/N/lib/ADD_NN_N/ADD_NN_N.h"
#include "modules/N/lib/SUB_NN_N/SUB_NN_N.h"

int main() {
    
    char* str = getString();
    //longNumber* a = parseNumber(str);
    //longNumber* b = parseNumber(getString());

    puts(str);

    //free(str);
    //free(a->num);
    return 0;
}