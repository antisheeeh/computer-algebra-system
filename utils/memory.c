#include <stdlib.h>
#include "memory.h"

void clearString(char* str) {
    free(str);
}

void clearStruct(longNumber *number) {    
    if (number != NULL){
        free(number->num);        
    }

    free(number);
}
