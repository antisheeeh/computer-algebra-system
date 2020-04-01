#pragma once

#include "../../modules/N/lib/number.h"

#define BLOCK 128

void removeTrailingZeros(longNumber* number);
char* getString();
longNumber* parseNumber(char* str);
void printNumber(longNumber* num);
char *toString(longNumber *num);