#pragma once

#include "../modules/N/lib/number.h"

#define BLOCK 128

char* getString();
longNumber* parseNumber(char* str);
void printNumber(longNumber* num);

