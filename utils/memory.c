#include <stdlib.h>
#include "memory.h"

void clearString(char* str) {
    free(str);
}

void clearStruct(longNumber *number)
{
    free(number->num);
    free(number);
}
