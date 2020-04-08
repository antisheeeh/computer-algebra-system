#include <stdlib.h>
#include "../lib/memory.h"

void clearStringP(char *string)
{
    free(string);
}

void clearStructP(longNumberP *number){
    if(number->degree != NULL) free(number->degree);
    if(number->coefficient != NULL) free(number->coefficient);
    if(number != NULL) free(number);
}