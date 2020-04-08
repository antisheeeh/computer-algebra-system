#pragma once

#include "../../lib/number.h"

#define BLOCK 128

int power(int a, int b);
void assign(longNumberN* to, longNumberN* from);
longNumberN* digitToNumberN(int digit);
void removeLeadingZerosN(longNumberN* number);
char* getStringN();
longNumberN* parseNumberN(char* str);
char* toStringN(longNumberN *num);
longNumberN* cutN(longNumberN* a, longNumberN* b);
longNumberN* addDigit(longNumberN* number, int digit);
void swapN(longNumberN* to, longNumberN* from);