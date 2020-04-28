#include <stdio.h>

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/Z/lib/number.h"

#include "../../modules/N/utils/lib/input.h"
#include "../../modules/N/lib/number.h"

#include "../../modules/Z/lib/ADD_ZZ_Z.h"
#include "../../modules/Z/lib/SUB_ZZ_Z.h"
#include "../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../modules/Z/lib/MOD_ZZ_Z.h"

#include "../lib/Z_FUNC_LIST.h"

//Addition 2 numbers

void menu_ADD_ZZ_Z() {
    puts("Please enter a first number");
    longNumberZ* a = parseNumberZ(getStringZ());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second number");
    longNumberZ* b = parseNumberZ(getStringZ());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("");

    puts("Result");
    puts(toStringZ(sumZ(a, b)));
}


//Subtraction 2 numbers

void menu_SUB_ZZ_Z() {
    puts("Please enter a first number");
    longNumberZ* a = parseNumberZ(getStringZ());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second number");
    longNumberZ* b = parseNumberZ(getStringZ());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("");

    puts("Result");
    puts(toStringZ(subZ(a, b)));
}


//Multiplication 2 numbers

void menu_MUL_ZZ_Z() {
    puts("Please enter a first number");
    longNumberZ* a = parseNumberZ(getStringZ());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second number");
    longNumberZ* b = parseNumberZ(getStringZ());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("");

    puts("Result");
    puts(toStringZ(multiZ(a, b)));
}


//Division 2 numbers

void menu_DIV_ZZ_Z() {
    puts("Please enter a first number");
    longNumberZ* a = parseNumberZ(getStringZ());
    if(!a)  {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second number");
    longNumberZ* b = parseNumberZ(getStringZ());
    if(!b)  {
        puts("\nInvalid input");
        return;
    }

    puts("");

    longNumberZ* res = divZ(a, b);

    if(!res) {
        puts("Error! The second number is zero!");
        return;
    }

    puts("Result");
    puts(toStringZ(res));
}

//Calculate the remainder of division

void menu_MOD_ZZ_Z() {
    puts("Please enter a first number");
    longNumberZ* a = parseNumberZ(getStringZ());
    if(!a) {
        puts("\nInvalid input");
        return;
    }
    
    puts("Please enter a second number");
    longNumberZ* b = parseNumberZ(getStringZ());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("");

    longNumberZ* res = divZ(a, b);

    if(!res) {
        puts("Error! The second number is zero!");
        return;
    }

    puts("Result");
    puts(toStringZ(res));
}