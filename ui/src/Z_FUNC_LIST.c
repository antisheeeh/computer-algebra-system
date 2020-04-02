#include <stdio.h>
#include <stdlib.h>

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/N/utils/lib/input.h"

#include "../../modules/Z/lib/number.h"
#include "../../modules/N/lib/number.h"

#include "../lib/menu.h"

#include "../../modules/Z/lib/ABS_Z_N.h"
#include "../../modules/Z/lib/POZ_Z_D.h"
#include "../../modules/Z/lib/MUL_ZM_Z.h"
#include "../../modules/Z/lib/TRANS_N_Z.h"
#include "../../modules/Z/lib/TRANS_Z_N.h"

#include "../../modules/Z/lib/ADD_ZZ_Z.h"
#include "../../modules/Z/lib/SUB_ZZ_Z.h"

#include "../../modules/Z/lib/MUL_ZZ_Z.h"

/*
#include "../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../modules/Z/lib/MOD_ZZ_Z.h"
*/

#include "../lib/Z_FUNC_LIST.h"

//Absolute number

void menu_ABS_Z_N() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    
    puts("Result");
    puts(toStringZ(absolute(a)));

    show_help();
}

void menu_POZ_Z_D() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);

    int res = getSign(a);
    
    if(res == NEGATIVE) {
        puts("The number is negative");
    } else if(res == POSITIVE) {
        puts("The number is positive");
    } else if(res == ZERO) {
        puts("The number is zero");
    }

    show_help();
}

//Change sign of number

void menu_MUL_ZM_Z() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    
    changeSign(a);
    
    puts("Result");
    puts(toStringZ(a));

    show_help();
}

//Translate natural to integer

void menu_TRANS_N_Z() {
    puts("Please enter a number");

    char* str = getString();
    longNumberN* a = parseNumber(str);
    
    longNumberZ* res = transNtoZ(a);
    
    puts("Result");
    puts(toStringZ(res));

    show_help();
}


//Translate integer to natural

void menu_TRANS_Z_N() {
    puts("Please enter a number");

    char* str = getString();
    longNumberZ* a = parseNumberZ(str);
    
    longNumberN* res = transZtoN(a);
    
    puts("Result");
    puts(toString(res));

    show_help();
}


//Addition 2 numbers

void menu_ADD_ZZ_Z() {
    puts("Please enter a first number");
    char* str1 = getStringZ();
    longNumberZ* a = parseNumberZ(str1);

    puts("Please enter a second number");
    char* str2 = getStringZ();
    longNumberZ* b = parseNumberZ(str2);

    puts("");

    puts("Result");

    longNumberZ* c = sumZ(a, b);
    puts(toStringZ(c));

    show_help();
}


//Subtraction 2 numbers

void menu_SUB_ZZ_Z() {
    puts("Please enter a first number");
    char* str1 = getStringZ();
    longNumberZ* a = parseNumberZ(str1);

    puts("Please enter a second number");
    char* str2 = getStringZ();
    longNumberZ* b = parseNumberZ(str2);

    puts("");

    puts("Result");

    longNumberZ* c = subZ(a, b);
    puts(toStringZ(c));

    show_help();
}


//Multiplication 2 numbers

void menu_MUL_ZZ_Z() {
    puts("Please enter a first number");
    char* str1 = getStringZ();
    longNumberZ* a = parseNumberZ(str1);

    puts("Please enter a second number");
    char* str2 = getStringZ();
    longNumberZ* b = parseNumberZ(str2);

    puts("");

    puts("Result");

    longNumberZ* c = multyZ(a, b);
    puts(toStringZ(c));

    show_help();
}

/*

//Division 2 numbers

void menu_DIV_ZZ_Z() {
    
    show_help();
}

//Calculate the remainder of division

void menu_MOD_ZZ_Z() {
    
    show_help();
}
*/