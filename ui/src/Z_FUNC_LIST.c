#include <stdio.h>

#include "../lib/menu.h"

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/Z/lib/number.h"

#include "../../modules/N/utils/lib/input.h"
#include "../../modules/N/lib/number.h"

#include "../../modules/Z/utils/lib/memory.h"
#include "../../modules/N/utils/lib/memory.h"

#include "../../modules/Z/lib/ABS_Z_N.h"
#include "../../modules/Z/lib/POZ_Z_D.h"
#include "../../modules/Z/lib/MUL_ZM_Z.h"
#include "../../modules/Z/lib/TRANS_N_Z.h"
#include "../../modules/Z/lib/TRANS_Z_N.h"
#include "../../modules/Z/lib/ADD_ZZ_Z.h"
#include "../../modules/Z/lib/SUB_ZZ_Z.h"
#include "../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../modules/Z/lib/MOD_ZZ_Z.h"

#include "../lib/Z_FUNC_LIST.h"

//Absolute number

void menu_ABS_Z_N() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    
    puts("Result");
    char* res = toStringZ(absolute(a));
    puts(res);

    clearStringZ(str);
    clearStringZ(res);
    clearStructZ(a);

    show_help();
}

void menu_POZ_Z_D() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);

    int res = getSign(a);
    
    if(res == MINUS) {
        puts("The number is negative");
    } else if(res == PLUS) {
        puts("The number is positive");
    } else if(res == NEUTRAL) {
        puts("The number is zero");
    }

    clearStringZ(str);
    clearStructZ(a);

    show_help();
}

//Change sign of number

void menu_MUL_ZM_Z() {
    puts("Please enter a number");

    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    
    changeSign(a);
    
    puts("Result");
    char* res = toStringZ(a);
    puts(res);

    clearStringZ(str);
    clearStringZ(res);
    clearStructZ(a);

    show_help();
}

//Translate natural to integer

void menu_TRANS_N_Z() {
    puts("Please enter a number");

    char* str = getStringN();
    longNumberN* a = parseNumberN(str);
    longNumberZ* b = transNtoZ(a);
    
    puts("Result");
    char* res = toStringZ(b);
    puts(res);

    clearStringZ(str);
    clearStringZ(res);
    clearStructN(a);
    clearStructZ(b);

    show_help();
}


//Translate integer to natural

void menu_TRANS_Z_N() {
    puts("Please enter a number");

    char* str = getStringZ();

    longNumberZ* a = parseNumberZ(str);
    longNumberN* b = transZtoN(a);
    
    puts("Result");
    char* res = toStringN(b);
    puts(res);

    clearStringZ(str);
    clearStringZ(res);
    clearStructZ(a);
    clearStructN(b);

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
    char* res = toStringZ(c);
    puts(res);

    clearStringZ(str1);
    clearStringZ(str2);
    clearStringZ(res);
    clearStructZ(a);
    clearStructZ(b);
    clearStructZ(c);


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
    char* res = toStringZ(c);
    puts(res);

    clearStringZ(str1);
    clearStringZ(str2);
    clearStringZ(res);
    clearStructZ(a);
    clearStructZ(b);
    clearStructZ(c);

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

    longNumberZ* c = multiZ(a, b);
    char* res = toStringZ(c);
    puts(res);

    clearStringZ(str1);
    clearStringZ(str2);
    clearStringZ(res);
    clearStructZ(a);
    clearStructZ(b);
    clearStructZ(c);

    show_help();
}


//Division 2 numbers

void menu_DIV_ZZ_Z() {
    puts("Please enter a first number");
    char* str1 = getStringZ();
    longNumberZ* a = parseNumberZ(str1);

    puts("Please enter a second number");
    char* str2 = getStringZ();
    longNumberZ* b = parseNumberZ(str2);

    puts("");

    puts("Result");

    longNumberZ* c = divZ(a, b);
    char* res = toStringZ(c);
    puts(res);

    clearStringZ(str1);
    clearStringZ(str2);
    clearStringZ(res);
    clearStructZ(a);
    clearStructZ(b);
    clearStructZ(c);

    show_help();
}

//Calculate the remainder of division

void menu_MOD_ZZ_Z() {
    puts("Please enter a first number");
    char* str1 = getStringZ();
    longNumberZ* a = parseNumberZ(str1);

    puts("Please enter a second number");
    char* str2 = getStringZ();
    longNumberZ* b = parseNumberZ(str2);

    puts("");

    puts("Result");

    longNumberZ* c = modZ(a, b);
    char* res = toStringZ(c);
    puts(res);

    clearStringZ(str1);
    clearStringZ(str2);
    clearStringZ(res);
    clearStructZ(a);
    clearStructZ(b);
    clearStructZ(c);

    show_help();
}