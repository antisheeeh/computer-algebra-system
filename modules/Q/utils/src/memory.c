#include <stdlib.h>
#include "../lib/memory.h"

void clearStringQ(char *string)
{
    free(string);
}

void clearStructQ(longNumberQ *number){
    if(number->numerator != NULL) free(number->numerator);
    if(number->denominator != NULL) free(number->denominator);
    if(number != NULL) free(number);
}