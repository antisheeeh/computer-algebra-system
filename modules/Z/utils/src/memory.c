#include <stdlib.h>

#include "../lib/memory.h"

void clearStringZ(char* str) {
    free(str);
}

void clearStructZ(longNumberZ* number) {
    if (number != NULL){
        free(number->num);        
    }

    free(number);
}