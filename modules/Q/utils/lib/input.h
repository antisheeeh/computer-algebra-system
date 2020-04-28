#pragma once

#include "../../lib/number.h"

longNumberQ* parseNumberQ(char* s);
char* toStringQ(longNumberQ* number);
char* copyQ(char* str);
void removeSpacesQ(char* s);
int isValidQ(char* str);