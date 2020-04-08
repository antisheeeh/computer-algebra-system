#pragma once

#include "../../lib/number.h"

#define BLOCK 128

void assign(longNumberN* to, longNumberN* from);
void removeLeadingZerosN(longNumberN* number);
char* getStringN();
longNumberN* parseNumberN(char* str);
char* toStringN(longNumberN *num);