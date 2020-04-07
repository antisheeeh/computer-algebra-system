#include <stdlib.h>

#include "../lib/memory.h"

void clearStringN(char* string) {
    free(string);
}

void clearStructN(longNumberN *number) {    
    if (number != NULL){
        free(number->num);        
    }

    free(number);
}
