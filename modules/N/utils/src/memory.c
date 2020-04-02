#include <stdlib.h>

#include "../lib/memory.h"

void clearStringN(char* str) {
    free(str);
}

void clearStructN(longNumberN *number) {    
    if (number != NULL){
        free(number->num);        
    }

    free(number);
}
