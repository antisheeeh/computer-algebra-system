#pragma once

#include "../modules/N/lib/number.h"

#define BLOCK 128

void removeTrailingZeros(char* str);
char* getString();
longNumber* parseNumber(char* str);
void printNumber(longNumber* num);