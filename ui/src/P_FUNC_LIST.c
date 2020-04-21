#include <stdio.h>

#include "../lib/menu.h"

#include "../../modules/P/utils/lib/input.h"
#include "../../modules/N/utils/lib/input.h"
#include "../../modules/Q/utils/lib/input.h"
#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/P/lib/number.h"

#include "../../modules/P/utils/lib/memory.h"

#include "../../modules/P/lib/ADD_PP_P.h"
#include "../../modules/P/lib/DEG_P_N.h"
#include "../../modules/P/lib/SUB_PP_P.h"
#include "../../modules/P/lib/MUL_PQ_P.h"
#include "../../modules/P/lib/LED_PQ_Q.h"
#include "../../modules/P/lib/MUL_PXK_P.h"
#include "../../modules/P/lib/FAC_P_Q.h"
#include "../../modules/P/lib/MUL_PP_P.h"
#include "../../modules/P/lib/DER_P_P.h"

#include "../../modules/N/utils/lib/input.h"


//Addition 2 polinomials

void menu_ADD_PP_P() {
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());
    
    puts("Result");
    puts(toStringP(sumP(a, b)));
}

//Subtraction 2 polinomials

void menu_SUB_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());

    puts("Result");
    puts(toStringP(subP(a, b)));
}
//Multiply polinomial by rational number

void menu_MUL_PQ_P(){
    puts("Please enter a polynomial");
    longNumberP *a = parseNumberP(getStringN());

    puts("Please enter a rational");
    longNumberQ *rat = parseNumberQ(getStringN());

    puts("Result");
    puts(toStringP(multyByRational(a, rat)));
}

//Multiply polinomial by x^k

void menu_MUL_Pxk_P(){
    puts("Please enter a polynomial");
    longNumberP *a = parseNumberP(getStringN());

    int pow;
    puts("Please enter k");
    scanf("%d" , &pow);
    getchar();

    puts("Result");
    puts(toStringP(multyByXk(a, pow)));
}

//Leading coefficient of polynomial

void menu_LED_L_Q(){
    puts("Please enter a polynomial");
    longNumberP *a = parseNumberP(getStringN());
    
    puts("Result");
    puts(toStringQ(led(a)));
}

//Highest degree of the polynomial

void menu_DEG_P_N(){
    puts("Please enter a polynomial");
    longNumberP *a = parseNumberP(getStringN());
    
    puts("Result");
    printf("%d\n", deg(a));
}

//The derivation of a coefficient from a polynomial

void menu_FAC_P_Q(){
    puts("Please enter a polynomial");
    longNumberP *a = parseNumberP(getStringN());

    longNumberN *gcf;
    longNumberN *lcm;

    facP(a,&gcf,&lcm);

    puts(toStringN(gcf));
    puts(toStringN(lcm));
}

//Multiplication 2 polinomials

void menu_MUL_PP_P(){
    puts("Please enter a first polynomial");
    longNumberP* a = parseNumberP(getStringN());

    puts("Please enter a second polynomial");
    longNumberP* b = parseNumberP(getStringN());

    puts("Result");
    puts(toStringP(mulP(a, b)));
}

//Division 2 polinomials
/*
void menu_DIV_PP_P(){

}
*/
//Calculate the remainder of division 2 polinomials
/*
void menu_MOD_PP_P(){

}
*/
//GCF of 2 polinomials
/*
void menu_GCF_PP_P(){

}
*/
//Derivative of polinomial
/*
void menu_DER_P_P(){
    longNumberP *a = getNumberP(); 

    printNumberP(derP(a));
}

//Multiple roots in simple
/*
void menu_NMR_P_P(){

}
*/