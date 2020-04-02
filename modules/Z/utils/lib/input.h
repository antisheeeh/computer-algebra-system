#pragma once

#include "../../lib/number.h"
#include "../../lib/TRANS_Z_N.h"
#include "../../../N/lib/NZER_N_B.h"

#define BLOCK 128

void removeTrailingZerosZ(longNumberZ* number);
char* getStringZ();
longNumberZ* parseNumberZ(char* str);
void printNumberZ(longNumberZ* num);
char *toStringZ(longNumberZ *num);