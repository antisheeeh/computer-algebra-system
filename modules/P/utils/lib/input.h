#pragma once

#include "../../lib/number.h"

longNumberP* parseNumberP(char* str);
char* toStringP(longNumberP *number);
char** getMonomials(char* str);
int getCount(char** monomials);
char* getCoef(char* str);
int getPower(char* str);
int getMaxPower(char** str);
void removeSpaces(char* s);