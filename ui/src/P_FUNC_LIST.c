#include <stdio.h>
#include <stdlib.h>

#include "../lib/menu.h"

#include "../../modules/P/utils/lib/input.h"
#include "../../modules/N/utils/lib/input.h"
#include "../../modules/Q/utils/lib/input.h"
#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/P/lib/number.h"

#include "../../modules/P/lib/ADD_PP_P.h"
#include "../../modules/P/lib/DEG_P_N.h"
#include "../../modules/P/lib/SUB_PP_P.h"
#include "../../modules/P/lib/MUL_PQ_P.h"
#include "../../modules/P/lib/LED_PQ_Q.h"
#include "../../modules/P/lib/MUL_PXK_P.h"
#include "../../modules/P/lib/FAC_P_Q.h"
#include "../../modules/P/lib/MUL_PP_P.h"
#include "../../modules/P/lib/DER_P_P.h"
#include "../../modules/P/lib/DIV_PP_P.h"
#include "../../modules/P/lib/MOD_PP_P.h"
#include "../../modules/P/lib/GCF_PP_P.h"
#include "../../modules/P/lib/DER_P_P.h"
#include "../../modules/P/lib/NMR_P_P.h"

#include "../../modules/N/utils/lib/input.h"


//Addition 2 polinomials

void menu_ADD_PP_P() {
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }
    
    puts("Result");
    puts(toStringP(sumP(a, b)));
}

//Subtraction 2 polinomials

void menu_SUB_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("Result");
    puts(toStringP(subP(a, b)));
}

//Multiplication 2 polinomials

void menu_MUL_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("Result");
    puts(toStringP(mulP(a, b)));
}

//Division 2 polinomials

void menu_DIV_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    longNumberP* res = divP(a, b);

    if(!res) {
        puts("Error! The second polynom is zero");
        return;
    }

    puts("Result");
    puts(toStringP(res));
}

//Calculate the remainder of division 2 polinomials

void menu_MOD_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    longNumberP* res = modP(a, b);

    if(!res) {
        puts("Error! The second polynom is zero");
        return;
    }

    puts("Result");
    puts(toStringP(res));
}

//GCF of 2 polinomials

void menu_GCF_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    if(!b) {
        puts("\nInvalid input");
        return;
    }

    puts("Result");
    puts(toStringP(gcfP(a, b)));
}

//Derivative of polinomial

void menu_DER_P_P(){
    puts("Please enter a polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Result");
    puts(toStringP(derP(a)));
}

//Multiple roots in simple

void menu_NMR_P_P(){
    puts("Please enter a polynomial");
    longNumberP* a = parseNumberP(getStringN());
    if(!a) {
        puts("\nInvalid input");
        return;
    }

    puts("Result");
    puts(toStringP(multipleRootsToSimple(a)));
}