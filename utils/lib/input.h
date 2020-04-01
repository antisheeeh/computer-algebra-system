#pragma once

#include "../../modules/N/lib/number.h"

#define BLOCK 128

void removeTrailingZeros(longNumberN* number);
char* getString();
longNumberN* parseNumber(char* str);
void printNumber(longNumberN* num);
char *toString(longNumberN *num);