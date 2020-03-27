#pragma once

/* Structure for long number
first field - array of ninth of digits
second field - amount of ninths in number
*/

#define MAXLENGTH 100
#define BLOCK_SIZE 9
#define BASE 1000000000

typedef struct {
    int* num;
    int len;
} longNumber;