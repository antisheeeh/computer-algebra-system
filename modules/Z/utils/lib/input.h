#pragma once

#include "../../lib/number.h"

#define BLOCK 128

void removeTrailingZerosZ(longNumberZ* number);
char* getStringZ();
longNumberZ* parseNumberZ(char* str);
void printNumberZ(longNumberZ* num);
char *toStringZ(longNumberZ *num);