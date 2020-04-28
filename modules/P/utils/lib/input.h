#pragma once

#include "../../lib/number.h"

longNumberP* parseNumberP(char* s);
char* toStringP(longNumberP *number);
int isValidP(char* str);
char** getMonomials(char* str);
int getCount(char** monomials);
char* getCoef(char* str);
char* getPower(char* str);
int getMaxPower(char** str);
void removeSpacesP(char* s);
char* copyP(char* str);
void removeLeadingZerosP(longNumberP *number);