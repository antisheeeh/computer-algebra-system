#pragma once

#define MAXLENGTH 100
#define BLOCK_SIZE 9
#define BASE 1000000000
#define PLUS 0
#define MINUS 1

typedef struct {
    int* num;
    int len;
    int sign;
} longNumberZ;