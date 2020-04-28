#include <stdio.h>

#include "../../modules/N/utils/lib/input.h"
#include "../../modules/N/lib/number.h"

#include "../../modules/N/lib/COM_NN_D.h"
#include "../../modules/N/lib/ADD_1N_N.h"
#include "../../modules/N/lib/ADD_NN_N.h"
#include "../../modules/N/lib/SUB_NN_N.h"
#include "../../modules/N/lib/MUL_NN_N.h"
#include "../../modules/N/lib/DIV_NN_N.h"
#include "../../modules/N/lib/MOD_NN_N.h"
#include "../../modules/N/lib/GCF_NN_N.h"
#include "../../modules/N/lib/LCM_NN_N.h"

#include "../lib/N_FUNC_LIST.h"

//Compare 2 numbers

void menu_COM_NN() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;
    
    int res = compN(a, b);

    puts("");
    
    if(res == GREATER) puts("The first number is greater than the second");
    else if(res == LESS) puts("The first number is less than the second");
    else if(res == EQUAL) puts("The first number is equal to the second");
}

//Addition 1 to number

void menu_ADD_1N_N() {
    puts("Please enter a number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("");

    puts("Result");

    puts(toStringN(incN(a)));
}

//Addition 2 numbers

void menu_ADD_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");

    puts("Result");
    puts(toStringN(sumN(a, b)));
}

//Subtraction 2 numbers

void menu_SUB_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");
    if(subN(a,b) != NULL){
        puts("Result");
        puts(toStringN(subN(a, b)));
    } else puts("Error! The second number is bigger than the first one!");
}

//Multiplication 2 numbers

void menu_MUL_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");

    puts("Result");
    puts(toStringN(multiN(a, b)));
}

//Division of 2 numbers

void menu_DIV_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");
    
    if(divN(a, b) != NULL){
        puts("Result");
        puts(toStringN(divN(a, b)));
    } else puts("Error! The second number is zero!");
}

void menu_MOD_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");
    
    if(modN(a, b) != NULL){
        puts("Result");
        puts(toStringN(modN(a, b)));
    } else puts("Error! The second number is zero!");
}

//GCF of 2 numbers

void menu_GCF_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");
    puts("Result");

    puts(toStringN(gcfN(a, b)));
}

//LCM of 2 numbers

void menu_LCM_NN_N() {
    puts("Please enter a first number");
    longNumberN* a = parseNumberN(getStringN());
    if(!a) return;

    puts("Please enter a second number");
    longNumberN* b = parseNumberN(getStringN());
    if(!b) return;

    puts("");
    puts("Result");

    puts(toStringN(lcmN(a, b)));
}