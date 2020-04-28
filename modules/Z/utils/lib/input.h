#pragma once

#include "../../lib/number.h"

#define BLOCK 128

void removeTrailingZerosZ(longNumberZ* number);
char* getStringZ();
longNumberZ* parseNumberZ(char* s);
void printNumberZ(longNumberZ* num);
char *toStringZ(longNumberZ *num);
char* copyZ(char* str);
void removeSpacesZ(char* s);
int isValidZ(char* str);